//
// Created by dieguin on 24-04-22.
//

#ifndef PANCAKESORTING_SORTPANCAKES_H
#define PANCAKESORTING_SORTPANCAKES_H

#include "Headers.h"

class SortPancakes {
protected:
    int steps_ = 0;
    size_t num_pancakes_;
    std::vector<int> order_;
    std::vector<int> positions_;

    int SearchPancake(int pancake) const;
    void Flip(int elements);
    void Print(int pos_spatula) const;

public:
    explicit SortPancakes(int size);
    explicit SortPancakes(const std::vector<int>& permutation);
    SortPancakes(const SortPancakes &other) = default;
    ~SortPancakes() = default;
    void Print() const;
    virtual int Sort() = 0;
};


#endif //PANCAKESORTING_SORTPANCAKES_H
