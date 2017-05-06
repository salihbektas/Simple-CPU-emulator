#include "requiredIncs.h"
using namespace std;

int main(int argc, char* argv[])
{
    int option;

    //Console argumans check
    if(argc != 3){
        cerr<< "Wrong Usage" << endl
            << "Example Usage: "<<argv[0]<<" <file_name.txt> <option>" << endl;
        return 1;
    }
    //Option check
    if (argv[2][0] != '0' && argv[2][0] != '1' && argv[2][0] != '2'){
        cerr << "Wrong option" << endl
             << "Option must be 0, 1 or 2" << endl;
        return 1;
    }

    if (argv[2][0] == '0')
        option = 0;
    else if (argv[2][0] == '1')
        option = 1;
    else if (argv[2][0] == '2')
        option = 2;

    CPU myCPU;
    CPUProgramDyn myProg(argv[1]);
    Memory myMemory;

    Computer myComputer(myCPU, myProg, myMemory, option);
    myComputer.execute();

    return 0;
}
