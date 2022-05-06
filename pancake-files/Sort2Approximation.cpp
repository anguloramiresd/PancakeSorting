//
// Created by dieguin on 25-04-22.
//

#include "Sort2Approximation.h"

int Sort2Approximation::Sort() {
    std::vector<int> original = order_;
    std::vector<int> sorted = order_;
    std::sort(sorted.begin(), sorted.end());
    bool re_start = true;
    int j_left, j_right;

    while (re_start) {
        if (steps_ > 4 * num_pancakes_) {
            return -1;
        }
        re_start = false;
        if (CheckRedArcLeft(1)) {
            j_left = positions_[order_[1] - 1];
            j_right = positions_[order_[1] + 1];
            if (CheckType1(order_[1], order_[j_left])) {
//                std::cout<<"Type 1 "<<1<<" "<<j_left<<'\n';
                Flip(j_left - 1);
                re_start = true;
                continue;
            } else if (CheckType1(order_[1], order_[j_right])) {
//                std::cout<<"Type 1 "<<1<<" "<<j_right<<'\n';
                Flip(j_right - 1);
                re_start = true;
                continue;
            }
        }

        for (int i = 1; i <= num_pancakes_; ++i) {
            j_left = positions_[order_[i] - 1];
            j_right = positions_[order_[i] + 1];
            if (i < j_left && j_left != num_pancakes_ + 1 && CheckType2(order_[i], order_[j_left])) {
//                std::cout<<"Type 2 "<<i<<" "<<j_left<<'\n';
                Flip(j_left);
                Flip(j_left - i);
                re_start = true;
                continue;
            } else if (i < j_right && j_right != num_pancakes_ + 1 && CheckType2(order_[i], order_[j_right])) {
//                std::cout<<"Type 2 "<<i<<" "<<j_right<<'\n';
                Flip(j_right);
                Flip(j_right - i);
                re_start = true;
                continue;
            }
        }

        for (int i = 1; i <= num_pancakes_; ++i) {
            j_left = positions_[order_[i] - 1];
            j_right = positions_[order_[i] + 1];

            if (i < j_left && CheckType3(order_[i], order_[j_left])) {
//                std::cout<<"Type 3 "<<i<<" "<<j_left<<'\n';
                Flip(i);
                Flip(j_left - 1);
                re_start = true;
                continue;
            } else if (i < j_right && CheckType3(order_[i], order_[j_right])) {
//                std::cout<<"Type 3 "<<i<<" "<<j_right<<'\n';
                Flip(i);
                Flip(j_right - 1);
                re_start = true;
                continue;
            }
        }
    }

//    std::cout<<"Last step\n\n";
    /// Final step, Lemma 6
    if (order_ != sorted) {
        std::vector<int> lengths;
        int p_actual, p_previous = 0, upper;
        for(upper=num_pancakes_; upper >= 0; --upper){
            if(order_[upper] != upper)
                break;
        }
        for (int i = 1; i < upper;) {
            p_actual = order_[i];
            if(p_actual == 0 || p_actual > num_pancakes_){
                return -1;
            }
            lengths.push_back(p_actual - p_previous);
            p_previous = p_actual;
            i = p_actual + 1;
        }

        for (int i = 0; i < lengths.size(); ++i) {
            Flip(upper);
            Flip(upper - lengths[i]);
        }
    }

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