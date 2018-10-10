#include <stdio.h>
#include <windows.h>

#include "peconv.h"
#include "pe_handler.h"

#define VERSION "1.0"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "DLL to EXE converter v"<< VERSION << " \n- for 32 & 64 bit DLLs -" << std::endl;
        std::cout << "args: <input_dll> <output_exe>" << std::endl;
        system("pause");
        return 0;
    }
    char *filename = argv[1];
    char *outfile = argv[2];

    PeHandler hndl(filename);
    if (!hndl.isDll()) {
        std::cout << "It is not a DLL!" << std::endl;
        return -1;
    }
    hndl.setDll();
    if (hndl.dllToExePatch()) {
        std::cout << "[OK] Converted successfuly."<< std::endl;
    } else {
        std::cout << "Could not convert!" << std::endl;
        return -1;
    }
    if (hndl.savePe(outfile)) {
        std::cout << "[OK] Module dumped to: " << outfile << std::endl;
    }
    return 0;
}
