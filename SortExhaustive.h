//
// Created by dieguin on 24-04-22.
//

#ifndef PANCAKESORTING_SORTEXHAUSTIVE_H
#define PANCAKESORTING_SORTEXHAUSTIVE_H

#include "SortPancakes.h"

class SortExhaustive : public SortPancakes {
private:
    static void Flip(std::vector<int> &aux, int elements);
public:
    using SortPancakes::SortPancakes;
    int Sort() override;
};


#endif //PANCAKESORTING_SORTEXHAUSTIVE_H
