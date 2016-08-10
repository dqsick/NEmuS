#include <iostream> // used for printing to console
#include <fstream>  // used for ifstream
#include <stdlib.h> // used for exit

using std::ios;
using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char* argv[])
{
    // Make sure a ROM file was entered.
    if (argc < 2)
    {
        cout << "Enter file to be read" << endl;
        exit(1);
    }

    ifstream readRom(argv[1]);
    if(readRom.is_open())
    {
        cout << "File opening succeeded." << endl;
    }
    else
    {
        cout << "File opening failed." << endl;
    }
}

