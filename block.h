#ifndef evm_block
#define evm_block

#include "std.h"

enum inst : u_int16_t {
    add,
    set,
    printint,
    newline,
    quit
};

struct block {

    u_int32_t id;
    u_int16_t size;
    u_int16_t *start;
    std::bitset<65536> *is_instruction;

    block(u_int16_t _sz, u_int16_t *_st) {
        size=_sz, start=_st;
    }

};

#endif