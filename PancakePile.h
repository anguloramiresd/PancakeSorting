//
// Created by dieguin on 27/3/22.
//

#ifndef PANCAKESORTING_PANCAKEPILE_H
#define PANCAKESORTING_PANCAKEPILE_H

#include "Headers.h"

class PancakePile {
private:
    size_t steps;
    int Right(int val);
    int Left(int val);
    bool CheckType1(int val1, int val2);
    bool CheckType2(int val1, int val2);
    bool CheckType3(int val1, int val2);
    std::vector<int> order_;
    std::vector<int> positions_;
    int num_pancakes_;
    int SearchPancake(int pancake);
    void Flip(int elements);
    void Print(int pos_spatula);
    static void Flip(std::vector<int> &aux, int elements);
public:
    explicit PancakePile(int size);
    explicit PancakePile(const std::vector<int>& permutation);
    PancakePile(const PancakePile &other) = default;
    ~PancakePile() = default;
    void Print();
    size_t Sort_FirstAlgo();
    size_t Sort_SecondAlgo();
    size_t Sort_BruteForce();
};


#endif //PANCAKESORTING_PANCAKEPILE_H
