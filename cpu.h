#ifndef CPU_H
#define CPU_H

#include <string>
#include "memory.h"

using namespace std;

class CPU{
    public:
        CPU();
        CPU(int option);
        CPU(int reg1, int reg2, int reg3, int reg4, int reg5, int progcount);

        void setR1(int value);
        void setR2(int value);
        void setR3(int value);
        void setR4(int value);
        void setR5(int value);
        void setPC(int value);
        void setMaxLine(int value);
        int getR1();
        int getR2();
        int getR3();
        int getR4();
        int getR5();
        int getPC();
        bool halted();
        int getMaxLine();
        void print();
        void execute(string, Memory&);
        string split(int& count, string str);
        bool isInteger(string ch);
        bool isMemory(string ch);
        int doInteger(string ch);
    private:
        int r1=0, r2=0, r3=0, r4=0, r5=0, PC=1;
        int maxLine;
};


#endif
