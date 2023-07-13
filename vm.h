#ifndef evm_vm
#define evm_vm

#include "std.h"
#include "vcb.h"
#include "fstack.h"
#include "block.h"

struct vm {

    vct *var;
    fstack *fs;
    std::vector<block> *blocks;

    int bidx = -1;
    u_int16_t sptr = -1;

    vm(std::vector<block> *_b) {
        var = new vct();
        fs = new fstack();
        blocks = _b;
    }

    void execute(int index);

};

#endif