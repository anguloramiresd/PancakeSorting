//
// Created by dieguin on 27/3/22.
//

#include "PancakePile.h"

PancakePile::PancakePile(int size) : num_pancakes_(size) {
    //We initialize the size of each pancake, from 1 to size
    order_.resize(size + 2);
    positions_.resize(size + 2);
    order_[0] = 0;
    order_[size + 1] = size + 1;
    for (size_t i = 1; i <= num_pancakes_; ++i) {
        order_[i] = i;
    }

    //Random permutation of pancakes
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order_.begin() + 1, order_.end() - 1, g);

    for (size_t i = 1; i <= num_pancakes_; ++i) {
        positions_[order_[i]] = i;
    }
    positions_[0] = 0;
    positions_[num_pancakes_ + 1] = num_pancakes_ + 1;
}

PancakePile::PancakePile(const std::vector<int> &permutation) {
    num_pancakes_ = int(permutation.size());
    order_.resize(permutation.size() + 2);
    order_[0] = 0;
    order_[num_pancakes_ + 1] = int(num_pancakes_) + 1;
    for (size_t i = 0; i < permutation.size(); ++i) {
        order_[i + 1] = permutation[i];
    }

    positions_.resize(num_pancakes_ + 2);
    for (size_t i = 1; i <= num_pancakes_; ++i) {
        positions_[order_[i]] = i;
    }
    positions_[0] = 0;
    positions_[num_pancakes_ + 1] = num_pancakes_ + 1;
}

void PancakePile::Print(int pos_spatula) {
    //Prints the stack of pancakes and the position in which the spatula is in
    for (int i = 0; i < order_.size(); ++i) {
        std::cout << order_[i] << " ";
        if (i == pos_spatula)
            std::cout << "| ";
    }
    std::cout << "\n";
}

void PancakePile::Print() {
    Print(order_.size() + 1); //So it never prints a spatula
}

void PancakePile::Flip(std::vector<int> &aux, int elements) {
    for (int i = 1; i <= elements / 2; ++i) {
        std::swap(aux[i], aux[elements - i + 1]);
    }
}

void PancakePile::Flip(int elements) {
    if (elements <= 1)
        return;
    steps++;
    Print(elements);
    for (int i = 1; i <= elements / 2; ++i) {
        std::swap(order_[i], order_[elements - i + 1]);
        positions_[order_[i]] = i;
        positions_[order_[elements - i + 1]] = elements - i + 1;
    }
}

int PancakePile::SearchPancake(int pancake) {
    for (int i = 1; i <= num_pancakes_; ++i)
        if (order_[i] == pancake) return i;
}

size_t PancakePile::Sort_FirstAlgo() {
    int pos_pancake;
    steps = 0;

    for (int i = num_pancakes_; i >= 1; --i) {
        pos_pancake = SearchPancake(i);
        if (pos_pancake == i) continue;

        if (pos_pancake > 1) {
            Flip(pos_pancake);
            steps++;
        }

        Flip(i);
        steps++;
    }

    return steps;
}

size_t PancakePile::Sort_SecondAlgo() {
    bool re_start = true;
    steps = 0;

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
    for (size_t i = 1; i <= num_pancakes_;) {
        p_actual = order_[i];
        lengths.push_back(p_actual - p_previous);
        p_previous = p_actual;
        i = p_actual + 1;
    }

    for (size_t i = 0; i < lengths.size(); ++i) {
        Flip(num_pancakes_);
        Flip(num_pancakes_ - lengths[i]);
    }

    return steps;
}

int PancakePile::Left(int val) {
    return order_[positions_[val] - 1];
}

int PancakePile::Right(int val) {
    return order_[positions_[val] + 1];
}

bool PancakePile::CheckType1(int val1, int val2) {
    if (positions_[val1] > positions_[val2])
        std::swap(val1, val2);
    return (abs(Left(val1) - val1) != 1 && abs(Left(val2) - val2) != 1);
}

bool PancakePile::CheckType2(int val1, int val2) {
    if (positions_[val1] > positions_[val2])
        std::swap(val1, val2);
    return (abs(Right(val1) - val1) != 1 && abs(Right(val2) - val2) != 1);
}

bool PancakePile::CheckType3(int val1, int val2) {
    if (positions_[val1] > positions_[val2])
        std::swap(val1, val2);
    return (abs(Right(val1) - val1) != 1 && abs(Left(val2) - val2) != 1);
}

size_t PancakePile::Sort_BruteForce() {
    //Uses a BFS to check all possible outcomes with minimal number of steps
    std::map<std::vector<int>, int> distance;
    std::queue<std::vector<int>> q;
    std::vector<int> actual, aux;
    distance[order_] = 0;
    q.push(order_);
    while (!q.empty()) {
        actual = q.front();
        q.pop();
        for (int i = 2; i <= num_pancakes_; ++i) {
            aux = actual;
            Flip(aux, i);
            if(distance[aux] == 0 && aux != order_){
                q.push(aux);
                distance[aux] = distance[actual] + 1;
            }
        }
    }
    std::sort(order_.begin(), order_.end());
    return distance[order_];
}
