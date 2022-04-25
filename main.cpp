#include "Headers.h"
#include "SortExhaustive.h"
#include "Sort3Approximation.h"
#include "Sort2Approximation.h"

int main(int argc, char* argv[]) {
    SortExhaustive pancake_pile(7);
    Sort3Approximation pancake_pile2(7);
    Sort2Approximation pancake_pile3(7);
    pancake_pile.Print();
    
    std::cout<<pancake_pile.Sort()<<'\n';
    pancake_pile2.Print();
    std::cout<<pancake_pile2.Sort()<<'\n';
    pancake_pile3.Print();
    std::cout<<pancake_pile3.Sort()<<'\n';
    return 0;
}
