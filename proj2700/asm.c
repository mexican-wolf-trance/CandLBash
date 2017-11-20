#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Interpreter by C.Z. Janikow
   Assumption 
     one instruction per line or line is blank ("\n")
     also, optional label:
     instructions are reserved in UPPER
     tokens are separated by WS
     storage directives are 
       name val
     all names are up to 20 characters and must start with a letter, then letters+digits
     execpt for COPY, all BRs and READ - argument can be immediate integer
     all literals are signed integers 
     labels can precede instructions only 
     PUSH/POP allocate/deallocate storage on the stack
     STACKR/STACKW n read/write the nth element counting from TOS
     (assume stack[TOS] is the top element) */

#define NAMESIZ 21
#define DEBUG 0


#define STACKSIZ 1000

struct 
{ int s[STACKSIZ];
  int tos;
} stack={{0},-1};

typedef struct 
{ char name[NAMESIZ];
  int val;
} elem_t;

typedef struct 
{ void (*oper)(int,int);
  int args[2];
} instruct_t;

typedef struct
{ void (*oper)(int,int);
  int numArgs;
  int useImmediate;
} instructInfo_t;


int ACC=0;
unsigned IP=0;
elem_t *Vars;
unsigned NumVars=0;
elem_t *Labels;
unsigned NumLabels=0;
instruct_t *Instructs;
unsigned NumInstructs=0;
unsigned NumNumbers=0;

void error(const char s[])
{ fprintf(stderr,"Error: %s\n",s);
  exit(1);
}

void ADD(int a, int b)
/* ADD(a,_) means add the value from variable at index x into ACC */
{ ACC+=Vars[a].val;
}

void SUB(int a, int b)
{ ACC-=Vars[a].val;
}

void MULT(int a, int b)
{ ACC*=Vars[a].val;
}

void DIV(int a, int b)
{ ACC/=Vars[a].val;
}

void LOAD(int a, int b)
{ ACC=Vars[a].val;
}

void STORE(int a, int b)
{ Vars[a].val=ACC;
}

void COPY(int a, int b)
{ Vars[a].val=Vars[b].val;
}

void READ(int a, int b)
{ printf("Give number: ");
  scanf("%d",&Vars[a].val);
}

void WRITE(int a, int b)
{ printf("Number is: %d\n",Vars[a].val);
}

void STOP(int a, int b)
{ exit(0);
}

void NOOP(int a, int b)
{ return;
}

void BR(int a, int b)
{ IP=Labels[a].val-1; /* -1 to account for subsequent IP++ */
}

void BRNEG(int a, int b)
{ if (ACC<0)
    IP=Labels[a].val-1;
}

void BRZNEG(int a, int b)
{ if (ACC<=0)
    IP=Labels[a].val-1;
}

void BRPOS(int a, int b)
{ if (ACC>0)
    IP=Labels[a].val-1;
}

void BRZPOS(int a, int b)
{ if (ACC>=0)
    IP=Labels[a].val-1;
}

void BRZERO(int a, int b)
{ if (ACC==0)
    IP=Labels[a].val-1;
}

void PUSH(int a, int b)
{ if (stack.tos==STACKSIZ-1)
    error("Stack overflow");
  stack.tos++;
}

void POP(int a, int b)
{ if (stack.tos<0)
    error("Stack underflow");
  stack.tos--;
}

void STACKW(int a, int b)
{ int loc;
  loc=stack.tos-Vars[a].val;
  if (loc<0 || loc>stack.tos)
    error("Stack write error");
  stack.s[loc]=ACC;
}

void STACKR(int a, int b)
{ int loc;
  loc=stack.tos-Vars[a].val;
  if (loc<0 || loc>stack.tos)
    error("Stack read error");
  ACC=stack.s[loc];
}

char *Reserved[]=
  {"ADD","SUB","MULT","DIV","LOAD","STORE",
   "COPY","READ","WRITE","STOP","NOOP","BR","BRNEG","BRZNEG",
   "BRPOS","BRZPOS","BRZERO","PUSH","POP","STACKW","STACKR",""};

instructInfo_t InstructInfo[]={
   {ADD,1,1}, {SUB,1,1}, {MULT,1,1}, {DIV,1,1}, {LOAD,1,1}, {STORE,1,0},
   {COPY,2,0}, {READ,1,0}, {WRITE,1,1}, {STOP,0,0}, {NOOP,0,0}, {BR,1,0}, 
   {BRNEG,1,0},{BRZNEG,1,0},{BRPOS,1,0},{BRZPOS,1,0},{BRZERO,1,0},
   {PUSH,0,0},{POP,0,0},{STACKW,1,1},{STACKR,1,1}};

int inReserved(const char *what)
{ int i;
  if (what==NULL)
    return -1;
  for(i=0;;i++)
  { if (!strcmp(Reserved[i],""))
      return -1; /* not reserved */
    if (!strcmp(what,Reserved[i]))
      return i; /* match */
  }
}

/* nothing(s) returns true if no non-WS in s */
int nothing(const char s[])
{ if (s==NULL)
    return 1;
  while (*s!='\0')
    if (!isspace(*s))
      return 0;
    else
      s++;
  return 1;
}

/* IsNumber(s) is true if s is all digits */
int isNumber(const char *s)
{ if (s==NULL)
    return 0;
  if (*s=='-' || *s=='+')
    if (!isdigit(*(s+1)))
      error("Minus/plus by itself");
    else
      s++;
  while (*s!='\0')
    if (!isdigit(*s))
      return 0;
    else
      s++;
  return 1;
}

  
  
/* pass1() counts variables (+literals), lines, instructions, labels, no syntax check */
void pass1(FILE *fp)
{ char buffer[132];
  char *p=NULL;
  int instruct;
  
  fgets(buffer,132,fp);
  while (!feof(fp))
  { if (nothing(buffer))
    { fgets(buffer,132,fp);
      continue;
    }
    p=strchr(buffer,':'); /* a label here */
    if (p)
    { NumLabels++;
      p++; /* move after label */
    }
    else
      p=buffer;
    p=strtok(p," \t\n");
    if ((instruct=inReserved(p))>=0)
    { NumInstructs++;
      if (InstructInfo[instruct].useImmediate && isNumber(strtok(NULL," \t\n")))
        NumNumbers++;
    }
    else
      NumVars++;
    fgets(buffer,132,fp);
  }
}


/* pass2() writes variables/literals and labels */
void pass2(FILE *fp)
{ char buffer[132];
  char *p=NULL;
  int i, numLabels=0, numVarsNumbers=0, numInstructs=0, instruct;
  char name[NAMESIZ];
  
  fgets(buffer,132,fp);
  while (!feof(fp))
  { if (nothing(buffer))
    { fgets(buffer,132,fp);
      continue;
    }
    p=strchr(buffer,':'); /* a label here */
    if (p!=NULL)
    { sscanf(buffer," %[^:]",name);
      strcpy(Labels[numLabels].name,name);
      Labels[numLabels].val=numInstructs;
      numLabels++;
      p++; /* skip the label now */
    }
    else
      p=buffer;
    p=strtok(p," \t\n");
    if ((instruct=inReserved(p))<0) /* not reserved */
    { strcpy(Vars[numVarsNumbers].name,p);
      for (i=0; i<numVarsNumbers; i++)
        if (!strcmp(Vars[i].name,p))
          error("Multiply defined variable");
      p=strtok(NULL," \t\n");
      if (p==NULL || !isNumber(p))
        error("Variable name must be followed by integer value");
      Vars[numVarsNumbers].val=atoi(p);
      p=strtok(NULL," \t\n");
      if (!nothing(p))
        error("left over on variable definition line");
      numVarsNumbers++;
    }
    else /* instruction */
    { for (i=0; i<InstructInfo[instruct].numArgs; i++)
      { p=strtok(NULL," \t\n"); 
        if (p==NULL || !(InstructInfo[instruct].useImmediate) && isNumber(p))
          error("invalid argument");
        if (isNumber(p))
        { strcpy(Vars[numVarsNumbers].name,p);
          Vars[numVarsNumbers].val=atoi(p);
          numVarsNumbers++;
        }
      }
      numInstructs++;
    }
    fgets(buffer,132,fp);
  }
}

int findInTable(elem_t *table, int numElms, const char name[])
{ int i;
  for (i=0; i<numElms; i++)
    if (!strcmp(name,table[i].name))
      return i;
  return -1; /* not found */
}

/* pass3() initializes Instructs array. All immediate vals and variables are already in Vars */
void pass3(FILE *fp)
{ char buffer[132];
  char *p=NULL;
  int i, numInstructs=0, instruct, label;
  
  fgets(buffer,132,fp);
  while (!feof(fp))
  { if (nothing(buffer))
    { fgets(buffer,132,fp);
      continue;
    }
    p=strchr(buffer,':'); /* a label here */
    if (p!=NULL)
      p++; /* skip the label now */
    else
      p=buffer;
    p=strtok(p," \t\n");
    if ((instruct=inReserved(p))>=0) /* instruction */
    { Instructs[numInstructs].oper=InstructInfo[instruct].oper;
      for (i=0; i<InstructInfo[instruct].numArgs; i++)
      { p=strtok(NULL," \t\n"); 
        if (instruct>=11 && instruct<=16) /* BRs */
        { label=findInTable(Labels,NumLabels,p);
          if (label<0)
            error("BRs must be followed by defined labels");
          Instructs[numInstructs].args[i]=label;
        }
        else
        { label=findInTable(Vars,NumVars+NumNumbers,p);
          if (label<0)
            error("Unknown argument");
          Instructs[numInstructs].args[i]=label;
        }
      }
      numInstructs++;
    }
    fgets(buffer,132,fp);
  }
}


int main(int argc, char *argv[])
{ int i,j,k;
  FILE *fp;

  if (argc==2)
  { fp=fopen(argv[1],"r");
    if (fp==NULL)
    { fprintf(stderr,"Cannot open %s\n",argv[1]);
          exit(1);
    }
  }
  else if (argc==1)
  { char buf[132];
    char *p=tmpnam(NULL);
    fp=fopen(p,"w");
    if (fp==NULL)
    { fprintf(stderr,"Cannot open %s\n",argv[1]);
          exit(1);
    }
    fgets(buf,132,stdin);
    while (!feof(stdin))
    { fputs(buf,fp);
      fgets(buf,132,stdin);
    }
    fclose(fp);
    fp=fopen(p,"r");
    if (fp==NULL)
    { fprintf(stderr,"Cannot open %s\n",argv[1]);
      exit(1);
    }
  }
  else
  { fprintf(stderr,"Invoke as %s [file]\n",argv[0]);
    exit(1);
  }
  
  printf("Welcome to asmb interpreter by C.Z. Janikow, 1999\n\n");
  pass1(fp); /* intialize counters */
  Vars=(elem_t*)calloc(NumVars+NumNumbers,sizeof(elem_t));
  Labels=(elem_t*)calloc(NumLabels,sizeof(elem_t));
  Instructs=(instruct_t*)calloc(NumInstructs,sizeof(instruct_t));
  
  rewind(fp);
#if DEBUG
printf("...debugging...\n");
printf("NumNumbers=%d\n",NumNumbers);
printf("NumVars=%d\n",NumVars);
printf("NumLabels=%d\n",NumLabels);
printf("NumInstructs=%d\n",NumInstructs);
#endif

  pass2(fp); /* set vars and labels */
  rewind(fp);
#if DEBUG
printf("...debugging...\n");
if (NumVars>0) printf("Vars...\n");
for (i=0; i<NumVars+NumNumbers; i++)
printf("\t%s=%d\n",Vars[i].name,Vars[i].val);
if (NumLabels>0) printf("Labels...\n");
for (i=0; i<NumLabels; i++)
printf("\t%s=%d\n",Labels[i].name,Labels[i].val);
#endif
  pass3(fp); /* create Instructions */

#if DEBUG
printf("Instructions...\n");
for (i=0; i<NumInstructs; i++)
{ for (j=0; j<21; j++)
    if(InstructInfo[j].oper==Instructs[i].oper)
    { printf("\t%s: ",Reserved[j]);
      break;
    }
  for(k=0; k<InstructInfo[j].numArgs; k++)
    printf("%d ",Instructs[i].args[k]);
  printf("\n");
}
#endif
  IP=0;
  ACC=0;
  for(;;)
  { Instructs[IP].oper(Instructs[IP].args[0],Instructs[IP].args[1]);
    IP++;
  }
  return 0;
}
