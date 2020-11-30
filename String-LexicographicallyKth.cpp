/*/////////////////////////// Q 60: Babbar450:  Print Lexicographically Kth Permutation ///////////////////////////
/*Given a string of length m containing lowercase alphabets only. You have to find the n-th permutation of string lexicographically.

Examples:

Input : str[] = "abc", n = 3
Output : Result = "bac"
Explanation : All possible permutation in
sorted order: abc, acb, bac, bca, cab, cba

Input : str[] = "aba", n = 2
Output : Result = "aba"
Explanation : All possible permutation
in sorted order: aab, aba, baa
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

///////////////////////// Solution 1: STL Based solution ///////////////
string getKthPermutation(string &input, int k)
{

#if 0 //if we want kth permutation from current string
    while (--k)
        next_permutation(input.begin(), input.end());
    return input;
#else
    // finding kth permutation from lexicographically smallest permutation
    sort(input.begin(), input.end());
    while (--k)
    {
        next_permutation(input.begin(), input.end());
        //cout << input << "   ";
    }
    return input;
#endif
}

//////////////////////// Solution 2 ////////////////////////

void getNextPermutation(string &input)
{
    int size = input.size();
    int i = size - 1;
    // finding place where input[i]>input[i-1]
    while (input[i] <= input[i - 1] && i > 0)
        i--;

    // if already largest return same
    if (i == 0)
        return;

    // sorting from index i to end
    sort(input.begin() + i, input.end());

    // swapping i-1 th element with next bigger element
    for (int j = i; j < size; j++)
        if (input[i - 1] < input[j])
        {
            swap(input[i - 1], input[j]);
            return;
        }
}

string printKthPermutation(string &input, int k)
{
    // finding kth permutation from lexicographically smallest permutation
    sort(input.begin(), input.end());
    while (--k)
    {
        getNextPermutation(input);
        //cout << input << "   ";
    }
    return input;
}

int main()
{
    string input = "GEEKSFORGEEKS";
    int k = 10;
    cout << getKthPermutation(input, k) << endl;
    cout << printKthPermutation(input, k) << endl;
}