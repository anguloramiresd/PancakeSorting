#include "Headers.h"
#include "SortExhaustive.h"
#include "Sort3Approximation.h"
#include "Sort2Approximation.h"

int main() {
    int size;
    std::string type;
    std::cin >> type >> size;
    std::vector<int> original(size);
    SortPancakes *pancakes;
    std::vector<bool> active(3, false);

    if (type == "1st") {
        active[0] = true;
    } else if (type == "2nd") {
        active[1] = true;
    } else if (type == "3rd") {
        active[2] = true;
    } else if (type == "All") {
        active[0] = true;
        active[1] = true;
        active[2] = true;
    } else {
        std::cout << "Invalid run\n";
        return 0;
    }

    std::vector<int> sorted(size);
    for (size_t i = 0; i < size; ++i) {
        sorted[i] = (int) i + 1;
    }

    SortExhaustive *pancakes_exhaustive;
    if (active[0]) {
        pancakes_exhaustive = new SortExhaustive(size);
        pancakes_exhaustive->Sort();
    }

    while (std::cin >> original[0]) {
        for (size_t i = 1; i < original.size(); ++i) {
            std::cin >> original[i];
        }

        if (active[0]) {
            std::cout << pancakes_exhaustive->GetSteps(original) << '\n';
        }
        if (active[1]) {
            pancakes = new Sort3Approximation(original);
            std::cout << pancakes->Sort() << '\n';
        }
        if (active[2]) {
            pancakes = new Sort2Approximation(original);
            std::cout << pancakes->Sort() << '\n';

            if (sorted != pancakes->GetPermutation()) {
                std::cout << "Fail\n";
            } else {
                std::cout << "Ok\n";
            }
        }
    }

    return 0;
}
