/*////////////////////////////////// Q 273: Babbar450: Find Kth Permutation of n Natural Numbers ///////////////////////////////////
Given two integers N and K, find the Kth permutation sequence of numbers from 1 to N without using STL function.
Note: Assume that the inputs are such that Kth permutation of N number is always possible.

Examples: 

Input: N = 3, K = 4 
Output: 231 
Explanation: 
The ordered list of permutation sequence from integer 1 to 3 is : 123, 132, 213, 231, 312, 321. So, the 4th permutation sequence is “231”.

Input: N = 2, K = 1 
Output: 12 
Explanation: 
For n = 2, only 2 permutations are possible 12 21. So, the 1st permutation sequence is “12”. 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

///////////////////////////////////////////////////////////// Solution 1 ///////////////////////////////////////////////////////////
bool findKthPermutation(string &input, int &k, int index)
{
    if (index == input.size())
    {
        k--;
        if (k == 0)
        {
            return true;
        }
        return false;
    }

    for (int i = index; i < input.size(); i++)
    {
        swap(input[index], input[i]);
        if (true == findKthPermutation(input, k, index + 1))
            return true;
        swap(input[index], input[i]);
    }
    return false;
}

/////////////////////////////////////////////////// Solution 2 //////////////////////////////////////////////////////
/*
If we generate all the permutations for n=3 then it will be as:
    123
    132
    213
    231
    312
    321

Here we can observe that there is a pattern in the permutations. from all three digits every digit came at first place exactly two times continuously. we can use this pattern and fill the places in the resulting permutations. there will be n places in the output string.
to find out which number will come at first place from set {1 2 3}, we have following points.
1.  since there are total !n permutations so every number will come at first place exactly !n/n times which is !(n-1) times continuously.
    which means for k is 1 and 2, number present at 0th index in the set which is 1 will come at first place, for k=3 and 4, numbet present at index 1 in the set which is 2 will come at first place and similarly for k=5 and 6, at first place 3 will come.

2.  now to calculate the index of the number which will come at first place, we need to calculate x = (k-1)/p where p is calculated in above step 
    as p = !(n-1). here x is the index, so we need to ensure that it is in the range of elements in the set i.e. 0 <= x < n.

3. xth element in the set will be the number which will be placed at first place in the resulting permutation string. we can push it in the resulting string and remove this number from the input set, since it can not be repeated in permutation. 

4. we can repeat above steps recursively for the smaller set until it became empty. in the end we'll have the kth permutation in output string.

Time complexity for this solution will be O(n) since there are n level of recursion and in each level we are calculating the correct digit to be inserted in the output string, so there is only one branch in the recursion tree.
*/
void KthPermutation(vector<int> &input, int k, string &output)
{
    if (input.empty())
        return;

    int n = input.size();
    long N = 1;
    for (int i = 1; i < n; i++)
        N *= i;

    int index = (k - 1) / N;
    index = index % n;

    output.append(to_string(input[index]));
    input.erase(input.begin() + index);

    KthPermutation(input, k, output);
}

void findKthPermutations2(int n, int k, string &output)
{
    vector<int> input;
    for (int i = 1; i <= n; i++)
        input.push_back(i);

    KthPermutation(input, k, output);
}

/////////////////////////////////////////////////////// Solution 3 //////////////////////////////////////////////////
/*
Reference : https://www.youtube.com/watch?v=W9SIlE2jhBQ
*/

int main()
{
    int n, k;
    cin >> n >> k;

    string input = "";
    for (int i = 1; i <= n; i++)
    {
        input += to_string(i);
    }
    cout << input << endl;
    string output = "";

    /*
    int index = 0;
    findKthPermutation(input, k, index);
    cout << input << endl;
    */
    findKthPermutations2(n, k, output);
    cout << output << endl;
}