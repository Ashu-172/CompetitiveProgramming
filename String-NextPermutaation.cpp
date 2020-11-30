/*////////////////////////////// Q61 : Babbar450:  Next Permutation //////////////////////////
Print the array of next permutation in a separate line.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100

Example:
Input:
1
6
1 2 3 6 5 4

Output:
1 2 4 3 5 6
//////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <algorithm>

using namespace std;
/*
1. from the end check for the index where input[i]>input[i-1],
    array from i-1 th index to end will give the next permutation, 
    we don't need to check elements brfore i-1.
    eg: input = [a c d b]
        here c < d,  i = 2 and  i-1 = 1

2. now we can see that array from index i to end is sorted in 
    desc order, means next permutation is not possible from
    index i to end index. 
    eg: array from index 2 to 3 is sorted in desc order.
        [d b] can not give next bigger permutation.

3. to get the next index we need to sort this remaining array in
    ascending order. now if we swap i-1 th element with just bigger 
    element in the array from index i to end, we'll have next permutation.
    eg: sort array from i to end => [a c b d]
        swap i-1 th element with just bigger element
            => [a d b c] (Next permutation)

// String version for Next Permutation is present in String-LexicographicallyKth.cpp file.
*/
void getNextPermutation(int input[], int size)
{
    int i = size - 1;
    // finding place where input[i]>input[i-1]
    while (input[i] <= input[i - 1] && i > 0)
        i--;

    // if already largest return same
    if (i == 0)
        return;

    // sorting from index i to end
    sort(input + i, input + size);

    // swapping i-1 th element with next bigger element
    for (int j = i; j < size; j++)
        if (input[i - 1] < input[j])
        {
            swap(input[i - 1], input[j]);
            return;
        }
}

int main()
{
    int input[] = {1, 2, 3, 6, 5, 4};
    int size = 6;
    getNextPermutation(input, size);
    for (int num : input)
        cout << num << " ";
}