#include "fstack.h"

// fstackframe

fstackframe::fstackframe() {
    vars = new vct();
}

void fstackframe::clear() {
    vars->clear();
    delete vars;
}

// fstack 

fstack::fstack() {
    glob = new fstackframe();
    stack = new std::vector<fstackframe*>;
}

void fstack::clear() {
    glob->clear();
    delete glob;
    while (!pop());
    delete stack;
}

fstackframe* fstack::top() {
    if (stack->size() == 0) return NULL;
    return (*stack)[stack->size() - 1];
}

int32_t fstack::push(fstackframe* frame) {
    stack->push_back(frame);
    return 0;
}

int32_t fstack::pop() {
    if (stack->size() == 0) return -1;
    top()->clear();
    delete top();
    stack->pop_back();
}

bool fstack::empty() {
    return (stack->size() == 0);
}