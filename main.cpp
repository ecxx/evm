#include "vm.h"

int main() {

    u_int16_t instructions[] = {
        inst::set, 0, 1, 
        inst::set, 1, 1, 
        inst::add, 0, 1, 2, 
        inst::printint, 0, 
        inst::newline, 
        inst::printint, 1, 
        inst::newline, 
        inst::printint, 2, 
        inst::newline, 
        inst::quit
    };

    block b = block(sizeof(instructions)/sizeof(instructions[0]), instructions);

    std::vector<block> vb;
    vb.push_back(b);

    auto vmx = vm(&vb);

    vmx.execute(0);

}