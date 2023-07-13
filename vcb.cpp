#include "vcb.h"

// vcb

void vcb::reset() {
    _data = 0ULL;
    _val = 0ULL;
}

void vcb::set_pointer() {
    _data |= 0x4ULL;
}

void vcb::unset_pointer() {
    _data &= (~(0x4ULL));
}

void vcb::clear() {
    // TODO : Implement Garbage Collection
}


// vct

vct::vct() {
    blocks = new vcb[4096];
    for (int i = 0; i < 4096; i++) blocks[i].reset();
}

u_int64_t vct::read(u_int32_t pos) {
    if (pos > 4096) {
        return 0ULL;
    }
    return blocks[pos]._val;
}

int32_t vct::write(u_int32_t pos, u_int64_t val, int isp) {
    if (pos > 4096) {
        return -1;
    }
    if (VAR_CONSTANT((blocks+pos))) {
        return -1;
    }
    if (isp) blocks[pos].set_pointer();
    else blocks[pos].unset_pointer();
    blocks[pos]._val=val;
    return 0;
}

void vct::clear() {
    for (int i = 0; i < 4096; i++) blocks[i].clear();
    delete[] blocks;
}