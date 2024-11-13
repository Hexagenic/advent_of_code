#include <iostream>
#include <string>

#include "common.h"

int main() {
    for (int i = 1; i <= 25; ++i) {
        auto f = SolutionRegister::getSolution(i);

        if (f) {
            auto a = std::ifstream("input/day" + std::to_string(i) + ".txt");
            std::cout << i << "a: " << f(a, Part::first) << std::endl;

            auto b = std::ifstream("input/day" + std::to_string(i) + ".txt");
            std::cout << i << "b: " << f(b, Part::second) << std::endl;
        }
    }
}
