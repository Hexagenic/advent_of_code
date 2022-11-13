#include "common.h"

SolutionRegister& SolutionRegister::getSolutionRegisterInstance() {
    static SolutionRegister instance;
    return instance;
}

int SolutionRegister::registerSolution(int i, SolutionPtr fun_ptr) {
    return getSolutionRegisterInstance().internalRegister(i - 1, fun_ptr);
}

SolutionPtr SolutionRegister::getSolution(int i) {
    return getSolutionRegisterInstance().func_ptrs[i - 1];
}

int SolutionRegister::internalRegister(int i, SolutionPtr fun_ptr) {
    if (i < 0 || i > 24) {
        return 0;
    }
    func_ptrs[i] = fun_ptr;
    return i;
}
