/*/////////////////////////// Q 58: Babbar450:  Print all Permutations ///////////////////////////
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
/////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void rotate(string &input)
{
    int size = input.size();
    if (size <= 1)
        return;

    char temp = input[0];
    for (int i = 0; i < size - 1; i++)
        input[i] = input[i + 1];
    input[size - 1] = temp;
}
/////////////////// Solution 1 (Recursion) //////////////////
/*
1. if we rotate the string n-1 times we'll have n permutations
input = ABC 
permutations = ABC CAB BAC

2. Now for each rotation if we fix first char and repeat 
    step 1 for remaing part of string we'll have 2 permutations 
    for each of the above result
    permutations(ABC): A + {BC, CB} = ABC ACB
    permutations(CAB): C + {AB, BA} = CAB CBA
    permutations(BAC): B + {AC, CA} = BAC BCA

3. Now for each of the rotation we'll repeat step 2.
4. when input is empty, we've all 3 or n chars fixed
    we can print them
*/
void printPermutations(string input, string prefix)
{
    //when whole input is processed
    if (input == "")
    {
        cout << prefix << " ";
        return;
    }

    int count = input.size();
    //for all rotations of current input
    while (count--)
    {
        printPermutations(input.substr(1), prefix + input[0]);
        if (count > 0)
        { //library rotate function
            rotate(input.begin(), input.begin() + 1, input.end());
            //rotate(input);
        }
    }
}

///////////////////// Solution 2 (Back Tracking) //////////////////
/*
in this aapproach we'll swap first char of the string with 
    rest of the characters one by one.
for each of the string we'll fix first char and repeat above
    step for rest of the string.
since we have swapped first char, after calling function for
    smaller input, we've to backtrack to previous string by 
    swapping again so that in next iteration we can swap first
    chat with next one.

we can understand it by following example:
input = "abc"
                       abc
                    /   |   \
                abc    bac   cba
               /  \    /  \    |  \
            abc  acb  bac bca  cba cab
*/
void permutation(string input, int start, int size)
{
    if (start == size)
        cout << input << " ";

    for (int i = start; i < size; i++)
    {
        swap(input[start], input[i]);
        permutation(input, start + 1, size);
        swap(input[start], input[i]);
    }
}
/////////////////////// Solution 3 //////////////////////
void printLexographically(string input)
{
    //sort the string to get smallest permutation
    sort(input.begin(), input.end());
    cout << input << " ";
    //printing next permutations untill fun return false
    //when there is no more lexographical next permutations possible
    while (next_permutation(input.begin(), input.end()))
        cout << input << " ";
}

int main()
{
    string input = "ABC";

    printPermutations(input, "");
    cout << endl;
    permutation(input, 0, input.size());
    cout << endl;
    printLexographically(input);
}