#include "Headers.h"
#include "PancakePile.h"

int main() {
    PancakePile pancakes(4);
    size_t steps = pancakes.Sort_FirstAlgo();
    std::cout<<'\n';
    pancakes.Print();
    std::cout << steps << '\n';

    std::vector<int> aux(9);
    aux = {8, 2, 1, 9, 5, 6, 3, 4, 7};
    PancakePile pancakes_2(aux);
    steps = pancakes_2.Sort_SecondAlgo();
    std::cout<<'\n';
    pancakes_2.Print();
    std::cout << steps << '\n';

    PancakePile pancakes_3(10);
    steps = pancakes_3.Sort_SecondAlgo();
    std::cout<<'\n';
    pancakes_3.Print();
    std::cout << steps << '\n';
    return 0;
}
