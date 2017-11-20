#include <stdio.h>
#include <ctype.h>

int main(void){
    int pCount=0, parCount=0, cCount=0, lCount=0;//word, paragraph, character, line
    int abCount = 0;//alphabet 
    double prom=0;
    int c;//It should be int.
    char pprev = '\n', prev = '\n';

    while ((c=getchar())!=EOF){
        ++cCount;
        if(isalpha(c))
            ++abCount;
        if(isspace(c)){
            if(c == '\n'){
                ++lCount;
            }
        } else if(isspace(prev)){//isspace(prev) && !isspace(c) : edge of top of word
            ++pCount;
            if(pprev == '\n' && prev == '\n'){//edge of top of paragraph
                ++parCount;
            }
        }
        pprev = prev;
        prev = c;
    }
    if(prev != '\n'){//If the file is not terminated by newline
        ++lCount;
    }

    prom = (double)abCount / pCount;//(cCount - spcCount - punctCount) / pCount
    printf("Total caracteres: %d \n", cCount);
    printf("Cantidad palabras: %d \n", pCount);
    printf("Cantidad lineas: %d \n", lCount);
    printf("Cantidad parrafos: %d \n", parCount);
    printf("Promedio longitud palabra: %.3f \n", prom);
    return 0;
}
