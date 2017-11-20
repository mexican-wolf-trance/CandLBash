      READ X
      COPY Z X

LOOP1: LOAD X
      BRZERO OUT1
      BRNEG  OUT1
      READ Y
      LOAD Y
      PUSH
      STACKW 0
      LOAD X
      SUB 1
      STORE X
      BR LOOP1

OUT1:  NOOP

      LOAD 0
      STORE Y
LOOP2: STACKR 0
      ADD Y
      STORE Y
      POP
      LOAD Z
      SUB 1
      BRZERO OUT2
      BRNEG OUT2
      STORE Z
      BR LOOP2
OUT2:  NOOP
      WRITE Y

STOP
X 0
Y 0
Z 0
