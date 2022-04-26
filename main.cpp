#include "Headers.h"
#include "SortExhaustive.h"
#include "Sort3Approximation.h"
#include "Sort2Approximation.h"

int main() {
    int size, type;
    std::cin>>type>>size;
    SortPancakes* pancakes;
    if (type == 1) {
        pancakes = new SortExhaustive(size);
        std::cout<<pancakes->Sort()<<'\n';
    } else if (type == 2) {
        pancakes = new Sort3Approximation(size);
        std::cout<<pancakes->Sort()<<'\n';
    } else if (type == 3) {
        pancakes = new Sort2Approximation(size);
        std::cout<<pancakes->Sort()<<'\n';
    } else if (type == 4) {
        pancakes = new SortExhaustive(size);
        std::vector<int> original = pancakes->GetPermutation();
        std::cout<<pancakes->Sort()<<'\n';

        pancakes = new Sort3Approximation(original);
        std::cout<<pancakes->Sort()<<'\n';

        pancakes = new Sort2Approximation(original);
        pancakes->Print();
        std::cout<<pancakes->Sort()<<'\n';
    } else {
        std::cout<<"Invalid run\n";
        return 0;
    }

    return 0;
}
