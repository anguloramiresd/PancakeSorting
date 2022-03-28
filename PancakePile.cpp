//
// Created by dieguin on 27/3/22.
//

#include "PancakePile.h"

PancakePile::PancakePile(size_t size) : num_pancakes_(size){
    //We initialize the size of each pancake, from 1 to size
    order_.resize(size);
    for(size_t i = 0; i < order_.size(); ++i){
        order_[i] = i + 1;
    }

    //Random permutation of pancakes
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order_.begin(), order_.end(), g);
}

void PancakePile::Print() {
    for(auto i : order_)
        std::cout << i << ' ';
    std::cout << '\n';
}

size_t PancakePile::SortInitial() {
    size_t pos_pancake, steps = 0;

    for(size_t i = 1; i <= num_pancakes_; ++i){
        Print();
        pos_pancake = SearchPancake(i);
        if(pos_pancake == i - 1) continue;

        if(pos_pancake != num_pancakes_ - 1) {
            Flip(pos_pancake);
            steps++;
        }

        Flip(i - 1);
        steps++;
    }

    return steps;
}

void PancakePile::Flip(size_t init) {
    std::reverse(order_.begin() + init, order_.end());
}

size_t PancakePile::SearchPancake(size_t pancake) {
    for(size_t i =0; i < num_pancakes_; ++i)
        if(order_[i] == pancake) return i;
}

PancakePile::PancakePile(const std::vector<size_t>& permutation) {
    num_pancakes_ = permutation.size();
    order_ = permutation;
}
