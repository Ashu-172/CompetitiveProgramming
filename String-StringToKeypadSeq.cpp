/*///////////// Q 66: Babbar450:Convert a sentence into its equivalent mobile numeric keypad sequence //////////////
Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence.

Examples :

Input : GEEKSFORGEEKS
Output : 4333355777733366677743333557777
For obtaining a number, we need to press a
number corresponding to that character for 
number of times equal to position of the 
character. For example, for character C, 
we press number 2 three times and accordingly.

Input : HELLO WORLD
Output : 4433555555666096667775553
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>

using namespace std;

//Time complexity = O(n)
void printNumericSequence(string input, string keyPad[])
{
    for (char c : input)
    {
        if (c == ' ')
            cout << 0;
        else
        {
            /* subtracting ASCII value of A (65) to get the index of char in the keypad
                for exmple c = G, then G-A = 71-65 = 6
                in keyPad at 6th index "4" is stored which is for G.
            */
            cout << keyPad[c - 'A'];
        }
    }
}

int main()
{
    string keyPad[] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

    string input = "GEEKSFORGEEKS";
    printNumericSequence(input, keyPad);
}