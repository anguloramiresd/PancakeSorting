//
// Created by dieguin on 24-04-22.
//

#ifndef PANCAKESORTING_SORTEXHAUSTIVE_H
#define PANCAKESORTING_SORTEXHAUSTIVE_H

#include "SortPancakes.h"

class SortExhaustive {
private:
    size_t num_pancakes_;
    std::map<std::vector<int>, int> distance;
    std::vector<int> sorted;

    static void Flip(std::vector<int> &aux, int elements);

public:
    explicit SortExhaustive(int size);

    SortExhaustive(const SortExhaustive &other) = default;

    ~SortExhaustive() = default;

    void Sort();

    int GetSteps(const std::vector<int> &objective);
};


#endif //PANCAKESORTING_SORTEXHAUSTIVE_H
