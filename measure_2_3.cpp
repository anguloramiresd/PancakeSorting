//
// Created by dieguin on 21-05-22.
//

#include "include/Headers.h"
#include "include/Sort3Approximation.h"
#include "include/Sort2Approximation.h"

int main() {
    size_t max_size, jumps;
    std::cin >> max_size >> jumps;
    std::vector<double> time_approx3, time_approx2;
    Sort3Approximation *sort_approx3;
    Sort2Approximation *sort_approx2;
    std::vector<double> approx3_flips, approx2_flips;

    for (size_t size = jumps; size <= max_size; size += jumps) {
        auto start = std::chrono::high_resolution_clock::now();
        auto ending = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ms = ending - start;

        size_t c = 0, steps;
        approx2_flips.push_back(0);
        approx3_flips.push_back(0);
        time_approx2.push_back(0);
        time_approx3.push_back(0);
        size_t last = time_approx3.size() - 1;
        std::vector<int> aux;
        do {
            /// 3 - Approximation
            /// Run, and timing
            sort_approx3 = new Sort3Approximation(size);
            aux = sort_approx3->GetPermutation();
            start = std::chrono::high_resolution_clock::now();
            steps = sort_approx3->Sort();
            ending = std::chrono::high_resolution_clock::now();
            time_ms = ending - start;
            time_approx3[last] += time_ms.count();

            /// Flips counter
            approx3_flips[last] += steps;

            /// 2 - Approximation
            /// Run, and timing
            sort_approx2 = new Sort2Approximation(aux);
            start = std::chrono::high_resolution_clock::now();
            steps = sort_approx2->Sort();
            ending = std::chrono::high_resolution_clock::now();
            time_ms = ending - start;

            /// Flips counter
            time_approx2[last] += time_ms.count();
            approx2_flips[last] += steps;
            c++;
        } while (c < std::min(size_t(200), size));
        time_approx2[time_approx3.size() - 1] /= double(c);
        time_approx3[time_approx3.size() - 1] /= double(c);
        approx2_flips[time_approx3.size() - 1] /= double(c);
        approx3_flips[time_approx3.size() - 1] /= double(c);
    }
    for (double i: time_approx3) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    for (double i: time_approx2) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    for (double approx3_flip: approx3_flips) {
        std::cout << approx3_flip << " ";
    }
    std::cout << '\n';
    for (double approx2_flip: approx2_flips) {
        std::cout << approx2_flip << " ";
    }
    std::cout << '\n';
    return 0;
}
