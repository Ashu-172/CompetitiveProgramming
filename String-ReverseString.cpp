/*////////////////////// Q 47: Babbar450 : Reverse a String /////////////////////////////
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
///////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;

/////////////////////// Double Poinnter Approch //////////////////////
void reverseString(vector<char> &s)
{
    int size = s.size();
    int i = 0;
    char temp;
    while (i < size / 2)
    {
        temp = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = temp;
        i++;
    }
}

int main()
{
    vector<char> input{'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(input);
    for (char c : input)
        cout << c << " ";
}
