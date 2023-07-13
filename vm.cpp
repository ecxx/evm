#include "vm.h"

void vm::execute(int index) {
    block b = (*blocks)[index];
    u_int16_t t = 0;
    u_int16_t* IP = b.start;

    while (true) {


        if (IP[t] == inst::quit) return;
        if (t >= b.size) return;

        u_int16_t arg, aux, fin; u_int64_t val1, val2;

        switch (IP[t++]) {
            case inst::add:
                arg = IP[t++];
                aux = IP[t++];
                fin = IP[t++];
                val1 = var->read(arg);
                val2 = var->read(aux);
                var->write(fin, val1 + val2, 0);
                break;
            case inst::printint:
                arg = IP[t++];
                val1 = var->read(arg);
                std::cout << val1;
                break;
            case inst::newline:
                std::cout << "\n";
                break;
            case inst::set:
                arg = IP[t++];
                aux = IP[t++];
                var->write(arg, aux, 0);
                break;
        }

    }
}

