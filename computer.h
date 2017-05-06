#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "cpu.h"
#include "CPUProgramDyn.h"
#include "memory.h"


class Computer{
public:
    Computer(CPU oCpu, CPUProgramDyn oCpuProgram, Memory oMemory, int option);
    Computer(int option);
    CPU getCPU();
    CPUProgramDyn getCPUProgram();
    Memory getMemory();
    void setCPU(CPU other);
    void setCPUProgram(CPUProgramDyn other);
    void setMemory(Memory other);
    void execute();
private:
    CPU myCPU;
    CPUProgramDyn myCpuProgram;
    Memory myMemory;
    int debug;
};


#endif
