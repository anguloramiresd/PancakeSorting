#include "Headers.h"
#include "PancakePile.h"

int main() {
    PancakePile pancakes(4);
    size_t steps = pancakes.SortInitial();
    std::cout<<'\n';
    pancakes.Print();
    std::cout << steps << '\n';
    return 0;
}
