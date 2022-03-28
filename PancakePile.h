//
// Created by dieguin on 27/3/22.
//

#ifndef PANCAKESORTING_PANCAKEPILE_H
#define PANCAKESORTING_PANCAKEPILE_H

#include "Headers.h"

class PancakePile {
private:
    std::vector<size_t> order_;
    size_t num_pancakes_;
    size_t SearchPancake(size_t pancake);
    void Flip(size_t init);
public:
    explicit PancakePile(size_t size);
    explicit PancakePile(const std::vector<size_t>& permutation);
    void Print();
    size_t SortInitial();
};


#endif //PANCAKESORTING_PANCAKEPILE_H
