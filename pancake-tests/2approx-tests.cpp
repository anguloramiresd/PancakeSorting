//
// Created by dieguin on 06-05-22.
//

#include "gtest/gtest.h"
#include "../pancake-files/include/Headers.h"
#include "../pancake-files/include/Sort2Approximation.h"
#include "../pancake-files/include/SortExhaustive.h"

TEST(TwoApproximation, Individual_test) {
    auto *ap = new Sort2Approximation(7);
    auto *exh = new SortExhaustive(7);
    exh->Sort();
    std::vector<int> aux = ap->GetPermutation();
    EXPECT_GE(exh->GetSteps(aux) * 2, ap->Sort());
}

TEST(TwoApproximation, ExhaustiveTesting) {
    size_t max_size = 8;
    SortExhaustive *sort_exhaustive;
    Sort2Approximation *sort_approx;
    for (size_t size = 1; size <= max_size; ++size) {
        sort_exhaustive = new SortExhaustive(size);
        sort_exhaustive->Sort();

        std::vector<int> list(size);
        for (size_t i = 0; i < size; ++i) {
            list[i] = i + 1;
        }

        std::vector<int> sorted = list;
        size_t steps;
        do {
            sort_approx = new Sort2Approximation(list);
            steps = sort_approx->Sort();
            ASSERT_EQ(sorted, sort_approx->GetPermutation());
            EXPECT_LE(steps, 2 * sort_exhaustive->GetSteps(list));
        } while (std::next_permutation(list.begin(), list.end()));
    }
}