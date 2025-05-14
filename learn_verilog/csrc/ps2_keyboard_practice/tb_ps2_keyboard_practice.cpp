#include <nvboard.h>
#include "Vps2_keyboard_practice.h"

Vps2_keyboard_practice *top;

void nvboard_bind_all_pins(Vps2_keyboard_practice *top);

void single_cycle() {
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();
}

int main() {
    top = new Vps2_keyboard_practice;
    nvboard_bind_all_pins(top);
    nvboard_init();

    while (true) {
        nvboard_update();
        single_cycle();
    }

    delete top;
    return 0;
}
