#include "mysimple.h"
#include <cstdio>

int memory[MEMORY_CAPACITY];

int reg;

//инициализируем память на 100 элементов
int sc_memoryInit(){
    for(int i = 0; i < MEMORY_CAPACITY; i++){
        memory[i] = 0;
    }
    return 0;
}

//инициализация флагов
int sc_regInit(){
    reg = 0;
    return 0;
}

//устанаваливает значение регистра флагов
int sc_regSet(int r, int value){
    if (r < 0 || r >= 5){
        return -1;
    }
    if(value == 1){
        reg = reg | (1 << (r - 1));
    }
    if(value == 0){
        reg = reg & (~(1 << (r - 1)));
    }
    return -2;
}

//возвращает значение указанного флага
int sc_regGet(int r, int* value){
    if (r < 0 || r >= 5){
        return -1;
    }
    *value = (reg >> (r - 1)) & 1;
    return 0;
}

//задает значение указанной ячейки памяти с флагом выхода за границы
int sc_memorySet(int address, int value)
{
    if(address < 0 || address >= MEMORY_CAPACITY){
        sc_regSet(M,1);
        return -1;
    }
    memory[address] = value;
    return 0;
}

//возвращает значение указанной ячейки памяти. Без изменения value
int sc_memoryGet(int address, int* value){
    if(address < 0 || address >= MEMORY_CAPACITY){
        sc_regSet(M,1);
        return -1;
    }
    *value = memory[address];
    return 0;
}

//сохраняем содержимое памяти в файл
int sc_memorySave(char* filename){
    FILE* file = fopen(filename,"wb");
    fwrite(memory,sizeof(int),MEMORY_CAPACITY,file);
    fclose(file);
    return 0;
}

//загрузка из файла данных
int sc_memoryLoad(char* filename){
    FILE* file = fopen(filename,"rb");
    fread(memory,sizeof(int),MEMORY_CAPACITY,file);
    fclose(file);
    return 0;
}

//кодировка команды
int sc_commandEncode(int command, int operand, int* value){
    if(operand > 0 && operand <= 100){
        int flag = 0;
        int commands[] = {10,11,20,21,30,31,32,33,40,41,42,43,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76};
        for(int i = 0; i < 13; i++){
            if (command == commands[i]){
                flag++;
                break;
            }
        }
        for(int i = 51; i < 77; i++){
            if (flag || command == i){
                flag++;
                break;
            }
        }
        if(!flag){
            return 1;
        }
    }
    *value = 16383 & ((command << 7) | operand);
    return 0;
}

//декодирует значение как команду
int sc_commandDecode(int value, int* command, int* operand){
    if ((value & 32768) != 0){
        sc_regSet(E,1);
        return -1;
    }
    *operand = value & 127;
    value >>= 7;
    *command = value & 127;
    return 0;
}
