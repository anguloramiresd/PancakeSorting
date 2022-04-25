//
// Created by dieguin on 25-04-22.
//

#include "Sort3Approximation.h"

int Sort3Approximation::Sort() {
    int pos_pancake;
    steps_ = 0;

    for (int i = num_pancakes_; i >= 1; --i) {
        pos_pancake = SearchPancake(i);
        if (pos_pancake == i) continue;

        if (pos_pancake > 1) {
            Flip(pos_pancake);
            steps_++;
        }

        Flip(i);
        steps_++;
    }

    return steps_;
}
