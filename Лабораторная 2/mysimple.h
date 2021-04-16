#ifndef MYSIMPLE_H
#define MYSIMPLE_H
#define MEMORY_CAPACITY 100

#define M 1
#define O 2
#define P 3
#define T 4
#define E 5

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int r, int value);
int sc_regGet(int r, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);


#endif
