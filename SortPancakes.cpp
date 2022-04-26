//
// Created by dieguin on 24-04-22.
//

#include "SortPancakes.h"

SortPancakes::SortPancakes(int size) : num_pancakes_(size) {
    /// We initialize the size of each pancake, from 1 to size
    /// We add two extra values, for purpose of the algorithm
    order_.resize(size + 2);
    positions_.resize(size + 2);
    for (int i = 0; i <= num_pancakes_ + 1; ++i) {
        order_[i] = i;
    }

    /// Here we create a random permutation of pancakes
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order_.begin() + 1, order_.end() - 1, g);

    /// Initialize positions vector
    for (int i = 0; i <= num_pancakes_ + 1; ++i) {
        positions_[order_[i]] = i;
    }
}

SortPancakes::SortPancakes(const std::vector<int> &permutation) {
    num_pancakes_ = permutation.size();
    order_.resize(permutation.size() + 2);
    order_[0] = 0;
    order_[num_pancakes_ + 1] = num_pancakes_ + 1;
    for (int i = 0; i < permutation.size(); ++i) {
        order_[i + 1] = permutation[i];
    }

    positions_.resize(num_pancakes_ + 2);
    for (int i = 0; i <= num_pancakes_; ++i) {
        positions_[order_[i]] = i;
    }
}

int SortPancakes::SearchPancake(int pancake) const {
    return positions_[pancake];
}

void SortPancakes::Flip(int elements) {
    if (elements <= 1)
        return;
    steps_++;
    Print(elements);
    for (int i = 1; i <= elements / 2; ++i) {
        std::swap(order_[i], order_[elements - i + 1]);
        positions_[order_[i]] = i;
        positions_[order_[elements - i + 1]] = elements - i + 1;
    }
}

void SortPancakes::Print(int pos_spatula) const {
    /// Prints the stack of pancakes and the position in which the spatula is in
    for (int i = 1; i < order_.size() - 1; ++i) {
        std::cout << order_[i] << " ";
        if (i == pos_spatula)
            std::cout << "| ";
    }
    std::cout << '\n';
}

void SortPancakes::Print() const {
    /// Spatula will never be printed
    Print(num_pancakes_ + 2);
}

std::vector<int> SortPancakes::GetPermutation() const {
    std::vector<int> permutation(num_pancakes_);
    for(size_t i = 1; i <= num_pancakes_; ++i){
        permutation[i - 1] = order_[i];
    }
    return permutation;
}

