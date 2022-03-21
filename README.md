# Pancake Sorting

_Pancake Sorting is scientifically known as Sorting by Prefix Reversal, but it called Pancake Sorting to give a meaning that has some implication in real life._

Let&#39;s imagine we have a stack of n pancakes, one on top of another, and they all have different sizes, for the purpose of the exercise, well assign an integer value to represent the size of each pancake.

Now let&#39;s picture a spatula, we can insert this spatula between two pancakes at any point of our stack, and flip all the pancakes that are on top of the spatula.

<p align="center">
  <img src="https://github.com/anguloramiresd/PancakeSorting/blob/main/pancakes.PNG" width="650" title="example">
</p>

A _pancake number_ is the minimum number of flips needed to sort a given number of pancakes, where a stack of sorted pancakes has the biggest pancake at the bottom of the stack, and every pancake above the bottom one is smaller than the pancake below.

It has been shown that for any stack of ___N___ pancakes, the minimum number of flips required to sort it lies between ___$\frac{15}{14}$N___ and ___$\frac{18}{11}$N___ flips, but there is not an exact formula yet.

There are simple algorithms, but inefficient for the purpose of the problem, these algorithms take ___2N - 3___ flips at most.

Pancake sort can be reduced from the NP-Hard problem 3-SAT, which implies that Pancake Sorting is also NP-Hard.


