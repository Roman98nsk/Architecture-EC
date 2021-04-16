#include "mysimple.h"
#include <iostream>

using namespace std;

int main(){
    sc_memoryInit();
    sc_regInit();
    char file[] = "test.bin";
    int commands[] = {10,11,20,21,30,31,32,33,40,41,42,43,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76};
    for(int i = 0; i < 100; i++){
        int c = commands[rand()%38];
        int o = rand()%127;
        int value = 0;
        sc_commandEncode(c,o,&value);
        sc_memorySet(i,value);
        cout << c << ':' << o << '/' << value << endl;
        if(i % 10 == 0 && i != 0){
            cout << endl;
        }
    }
    cout << endl << "ПОСЛЕ ЗАГРУЗКИ:" << endl << endl;
    sc_memorySave(file);
    sc_memoryLoad(file);
    for(int i = 0; i < 100; i++){
        int value = 0;
        int c = 0;
        int o = 0;
        sc_memoryGet(i,&value);
        sc_commandDecode(value,&c,&o);
        cout << c << ':' << o << '/' << value << endl;
        if(i % 10 == 0 && i != 0){
            cout << endl;
        }
    }
    return 0;
}
