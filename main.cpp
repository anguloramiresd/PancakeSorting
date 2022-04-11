#include "Headers.h"
#include "PancakePile.h"

int main() {
    size_t steps;
    PancakePile pancakes(6);
    PancakePile pancakes2(pancakes);
    PancakePile pancakes3(pancakes);
    pancakes.Print();
    std::cout<<"Correct sol: \n";
    steps = pancakes.Sort_BruteForce();
    std::cout<<"Steps: "<<steps<<'\n';
    pancakes.Print();

    std::cout<<"\nFirst sol: \n";
    pancakes2.Print();
    steps = pancakes2.Sort_FirstAlgo();
    std::cout<<"Steps: "<<steps<<'\n';
    pancakes2.Print();

    std::cout<<"\nSecond sol: \n";
    pancakes3.Print();
    steps = pancakes3.Sort_SecondAlgo();
    std::cout<<"Steps: "<<steps<<'\n';
    pancakes3.Print();
    return 0;
}
