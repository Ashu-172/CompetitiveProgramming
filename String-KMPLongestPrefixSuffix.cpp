/*/////////////////// Q 65: Babbar450: KMP(Knuth-Morris-Pratt) Algo for Longest Prefix-Suffix  /////////////////////
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets
/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>

using namespace std;

int lps(string input)
{
    int size = input.size();
    int arr[size] = {0};

    for (int i = 0, j = 1; i < size && j < size;)
    {
        if (input[i] == input[j])
        {
            arr[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i > 0)
            { // moving i to position after last prefix
                i = arr[i - 1];
            }
            else
            { // no need to change i if it is 0.
                j++;
            }
        }
    }
    return arr[size - 1];
}

void printLongestPrefix(string input)
{
    int size = input.size();
    int arr[size] = {0};

    for (int i = 0, j = 1; i < size && j < size;)
    {
        if (input[i] == input[j])
        {
            arr[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i > 0)
            { // moving i to position after last prefix
                i = arr[i - 1];
            }
            else
            { // no need to change i if it is 0.
                j++;
            }
        }
    }
    if (arr[size - 1] > 0)
        cout << input.substr(size - arr[size - 1]) << endl;
}

int main()
{
    string input = "abcabc";
    printLongestPrefix(input);
    cout << lps(input);
}
