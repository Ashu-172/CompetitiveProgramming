/*//////////////////// Recursion:Aditya Verma: Permute a string by changing case ////////////////////////
Print all permutations of a string keeping the sequence but changing cases.

Examples:

Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
///////////////////// Solution 1 (Recursion) ///////////////////////
void printCaseChangePermutation(string input, string output)
{
    if (input == "")
    {
        cout << output << " ";
        return;
    }
    printCaseChangePermutation(input.substr(1), output + input[0]);
    printCaseChangePermutation(input.substr(1), output + (char)toupper(input[0]));
}

/*////////////////////////// Solution 2 (Using Bitwise Shift) //////////////////////
Algorithm:

Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size (or set_size-1 to 0)
          (i) If ith bit in counter is set
               Print ith element in Upper Case
              Else
                Print ith element as it is (LowerCase)
     (b) Print separator for subsets i.e., newline

Example:

Set  = [a,b,c]
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> abc
    001                    -> abC
    010                    -> aBc
    011                    -> aBC
    100                    -> Abc
    101                    -> AbC
    110                    -> ABc
    111                    -> ABC
////////////////////////////////////////////////////////////////////////////////////////////////////*/
void printUpperCaseWithBitShift(string input)
{
    int size = input.size();
    int seqCount = pow(2, size);

    for (int i = 0; i < seqCount; i++)
    {
        for (int j = size - 1; j >= 0; j--)
        {
            if (i & (1 << j))
                cout << (char)toupper(input[size - 1 - j]);
            else
                cout << input[size - 1 - j];
        }
        cout << " ";
    }
}

int main()
{
    string input = "abc";
    string output = "";

    printCaseChangePermutation(input, output);
    cout << endl;
    printUpperCaseWithBitShift(input);
}