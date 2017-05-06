#include "memory.h"

Memory::Memory()
{
    for(int i = 0; i <50; ++i)
    {
        mem[i] = 0;
    }
}

Memory::Memory(int option)
{
    for(int i = 0; i <50; ++i)
    {
        mem[i] = 0;
    }
}

int Memory::getMem(int index)
{
    return mem[index];
}

void Memory::setMem(int index, int value)
{
    mem[index] = value;
}


void Memory::printAll()
{
    cout << "Memory values:" << endl;
    for(int i = 0; i < 50; ++i)
    {
        cout << "[" << i << "] -> " << getMem(i) << endl;
    }
}
