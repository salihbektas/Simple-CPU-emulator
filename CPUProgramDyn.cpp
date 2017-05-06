#include "CPUProgramDyn.h"
using namespace std;


CPUProgramDyn::CPUProgramDyn()
{
    fileString = new string[DEFAULT];
}

CPUProgramDyn::CPUProgramDyn(int option)
{
    fileString = new string[DEFAULT];
}

CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& obj)
{
    fileString = new string[obj.numberOfLines];
    numberOfLines = obj.numberOfLines;

    for(int i = 0; i < obj.numberOfLines; ++i)
    {
        fileString[i] = obj.fileString[i];
    }
}

CPUProgramDyn::CPUProgramDyn(const char* fileName){
    ReadFile(fileName);
}

CPUProgramDyn::~CPUProgramDyn(){
    delete [] fileString;
}

//Transfer data from file to fileArray and set numberOfLines
void CPUProgramDyn::ReadFile(const char* fileName){

    numberOfLines = determineNumberOfLines(fileName);

    if(fileString != nullptr)
    {
        delete [] fileString;
    }

    fileString = new string[numberOfLines];
    fstream file;
    string line;
    file.open(fileName);

    for(int i = 0; i < numberOfLines; ++i)
    {
        getline (file,fileString[i]);
    }

    file.close();
}

/*Take integer
 *Write one line from fileArray to string
 */
const string CPUProgramDyn::getLine(int line) const
{

    if(line >= numberOfLines || line < 0){
            cout << "Error: Overflow fileString." << endl
                 << "Returned empty string" << endl;

            string empty;

            return empty;
        }

    return fileString[line];
}

const int CPUProgramDyn::size()const
{
    return numberOfLines;
}

const CPUProgramDyn CPUProgramDyn::operator--()
{
    CPUProgramDyn temp;
    temp = *this;
    delete [] fileString;
    --numberOfLines;
    fileString = new string[numberOfLines];
    for(int i = 0; i < numberOfLines; ++i)
    {
        fileString[i] = temp.fileString[i];
    }

    return *this;
}

const CPUProgramDyn CPUProgramDyn::operator--(int)
{
    CPUProgramDyn newObj;
    newObj = *this;
    delete [] fileString;
    --numberOfLines;
    fileString = new string[numberOfLines];
    for(int i = 0; i < numberOfLines; ++i)
    {
        fileString[i] = newObj.fileString[i];
    }

    return newObj;
}

const CPUProgramDyn CPUProgramDyn::operator+=(string instraction)
{
    if( instraction != ""){
        CPUProgramDyn temp;
        temp = *this;
        delete [] fileString;
        fileString = new string[numberOfLines+1];
        for(int i = 0; i < numberOfLines; ++i)
        {
            fileString[i] = temp.fileString[i];
        }
        fileString[numberOfLines] = instraction;
        ++numberOfLines;
        return *this;
    }

    else{
        cout << "Error: Empty string try to add object." << endl
             << "+= not proceed." << endl;

        CPUProgramDyn emptyObj;
        return emptyObj;
    }

}

string& CPUProgramDyn::operator[](int line)
{
    if(line >= numberOfLines || line < 0){
        cout << "Error: Overflow fileString." << endl
             << "Returned empty string" << endl;

        return empty;
    }

    return fileString[line];
}

CPUProgramDyn CPUProgramDyn::operator+(const string instraction) const
{
    CPUProgramDyn newObj;
    newObj = *this;
    newObj+= instraction;
    return newObj;
}

CPUProgramDyn CPUProgramDyn::operator+(CPUProgramDyn& rSide) const
{
    CPUProgramDyn newObj;
    newObj = *this;
    for(int i = 0; i < rSide.size(); ++i)
    {
        newObj += rSide.getLine(i);
    }

    return newObj;
}

const CPUProgramDyn CPUProgramDyn::operator()(int start, int end) const
{
    CPUProgramDyn newObj, emptyObj;

    if(start > size()-1 || end > size()-1){
        cout << "Error: Overflow fileString." << endl;

        return emptyObj;
    }

    for(int i = start; i <= end; ++i)
    {
        newObj += this->getLine(i);
    }

    return newObj;
}
const bool CPUProgramDyn::operator==(CPUProgramDyn rSide)const
{
    bool result = false;

    if (size() == rSide.size())
        result = true;

    return result;
}

const bool CPUProgramDyn::operator!=(CPUProgramDyn rSide)const
{
    return !(*this == rSide);
}

const bool CPUProgramDyn::operator<(CPUProgramDyn rSide)const
{
    bool result = false;

    if(size() < rSide.size())
        result = true;

    return result;
}

const bool CPUProgramDyn::operator<=(CPUProgramDyn rSide)const
{
    bool result = false;

    if(size() <= rSide.size())
        result = true;

    return result;
}

const bool CPUProgramDyn::operator>(CPUProgramDyn rSide)const
{
    return !(*this <= rSide);
}

const bool CPUProgramDyn::operator>=(CPUProgramDyn rSide)const
{
    return !(*this < rSide);
}

ostream& operator << (ostream& out, const CPUProgramDyn& myProg)
{
    for(int i = 0; i < myProg.size(); ++i)
    {
        out << myProg.getLine(i);

        if(i != myProg.size()-1)
            out << endl;
    }
    return out;
}

const int CPUProgramDyn::determineNumberOfLines(const char* fileName)const
{
    int line = 0;
    string buffer;
    fstream file;

    file.open(fileName);

    for(getline(file, buffer); !(file.eof()) ; getline(file, buffer)){
        ++line;
    }

    file.close();
    return line;
}

CPUProgramDyn CPUProgramDyn::operator = (CPUProgramDyn rSide)
{
    if(rSide.numberOfLines != numberOfLines)
    {
        delete [] fileString;
        fileString = new string[rSide.numberOfLines];
        numberOfLines = rSide.numberOfLines;
    }
    for(int i = 0; i < rSide.numberOfLines; ++i)
    {
        fileString[i] = rSide.fileString[i];
    }

    return *this;
}
