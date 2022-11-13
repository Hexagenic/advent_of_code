#pragma once

#include <fstream>
#include "third-party/doctest.h"
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

enum class Part {
    first,
    second
};

typedef int (*SolutionPtr)(std::istream& input, Part part);

class SolutionRegister
{
public:
    static int registerSolution(int i, SolutionPtr fun_ptr);

    static SolutionPtr getSolution(int i);
private:
    SolutionRegister() = default;
    int internalRegister(int i, SolutionPtr fun_ptr);

    static SolutionRegister& getSolutionRegisterInstance();

    SolutionPtr func_ptrs[25] = {nullptr};
};

#ifdef DOCTEST_CONFIG_DISABLE

#define REGISTER_SOLUTION(I, F) namespace { int dummy =  SolutionRegister::registerSolution(I, F); }

#else

#define REGISTER_SOLUTION(I, F)

#endif