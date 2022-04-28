//
// Created by dieguin on 25-04-22.
//

#ifndef PANCAKESORTING_SORT2APPROXIMATION_H
#define PANCAKESORTING_SORT2APPROXIMATION_H

#include "SortPancakes.h"

class Sort2Approximation : public SortPancakes {
private:
    int LeftPancake(int pancake) const;

    int RightPancake(int pancake) const;

    bool CheckType1(int pancake1, int pancake2) const;

    bool CheckType2(int pancake1, int pancake2) const;

    bool CheckType3(int pancake1, int pancake2) const;

    bool CheckRedArcLeft(int position) const;

    bool CheckRedArcRight(int position) const;

public:
    using SortPancakes::SortPancakes;

    int Sort() override;
};


#endif //PANCAKESORTING_SORT2APPROXIMATION_H
