#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>


using namespace std;

class Memory {
public:
    Memory();
    Memory(int option);
    void setMem(int index, int value);
    int getMem(int index);
    void printAll();
private:
    int mem[50];
};


#endif
