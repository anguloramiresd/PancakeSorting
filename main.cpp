#include "Headers.h"
#include "SortExhaustive.h"
#include "Sort3Approximation.h"
#include "Sort2Approximation.h"

int main() {
    int size, type;
    std::cin>>type>>size;
    std::vector<int> original(size);
    SortPancakes* pancakes;
    if (type == 1) {
        for(size_t i =0; i < size; ++i) {
            std::cin >> original[i];
        }
    } else if (type == 2) {
        pancakes = new SortExhaustive(size);
        original = pancakes->GetPermutation();
    } else {
        std::cout<<"Invalid run\n";
        return 0;
    }

    pancakes = new SortExhaustive(original);
    pancakes->Print();
    std::cout<<pancakes->Sort()<<'\n';

    pancakes = new Sort3Approximation(original);
    std::cout<<pancakes->Sort()<<'\n';

    pancakes = new Sort2Approximation(original);
    std::cout<<pancakes->Sort()<<'\n';

    std::vector<int> sorted = original;
    std::sort(sorted.begin(), sorted.end());

    if (sorted != pancakes->GetPermutation()){
        std::cout<<"Fail\n";
    }
    return 0;
}
