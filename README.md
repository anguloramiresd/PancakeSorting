# Pancake Sorting

_Pancake Sorting is scientifically known as Sorting by Prefix Reversal, but we will call it Pancake Sorting to give a meaning that has some curious implication in real life._

Let&#39;s imagine we have a stack of n pancakes, one on top of another, and they all have different sizes, for the purpose of the exercise, well assign an integer value to represent the size of each pancake.

Now let&#39;s picture a spatula, we can insert this spatula between two pancakes at any point of our stack, and flip all the pancakes that are on top of the spatula.

<p align="center">
  <img src="https://github.com/anguloramiresd/PancakeSorting/blob/main/pancakes.PNG" width="650" title="example">
</p>

A _pancake number_ is the minimum number of flips needed to sort a given number of pancakes, where a stack of sorted pancakes has the biggest pancake at the bottom of the stack, and every pancake above the bottom one is smaller than the pancake below.

It has been shown that for any stack of ___N___ pancakes, the minimum number of flips required to sort it lies between ___1.0714 N___ and ___1.6364 N___ flips, but there is not an exact formula yet.

[Lower Bound paper](https://www.sciencedirect.com/science/article/pii/0012365X79900682?via%3Dihub)
[Upper Bound paper](https://www.sciencedirect.com/science/article/pii/S0304397508003575?via%3Dihub)

There are numerous ways to represent this problem on a computer, including graphs, permutations, strings and lists. We will try to take as many approaches as possible during the development of this project.

# Algorithms

### Inefficient in number of flips, but uses linear time.
There are simple algorithms, but inefficient for the purpose of the problem.
1. Pick the biggest pancake not sorted yet, put the spatula right under this pancake.
2. Flip
3. Now that the biggest pancake not sorted yet is on top, put the spatula right above the smallest sorted pancake.
4. Flip
5. Repeat step 1 until all the pancakes are sorted.

We can prove by induction that in the worst case, this method will take at most ___2N - 3___ flips.

### Inefficient in time, but efficient in result.
We can as well test all possible outcome, doing a ridiculous recursion.
1. Put the spatula under the i-th pancake(i = 1, ..., n) (Yes, we test for every pancake)
2. Flip
3. This is now our new pile of pancakes, if it's sorted we stop.
4. Repeat recursiom

This will create a recursion that will surely find a result as it's searching for all possible scenario, but it's really innefficient in time and memory, as it will in the worst of the cases find all the n! permutations and the steps that it takes to get to each of them.

### Efficient in time, efficient in result?
Well this is tricky, there are a couple of algorithms that can approximate the result of optimal pancake sorting, but they can only approximate, we can't know if they have the exact result.
        
[Algorithms possibly used](https://reader.elsevier.com/reader/sd/pii/S1570866715000507?token=E25638B271D911428C086B8074D0A12FAFB54738FF8FAA2636033D3851A855879B2647E0B334D13B3A04E71A5B43E4A8&originRegion=eu-west-1&originCreation=20220321165136)

# Proof Pancake sorting is NP-Hard
Pancake sort can be reduced from the NP-Hard problem 3-SAT, which implies that Pancake Sorting is also NP-Hard.
We can see the proof of such assertion in the following [paper](https://arxiv.org/abs/1111.0434v1).

# Practical Applications
There are some interesting practical purposes for this problem - in comparative genomics, or parallel processor networks, in which it can provide an effective routing algorithm between processors.

    But who needs practical uses of Sorting by Prefix Reversal when we can simply be hungry for sorted pancakes?


<p align="center">
  <img src="https://img.favpng.com/1/4/22/pancake-breakfast-english-muffin-waffle-bacon-png-favpng-svq3yuXZXUZwZ4jyTR3seYrfE_t.jpg" width="350" title="pancakes">
</p>



