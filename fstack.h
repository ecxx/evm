#ifndef evm_fstack
#define evm_fstack

#include "std.h"
#include "vcb.h"

struct fstackframe {
    
    vct *vars;
    fstackframe();
    void clear();
    
};

struct fstack {

    fstackframe *glob;
    std::vector<fstackframe*> *stack;

    fstack();
    void clear();

    fstackframe* top();
    int32_t push(fstackframe* frame);
    int32_t pop();
    bool empty();

};

#endif