//
// Created by dieguin on 07-05-22.
//

#include "include/Headers.h"
#include "include/SortExhaustive.h"
#include "include/Sort3Approximation.h"
#include "include/Sort2Approximation.h"

std::vector<int> Input(const size_t &size) {
    std::vector<int> aux(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> aux[i];
    }
    return aux;
}

void Menu() {
    int algo, size, type;
    std::vector<int> initial_vec;
    SortExhaustive *exhaustive;
    SortPancakes *pancakes;
    std::cout << "Which Algorithm will you use?\n";
    std::cout << "1) Exhaustive\t 2) 3-Approx\t 3) 2-Approx\n";
    std::cin >> algo;
    std::cout << "Size? ";
    std::cin >> size;
    std::cout << "Random permutation(1) or defined one(2)? ";
    std::cin >> type;
    if (type == 2) {
        std::cout << "Insert the " << size << " elements: ";
        initial_vec = Input(size);
    }
    switch (algo) {
        case 1:
            exhaustive = new SortExhaustive(size);
            exhaustive->Sort();
            if (type == 1) {
                pancakes = new Sort2Approximation(size);
                pancakes->Print();
                std::cout << "Number of flips calculated: " << exhaustive->GetSteps(pancakes->GetPermutation()) << '\n';
            } else {
                std::cout << "Number of flips calculated: " << exhaustive->GetSteps(initial_vec) << '\n';
            }
            break;
        case 2:
            if (type == 1) {
                pancakes = new Sort3Approximation(size);
                pancakes->Print();
            } else {
                pancakes = new Sort3Approximation(initial_vec);
            }
            std::cout << "Number of flips calculated: " << pancakes->Sort() << '\n';
            break;
        case 3:
            if (type == 1) {
                pancakes = new Sort2Approximation(size);
                pancakes->Print();
            } else {
                pancakes = new Sort2Approximation(initial_vec);
            }
            std::cout << "Number of flips calculated: " << pancakes->Sort() << '\n';
            break;
        default:
            break;
    }
}

int main() {
    Menu();
    return 0;
}
