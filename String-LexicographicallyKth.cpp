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

///////////////////////// STL Based solution ///////////////
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
        next_permutation(input.begin(), input.end());
    return input;
#endif
}

int main()
{
    string input = "GEEKSFORGEEKS";
    int k = 100;
    cout << getKthPermutation(input, k) << endl;
}