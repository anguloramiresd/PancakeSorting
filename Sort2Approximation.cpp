//
// Created by dieguin on 25-04-22.
//

#include "Sort2Approximation.h"

int Sort2Approximation::Sort() {
    bool re_start = true;

    while (re_start) {
        re_start = false;
        //Check blue arc of type 1 with i = 1
        if (CheckType1(order_[1], order_[1] - 1)) {
            Flip(positions_[order_[1] - 1] - 1);
            re_start = true;
        } else if (CheckType1(order_[1], order_[1] + 1)) {
            Flip(positions_[order_[1] + 1] - 1);
            re_start = true;
        }
        if (re_start)continue;
        for (int i = 1; i < num_pancakes_; ++i) {
            if (CheckType2(i, i + 1)) {
                int pos1, pos2;
                pos1 = std::min(positions_[i], positions_[i + 1]);
                pos2 = std::max(positions_[i], positions_[i + 1]);
                Flip(pos2);
                Flip(pos2 - pos1);
                re_start = true;
                break;
            }
        }
        if (re_start)continue;
        for (int i = 0; i <= num_pancakes_; ++i) {
            if (CheckType3(i, i + 1)) {
                int pos1, pos2;
                pos1 = std::min(positions_[i], positions_[i + 1]);
                pos2 = std::max(positions_[i], positions_[i + 1]);
                Flip(pos1);
                Flip(pos2 - 1);
                re_start = true;
                break;
            }
        }
    }
    std::cout << "Final Sorting\n";
    Print();

    //Final step, Lemma 6
    std::vector<int> lengths;
    int p_actual, p_previous = 0;
    for (int i = 1; i <= num_pancakes_;) {
        p_actual = order_[i];
        lengths.push_back(p_actual - p_previous);
        p_previous = p_actual;
        i = p_actual + 1;
    }

    for (int i = 0; i < lengths.size(); ++i) {
        Flip(num_pancakes_);
        Flip(num_pancakes_ - lengths[i]);
    }

    return steps_;
}

int Sort2Approximation::LeftPancake(int pancake) {
    return order_[positions_[pancake] - 1];
}

int Sort2Approximation::RightPancake(int pancake) {
    return order_[positions_[pancake] + 1];
}

bool Sort2Approximation::CheckType1(int pancake1, int pancake2) {
    if (positions_[pancake1] > positions_[pancake2])
        std::swap(pancake1, pancake2);
    return (abs(LeftPancake(pancake1) - pancake1) != 1 && abs(LeftPancake(pancake2) - pancake2) != 1);
}

bool Sort2Approximation::CheckType2(int pancake1, int pancake2) {
    if (positions_[pancake1] > positions_[pancake2])
        std::swap(pancake1, pancake2);
    return (abs(RightPancake(pancake1) - pancake1) != 1 && abs(RightPancake(pancake2) - pancake2) != 1);
}

bool Sort2Approximation::CheckType3(int pancake1, int pancake2) {
    if (positions_[pancake1] > positions_[pancake2])
        std::swap(pancake1, pancake2);
    return (abs(RightPancake(pancake1) - pancake1) != 1 && abs(LeftPancake(pancake2) - pancake2) != 1);
}
