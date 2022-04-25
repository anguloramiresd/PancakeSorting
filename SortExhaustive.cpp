//
// Created by dieguin on 24-04-22.
//

#include "SortExhaustive.h"

void SortExhaustive::Flip(std::vector<int> &aux, int elements) {
    for (int i = 1; i <= elements / 2; ++i) {
        std::swap(aux[i], aux[elements - i + 1]);
    }
}

int SortExhaustive::Sort() {
    /// Uses a BFS to check all possible outcomes with minimal number of steps
    std::map<std::vector<int>, int> distance;
    std::queue<std::vector<int>> q;
    std::vector<int> actual, aux;
    distance[order_] = 0;
    q.push(order_);
    while (!q.empty()) {
        actual = q.front();
        q.pop();
        for (int i = 2; i <= num_pancakes_; ++i) {
            aux = actual;
            Flip(aux, i);
            if(distance[aux] == 0 && aux != order_){
                q.push(aux);
                distance[aux] = distance[actual] + 1;
            }
        }
    }
    std::sort(order_.begin(), order_.end());
    return distance[order_];
}
