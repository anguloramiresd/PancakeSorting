//
// Created by dieguin on 07-05-22.
//

#include "gtest/gtest.h"
#include "./../pancake-files/Headers.h"
#include "./../pancake-files/Sort3Approximation.h"
#include "./../pancake-files/SortExhaustive.h"

TEST(ThreeApproximation, Individual_test){
    auto *ap = new Sort3Approximation(7);
    auto *exh = new SortExhaustive(7);
    exh->Sort();
    std::vector<int> aux = ap->GetPermutation();
    EXPECT_GE(exh->GetSteps(aux)*7, ap->Sort());
}

TEST(ThreeApproximation, ExhaustiveTesting){
    size_t max_size = 8;
    SortExhaustive* sort_exhaustive;
    Sort3Approximation* sort_approx;
    for(size_t size = 1; size <= max_size; ++size){
        sort_exhaustive = new SortExhaustive(size);
        sort_exhaustive->Sort();

        std::vector<int> list(size);
        for(size_t i = 0; i < size; ++i){
            list[i] = i + 1;
        }

        std::vector<int> sorted = list;
        size_t steps;
        do{
            sort_approx = new Sort3Approximation(list);
            steps = sort_approx->Sort();
            ASSERT_EQ(sorted, sort_approx->GetPermutation());
            EXPECT_LE(steps, size * sort_exhaustive->GetSteps(list))<<size;
        }while(std::next_permutation(list.begin(), list.end()));
    }
}