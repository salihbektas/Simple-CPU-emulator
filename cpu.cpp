#include "cpu.h"

using namespace std;

CPU::CPU()
{
    setR1(0);
    setR2(0);
    setR3(0);
    setR4(0);
    setR5(0);
    setPC(1);
}

CPU::CPU(int option)
{
    setR1(0);
    setR2(0);
    setR3(0);
    setR4(0);
    setR5(0);
    setPC(1);
}

CPU::CPU(int reg1, int reg2, int reg3, int reg4, int reg5,
            int progcount)
{
    setR1(reg1);
    setR2(reg2);
    setR3(reg3);
    setR4(reg4);
    setR5(reg5);
    setPC(progcount);
}

void CPU::setR1(int value)
{
    r1 = value;
}

void CPU::setR2(int value)
{
    r2 = value;
}

void CPU::setR3(int value)
{
    r3 = value;
}

void CPU::setR4(int value)
{
    r4 = value;
}

void CPU::setR5(int value)
{
    r5 = value;
}

void CPU::setPC(int value)
{
    PC = value;
}

void CPU::setMaxLine(int value)
{
    maxLine = value;
}

int CPU::getR1()
{
    return r1;
}

int CPU::getR2()
{
    return r2;
}

int CPU::getR3()
{
    return r3;
}

int CPU::getR4()
{
    return r4;
}

int CPU::getR5()
{
    return r5;
}

int CPU::getPC()
{
    return PC;
}

int CPU::getMaxLine()
{
    return maxLine;
}

void CPU::print()
{
    cout <<"Register Values:" << endl
         << "[" << 0 << "]->" << getR1() << endl
         << "[" << 1 << "]->" << getR2() << endl
         << "[" << 2 << "]->" << getR3() << endl
         << "[" << 3 << "]->" << getR4() << endl
         << "[" << 4 << "]->" << getR5() << endl;
}

void CPU::execute(string str, Memory& myMemory)
{
    string vord1, vord2, vord3;
    int i=0;
    int intBuffer, memIndex;
    vord1 = split(i, str);
    //Meve instruction area
    if(vord1 == "MOV" || vord1 == "Mov" || vord1 == "mov"){
        vord2 = split(i, str);
        vord3 = split(i, str);

        if(vord2 == "R1" || vord2 == "r1"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR1(intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                myMemory.setMem(memIndex, getR1());
            }
            else{
                if(vord3 == "R1" || vord3 == "r1")
                {
                    setR1(getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2")
                {
                    setR2(getR1());
                }
                else if(vord3 == "R3" || vord3 == "r3")
                {
                    setR3(getR1());
                }
                else if(vord3 == "R4" || vord3 == "r4")
                {
                    setR4(getR1());
                }
                else if(vord3 == "R5" || vord3 == "r5")
                {
                    setR5(getR1());
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R2" || vord2 == "r2"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR2(intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                myMemory.setMem(memIndex, getR2());
            }
            else{
                if(vord3 == "R1" || vord3 == "r1")
                {
                    setR1(getR2());
                }
                else if(vord3 == "R2" || vord3 == "r2")
                {
                    setR2(getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3")
                {
                    setR3(getR2());
                }
                else if(vord3 == "R4" || vord3 == "r4")
                {
                    setR4(getR2());
                }
                else if(vord3 == "R5" || vord3 == "r5")
                {
                    setR5(getR2());
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R3" || vord2 == "r3"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR3(intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                myMemory.setMem(memIndex, getR3());
            }
            else{
                if(vord3 == "R1" || vord3 == "r1")
                {
                    setR1(getR3());
                }
                else if(vord3 == "R2" || vord3 == "r2")
                {
                    setR2(getR3());
                }
                else if(vord3 == "R3" || vord3 == "r3")
                {
                    setR3(getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4")
                {
                    setR4(getR3());
                }
                else if(vord3 == "R5" || vord3 == "r5")
                {
                    setR5(getR3());
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R4" || vord2 == "r4"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR4(intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                myMemory.setMem(memIndex, getR4());
            }
            else{
                if(vord3 == "R1" || vord3 == "r1")
                {
                    setR1(getR4());
                }
                else if(vord3 == "R2" || vord3 == "r2")
                {
                    setR2(getR4());
                }
                else if(vord3 == "R3" || vord3 == "r3")
                {
                    setR3(getR4());
                }
                else if(vord3 == "R4" || vord3 == "r4")
                {
                    setR4(getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5")
                {
                    setR5(getR4());
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R5" || vord2 == "r5"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR5(intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                myMemory.setMem(memIndex, getR5());
            }
            else{
                if(vord3 == "R1" || vord3 == "r1")
                {
                    setR1(getR5());
                }
                else if(vord3 == "R2" || vord3 == "r2")
                {
                    setR2(getR5());
                }
                else if(vord3 == "R3" || vord3 == "r3")
                {
                    setR3(getR5());
                }
                else if(vord3 == "R4" || vord3 == "r4")
                {
                    setR4(getR5());
                }
                else if(vord3 == "R5" || vord3 == "r5")
                {
                    setR5(getR5());
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(isMemory(vord2))
        {
            memIndex = doInteger(vord2);

            if(isInteger(vord3))
            {
                intBuffer = doInteger(vord3);
                if(intBuffer < 0)
                {
                    cerr << "The value which is move to memory, must be "
                         << "unsigned integer" <<endl;
                    exit(1);
                }
                myMemory.setMem(memIndex, intBuffer);
            }

            else {
                if (vord3 == "R1" || vord3 == "r1")
                {
                    setR1(myMemory.getMem(memIndex));
                }
                else if (vord3 == "R2" || vord3 == "r2")
                {
                    setR2(myMemory.getMem(memIndex));
                }
                else if (vord3 == "R3" || vord3 == "r3")
                {
                    setR3(myMemory.getMem(memIndex));
                }
                else if (vord3 == "R4" || vord3 == "r4")
                {
                    setR4(myMemory.getMem(memIndex));
                }
                else if (vord3 == "R5" || vord3 == "r5")
                {
                    setR5(myMemory.getMem(memIndex));
                }
                else
                {
                    cerr << "Move instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else
        {
            cerr << "Move instruction can't proceed" << endl;
            setPC(getMaxLine());
        }
        setPC(getPC()+1);
    }
    //ADD instruction area
    else if(vord1 == "ADD" || vord1 == "Add" || vord1 == "add"){
        vord2 = split(i, str);
        vord3 = split(i, str);
        if(vord2 == "R1" || vord2 == "r1"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR1(getR1() + intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR1(getR1() + myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR1(getR1() + getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR1(getR1() + getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR1(getR1() + getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR1(getR1() + getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR1(getR1() + getR5());
                }
                else
                {
                    cerr << "Add instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R2" || vord2 == "r2"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR2(getR2() + intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR2(getR2() + myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR2(getR2() + getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR2(getR2() + getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR2(getR2() + getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR2(getR2() + getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR2(getR2() + getR5());
                }
                else
                {
                    cerr << "Add instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R3" || vord2 == "r3"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR3(getR3() + intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR3(getR3() + myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR3(getR3() + getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR3(getR3() + getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR3(getR3() + getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR3(getR3() + getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR3(getR3() + getR5());
                }
                else
                {
                    cerr << "Add instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R4" || vord2 == "r4"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR4(getR4() + intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR4(getR4() + myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR4(getR4() + getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR4(getR4() + getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR4(getR4() + getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR4(getR4() + getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR4(getR4() + getR5());
                }
                else
                {
                    cerr << "Add instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R5" || vord2 == "r5"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR5(getR5() + intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR5(getR5() + myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR5(getR5() + getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR5(getR5() + getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR5(getR5() + getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR5(getR5() + getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR5(getR5() + getR5());
                }
                else
                {
                    cerr << "Add instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else
        {
            cerr << "Add instruction can't proceed" << endl;
            setPC(getMaxLine());
        }
        setPC(getPC()+1);
    }
    //Subtraction instruction area
    else if(vord1 == "SUB" || vord1 == "Sub" || vord1 == "sub"){
        vord2 = split(i, str);
        vord3 = split(i, str);
        if(vord2 == "R1" || vord2 == "r1"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR1(getR1() - intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR1(getR1() - myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR1(getR1() - getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR1(getR1() - getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR1(getR1() - getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR1(getR1() - getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR1(getR1() - getR5());
                }
                else
                {
                    cerr << "Sub instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R2" || vord2 == "r2"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR2(getR2() - intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR2(getR2() - myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR2(getR2() - getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR2(getR2() - getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR2(getR2() - getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR2(getR2() - getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR2(getR2() - getR5());
                }
                else
                {
                    cerr << "Sub instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R3" || vord2 == "r3"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR3(getR3() - intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR3(getR3() - myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR3(getR3() - getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR3(getR3() - getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR3(getR3() - getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR3(getR3() - getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR3(getR3() - getR5());
                }
                else
                {
                    cerr << "Sub instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R4" || vord2 == "r4"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR4(getR4() - intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR4(getR4() - myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR4(getR4() - getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR4(getR4() - getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR4(getR4() - getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR4(getR4() - getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR4(getR4() - getR5());
                }
                else
                {
                    cerr << "Sub instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else if(vord2 == "R5" || vord2 == "r5"){
            if(isInteger(vord3)){
                intBuffer = doInteger(vord3);
                setR5(getR5() - intBuffer);
            }
            else if(isMemory(vord3))
            {
                memIndex = doInteger(vord3);
                setR5(getR5() - myMemory.getMem(memIndex));
            }
            else{
                if(vord3 == "R1" || vord3 == "r1"){
                    setR5(getR5() - getR1());
                }
                else if(vord3 == "R2" || vord3 == "r2"){
                    setR5(getR5() - getR2());
                }
                else if(vord3 == "R3" || vord3 == "r3"){
                    setR5(getR5() - getR3());
                }
                else if(vord3 == "R4" || vord3 == "r4"){
                    setR5(getR5() - getR4());
                }
                else if(vord3 == "R5" || vord3 == "r5"){
                    setR5(getR5() - getR5());
                }
                else
                {
                    cerr << "Subtraction instruction can't proceed" << endl;
                    setPC(getMaxLine());
                }
            }
        }
        else
        {
            cerr << "Subtraction instruction can't proceed" << endl;
            setPC(getMaxLine());
        }
        setPC(getPC()+1);
    }
    //Jump instruction area
    else if(vord1 == "JMP" || vord1 == "Jmp" || vord1 == "jmp")
    {
        vord2 = split(i, str);
        if (isInteger(vord2))
        {
            intBuffer = doInteger(vord2);
            setPC(intBuffer);
        }
        else
        {
            vord3 = split(i, str);
            if(isInteger(vord3))
            {
                intBuffer = doInteger(vord3);
            }

            if(vord2 == "R1" || vord2 == "r1")
            {
                if(getR1() == 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R2" || vord2 == "r2")
            {
                if(getR2() == 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R3" || vord2 == "r3")
            {
                if(getR3() == 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R4" || vord2 == "r4")
            {
                if(getR4() == 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R5" || vord2 == "r5")
            {
                if(getR5() == 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else
            {
                cerr << "Jump instruction can't proceed" << endl;
                setPC(getMaxLine());
            }
        }
    }
    //JPN instruction area
    else if(vord1 == "JPN")
    {
        vord2 = split(i, str);
        if (isInteger(vord2))
        {
            intBuffer = doInteger(vord2);
            setPC(intBuffer);
        }
        else
        {
            vord3 = split(i, str);
            if(isInteger(vord3))
            {
                intBuffer = doInteger(vord3);
            }

            if(vord2 == "R1" || vord2 == "r1")
            {
                if(getR1() <= 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R2" || vord2 == "r2")
            {
                if(getR2() <= 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R3" || vord2 == "r3")
            {
                if(getR3() <= 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R4" || vord2 == "r4")
            {
                if(getR4() <= 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else if(vord2 == "R5" || vord2 == "r5")
            {
                if(getR5() <= 0)
                    setPC(intBuffer);
                else
                    setPC(getPC()+1);
            }
            else
            {
                cerr << "Jump instruction can't proceed" << endl;
                setPC(getMaxLine());
            }
        }
    }
    //Print instruction area
    else if(vord1 == "PRN" || vord1 == "Prn" || vord1 == "prn")
    {
        vord2 = split(i, str);
        if(isInteger(vord2))
        {
            intBuffer = doInteger(vord2);
        }
        else if(isMemory(vord2))
        {
            memIndex = doInteger(vord2);
            cout << myMemory.getMem(memIndex) << endl;
        }
        else{
            if(vord2 == "R1" || vord2 == "r1")
            {
                cout << "R1 = " << getR1() << endl;
            }
            else if(vord2 == "R2" || vord2 == "r2")
            {
                cout << "R2 = " << getR2() << endl;
            }
            else if(vord2 == "R3" || vord2 == "r3")
            {
                cout << "R3 = " << getR3() << endl;
            }
            else if(vord2 == "R4" || vord2 == "r4")
            {
                cout << "R4 = " << getR4() << endl;
            }
            else if(vord2 == "R5" || vord2 == "r5")
            {
                cout << "R5 = " << getR5() << endl;
            }
            else
            {
                cerr << "Print instruction can't proceed" << endl;
                setPC(getMaxLine());
            }
        }
        setPC(getPC()+1);
    }
    //Halt instruction area
    else if(vord1 == "HLT")
    {
        setPC(getMaxLine());
        cout<<"Program halted" << endl
            <<"R1 = "<<getR1()<<' '<<"R2 = "<<getR2()<<' '
            <<"R3 = "<<getR3()<<' '<<"R4 = "<<getR4()<<' '
            <<"R5 = "<<getR5()<<endl;
    }
    else
    {
        cerr << "Wrong instruction name" << endl;
        setPC(getMaxLine());
    }
}
//decide is string translable to intager
bool CPU::isInteger(string ch)
{
    bool result = true;
    int size;
    size = ch.length();

    for(int i = 0; i < size; ++i){
        if((ch[i] < '0' || ch[i] > '9') && ch[i] != '-')
            result = false;
    }
    return result;
}
//decide is string translable to memory adress
bool CPU::isMemory(string ch)
{
    bool result = false;

    if(ch[0] == '#')
        result = true;

    return result;
}
/*take string decide positive or negative and
 *translate to integer
 */
int CPU::doInteger(string ch){
    int result = 0, x = 0, size= 0, i=0;
    bool negative = false;

    size = ch.length();
    if(ch[0] == '-'){
        negative = true;
        ++i;
    }
    else if(ch[0] == '#')
    {
        ++i;
    }

    while(i < size){
        result *= 10;
        x = ch[i] - '0';
        result += x;
        ++i;
    }

    if(negative)
        result *= -1;

    return result;
}
/*take a string and index
 * transfer one word from str to result and set index
 */
string CPU::split(int& i, string str)
{
    char temp[100];
    string result;
    int j= 0;
    while(str[i] != ' ' && str[i] != ',' && str[i] != ';' && str[i] != '\n'
            && str[i] != '\t' && str[i] != '\0')
    {
        temp[j] = str[i];
        ++(i);
        ++j;
    }

    temp[j] = '\0';

    result = temp;
    //set index for ignore space and coma and tab
    if(str[i] == ' ' || str[i] == ',' || str[i] == '\t')
    {
        i += 1;
    }
    //if result stay empty fonction call itself
    if(j == 0)
    {
        result = split(i, str);
    }
    return result;

}

bool CPU::halted()
{
    bool result = false;

    if(getPC() == getMaxLine())
        result = true;

    return result;
}
