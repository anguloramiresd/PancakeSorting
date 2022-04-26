//
// Created by dieguin on 25-04-22.
//

#include "Sort2Approximation.h"

int Sort2Approximation::Sort() {
    bool re_start = true;

    while (re_start) {
        if(steps_ >= 4*num_pancakes_){
            return -1;
        }
        re_start = false;
        for(int position = 0; position <= num_pancakes_ + 1; ++position){
            /// Good edge of type 1
            if(position == 1 && CheckRedArcLeft(position)){
                if(CheckType1(order_[position], order_[position] + 1)){
                    Flip(positions_[order_[position] + 1] - 1);
                    re_start = true;
                }
                if(CheckType1(order_[position], order_[position] - 1)) {
                    Flip(positions_[order_[position] - 1] - 1);
                    re_start = true;
                }
            }
            /// Good edge of type 2
            if(position != 0 && CheckRedArcRight(position)){
                if(CheckType2(order_[position], order_[position] + 1)){
                    int j = positions_[order_[position] + 1];
                    Flip(j);
                    Flip(j - position);
                    re_start = true;
                }
                if(CheckType2(order_[position], order_[position] - 1)) {
                    int j = positions_[order_[position] - 1];
                    Flip(j);
                    Flip(j - position);
                    re_start = true;
                }
            }
            /// Good edge of type 3
            if(CheckRedArcRight(position)){
                if(CheckType3(order_[position], order_[position] + 1)){
                    int j = positions_[order_[position] + 1];
                    Flip(position);
                    Flip(j - 1);
                    re_start = true;
                }
                if(CheckType3(order_[position], order_[position] - 1)) {
                    int j = positions_[order_[position] - 1];
                    Flip(position);
                    Flip(j - 1);
                    re_start = true;
                }
            }
        }
    }

    /*//Final step, Lemma 6
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
    }*/

    return steps_;
}

int Sort2Approximation::LeftPancake(int pancake) const {
    return order_[positions_[pancake] - 1];
}

int Sort2Approximation::RightPancake(int pancake) const {
    return order_[positions_[pancake] + 1];
}

bool Sort2Approximation::CheckType1(int pancake1, int pancake2) const {
    return CheckRedArcLeft(positions_[pancake1]) && CheckRedArcLeft(positions_[pancake2]);
}

bool Sort2Approximation::CheckType2(int pancake1, int pancake2) const {
    return CheckRedArcRight(positions_[pancake1]) && CheckRedArcRight(positions_[pancake2]);
}

bool Sort2Approximation::CheckType3(int pancake1, int pancake2) const {
    return CheckRedArcRight(positions_[pancake1]) && CheckRedArcLeft(positions_[pancake2]);
}

bool Sort2Approximation::CheckRedArcLeft(int position) const {
    return position > 0 && abs(order_[position - 1] - order_[position]) != 1;
}

bool Sort2Approximation::CheckRedArcRight(int position) const {
    return position <= num_pancakes_ && abs(order_[position] - order_[position + 1]) != 1;
}