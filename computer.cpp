#include "computer.h"


using namespace std;

Computer::Computer(CPU oCpu, CPUProgramDyn oCpuProgram, Memory oMemory, int option)
{
    setCPU(oCpu);
    setCPUProgram(oCpuProgram);
    setMemory(oMemory);
    debug = option;
}

Computer::Computer(int option)
{
    debug = option;
}

void Computer::setCPU(CPU oCpu)
{
    myCPU = oCpu;
}

void Computer::setCPUProgram(CPUProgramDyn oCpuProgram)
{
    myCpuProgram = oCpuProgram;
}

void Computer::setMemory(Memory oMemory)
{
    myMemory = oMemory;
}

CPU Computer::getCPU()
{
    return myCPU;
}

CPUProgramDyn Computer::getCPUProgram()
{
    return myCpuProgram;
}

Memory Computer::getMemory()
{
    return myMemory;
}

void Computer::execute()
{
    while(!myCPU.halted())
    {

        string instruction = myCpuProgram.getLine(myCPU.getPC()-1);

        myCPU.execute(instruction, myMemory);
        //Register debug mode part
        if(debug > 0)
        {
            cout <<"R1 = "<<myCPU.getR1()<<' '<<"R2 = "<<myCPU.getR2()<<' '
                 <<"R3 = "<<myCPU.getR3()<<' '<<"R4 = "<<myCPU.getR4()<<' '
                 <<"R5 = "<<myCPU.getR5()<<endl;

        }
        //Memory debug mode part
        if(debug == 2)
        {

            for(int i = 0; i < 50; i += 5){
                cout << "memory" << i+1 << " : " << myMemory.getMem(i)
                     << " memory" << i+2 << " : " << myMemory.getMem(i+1)
                     << " memory" << i+3 << " : " << myMemory.getMem(i+2)
                     << " memory" << i+4 << " : " << myMemory.getMem(i+3)
                     << " memory" << i+5 << " : " << myMemory.getMem(i+4)
                     <<endl;
            }
        }
    }
}
