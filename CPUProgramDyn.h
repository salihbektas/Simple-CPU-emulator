#ifndef CPUPROGRAMDYN_H
#define CPUPROGRAMDYN_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <typeinfo>

using namespace std;

#define DEFAULT 50

class CPUProgramDyn {
public:
    CPUProgramDyn();
    CPUProgramDyn(const char* fileName);
    CPUProgramDyn(int option);
    CPUProgramDyn(const CPUProgramDyn& obj);
    ~CPUProgramDyn();
    void ReadFile(const char* fileName);
    const string getLine(int)const;
    const int size()const;
    const CPUProgramDyn operator --();
    const CPUProgramDyn operator --(int);
    const CPUProgramDyn operator +=(string instraction);
    string& operator [](int line);
    CPUProgramDyn operator +(const string instraction)const;
    CPUProgramDyn operator +(CPUProgramDyn& rSide)const;
    const CPUProgramDyn operator ()(int start, int end)const;
    const bool operator ==(CPUProgramDyn rSide)const;
    const bool operator !=(CPUProgramDyn rSide)const;
    const bool operator <(CPUProgramDyn rSide)const;
    const bool operator <=(CPUProgramDyn rSide)const;
    const bool operator >(CPUProgramDyn rSide)const;
    const bool operator >=(CPUProgramDyn rSide)const;
    friend ostream& operator << (ostream& outputStream, const CPUProgramDyn& myProg);
    CPUProgramDyn operator = (const CPUProgramDyn rSide);

private:
    int numberOfLines = 0;
    int maxLengthOfLines = 0;
    string *fileString = nullptr;
    string empty = "";
    const int determineNumberOfLines(const char* fileName)const;

};

#endif
