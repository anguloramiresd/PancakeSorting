//
// Created by dieguin on 24-04-22.
//

#include "include/SortExhaustive.h"

SortExhaustive::SortExhaustive(int size) : num_pancakes_(size) {
    distance.clear();
    sorted.resize(size);
    for (size_t i = 0; i < num_pancakes_; ++i) {
        sorted[i] = (int) i + 1;
    }

}

void SortExhaustive::Flip(std::vector<int> &aux, int elements) {
    for (int i = 0; i < elements / 2; ++i) {
        std::swap(aux[i], aux[elements - i - 1]);
    }
}

void SortExhaustive::Sort() {
    /// Uses a BFS to check all possible outcomes with minimal number of steps
    std::queue<std::vector<int>> q;
    std::vector<int> actual, aux;
    distance[sorted] = 0;
    q.push(sorted);
    while (!q.empty()) {
        actual = q.front();
        q.pop();
        for (int i = 2; i <= num_pancakes_; ++i) {
            aux = actual;
            Flip(aux, i);
            if (distance[aux] == 0 && aux != sorted) {
                q.push(aux);
                distance[aux] = distance[actual] + 1;
            }
        }
    }

}

int SortExhaustive::GetSteps(const std::vector<int> &objective) {
    return distance[objective];
}

