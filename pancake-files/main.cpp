#include "Headers.h"
#include "SortExhaustive.h"
#include "Sort3Approximation.h"
#include "Sort2Approximation.h"

int main() {
    size_t max_size;
    std::cin >> max_size;
    std::vector<double> time_exhaustive(max_size + 1), time_approx3(max_size + 1, 0), time_approx2(max_size + 1, 0);
    SortExhaustive* sort_exhaustive;
    Sort3Approximation* sort_approx3;
    Sort2Approximation* sort_approx2;
    std::vector<double> ratio_approx3(max_size + 1, 0), ratio_approx2(max_size + 1, 0);
    for(size_t size = 1; size <= max_size; ++size){
        /// Run and timing
        auto start = std::chrono::high_resolution_clock::now();
        sort_exhaustive = new SortExhaustive(size);
        sort_exhaustive->Sort();
        auto ending = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> time_ms = ending - start;
        time_exhaustive[size] = time_ms.count();

        std::vector<int> list(size);
        for(size_t i = 0; i < size; ++i){
            list[i] = i + 1;
        }

        std::vector<int> sorted = list;
        size_t c_approx3 = 0, c_approx2 = 0, steps;
        do{
            /// 3 - Approximation
            /// Run, and timing
            c_approx3++;
            start = std::chrono::high_resolution_clock::now();
            sort_approx3 = new Sort3Approximation(list);
            steps = sort_approx3->Sort();
            ending = std::chrono::high_resolution_clock::now();
            time_ms = ending - start;
            time_approx3[size] += time_ms.count();

            /// Ratio adding
            ratio_approx3[size] += (double(std::max(steps, 1lu))/std::max(sort_exhaustive->GetSteps(list), 1));

            /// 2 - Approximation
            /// Run, and timing
            start = std::chrono::high_resolution_clock::now();
            sort_approx2 = new Sort2Approximation(list);
            steps = sort_approx2->Sort();
            ending = std::chrono::high_resolution_clock::now();
            time_ms = ending - start;

            /// Ratio adding
            if(sorted == sort_approx2->GetPermutation()) {
                c_approx2++;
                time_approx2[size] += time_ms.count();
                ratio_approx2[size] += (double(std::max(steps, 1lu)) / std::max(sort_exhaustive->GetSteps(list), 1));
            }
        }while(std::next_permutation(list.begin(), list.end()));
        time_approx2[size] /= double(c_approx2);
        time_approx3[size] /= double(c_approx3);
        ratio_approx2[size] /= double(c_approx2);
        ratio_approx3[size] /= double(c_approx3);
    }
    for(size_t i=1; i <= max_size;++i){
        std::cout<< time_exhaustive[i]<<" ";
    }
    std::cout<<'\n';
    for(size_t i=1; i <= max_size;++i){
        std::cout<< time_approx3[i]<<" ";
    }
    std::cout<<'\n';
    for(size_t i=1; i <= max_size;++i){
        std::cout<< time_approx2[i]<<" ";
    }
    std::cout<<'\n';
    for(size_t i=1; i <= max_size;++i){
        std::cout<< ratio_approx3[i]<<" ";
    }
    std::cout<<'\n';
    for(size_t i=1; i <= max_size;++i){
        std::cout<< ratio_approx2[i]<<" ";
    }
    std::cout<<'\n';
    return 0;
}
