#ifndef evm_vcb
#define evm_vcb

#include "std.h"

#define VAR_VALID(vcb) vcb->_data&1
#define VAR_CONSTANT(vcb) (vcb->_data&2)>>1
#define VAR_IS_POINTER(vcb) (vcb->_data&4)>>1
#define VAR_SIZE(vcb) (vcb>>8)&(0xFFFFFFFFULL)

struct vcb {
    u_int64_t _data;
    u_int64_t _val;

    void clear();

    void reset();
    void set_pointer();
    void unset_pointer();

};

struct vct {
    // size of 4096
    vcb* blocks;

    vct();
    void clear();

    u_int64_t read(u_int32_t pos);
    int32_t write(u_int32_t pos, u_int64_t val, int isp);

};

#endif