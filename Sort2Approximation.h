//
// Created by dieguin on 25-04-22.
//

#ifndef PANCAKESORTING_SORT2APPROXIMATION_H
#define PANCAKESORTING_SORT2APPROXIMATION_H

#include "SortPancakes.h"

class Sort2Approximation : public SortPancakes {
private:
    int LeftPancake(int pancake);
    int RightPancake(int pancake);
    bool CheckType1(int pancake1, int pancake2);
    bool CheckType2(int pancake1, int pancake2);
    bool CheckType3(int pancake1, int pancake2);
public:
    using SortPancakes::SortPancakes;
    int Sort() override;
};


#endif //PANCAKESORTING_SORT2APPROXIMATION_H
