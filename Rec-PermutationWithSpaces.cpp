/*//////////////////////// Recursion:Aditya Verma: Permutation with Spaaces /////////////////////////////
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. Output should be printed in sorted increasing order of strings.

Input:  str[] = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Input:
First line contains the test cases T.  1<=T<=10
Each test case have one line string S of characters of length  N.  1<=N<=10

Output:
One line per test case, every string enclosed in ().(See example). Output should be printed in sorted order.

Example:
Input:
2
AB
ABC

Output:
(A B)(AB)
(A B C)(A BC)(AB C)(ABC)
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>

using namespace std;

void printStrings(string output, string input)
{
    if (input == "")
    {
        cout << output << endl;
        return;
    }
    char first = input[0];
    input.erase(input.begin() + 0);
    printStrings(output + " " + first, input);
    printStrings(output + first, input);
}

int main()
{
    string input;
    cin >> input;
    string output;
    output.push_back(input[0]);
    input.erase(input.begin() + 0);

    printStrings(output, input);
}