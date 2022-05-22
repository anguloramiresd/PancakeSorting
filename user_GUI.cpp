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
    std::cin >> algo;
    std::cin >> size;
    initial_vec = Input(size);
    switch (algo) {
        case 1:
            exhaustive = new SortExhaustive(size);
            exhaustive->Sort();
            std::cout << exhaustive->GetSteps(initial_vec);
            break;
        case 2:
            pancakes = new Sort3Approximation(initial_vec);
            std::cout << pancakes->Sort();
            break;
        case 3:
            pancakes = new Sort2Approximation(initial_vec);
            std::cout << pancakes->Sort();
            break;
        default:
            break;
    }
}

int main() {
    Menu();
    return 0;
}
