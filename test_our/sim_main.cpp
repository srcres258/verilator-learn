#include "Vour.h"
#include <verilated.h>

int main(int argc, char **argv) {
    VerilatedContext *contextp;
    Vour *top;

    contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    top = new Vour { contextp };
    while (!contextp->gotFinish()) {
        top->eval();
    }
    delete top;
    delete contextp;

    return 0;
}
