/*/////////////////////////// Q 57: Babbar450:  Print all Susequences /////////////////////////////
Given a string, we have to find out all subsequences of it. A String is a subsequence of a given
 String, that is generated by deleting some character of a given string without changing its order.
Examples: 

Input : abc
Output : a, b, c, ab, bc, ac, abc

Input : aaa
Output : a, aa, aaa
/////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//////////////////////// Solution 1 (DP - Recursive Tree method) ////////////////////
/*
1. we can consider empty string as root node.
2. we have two choices for first char of input, 
    either select or not for appending to prefix
    -> 1st function call is for not selecting input[0]
    -> 2nd function call is for selecting input[0]
3. since we have taken the decision, we can exclude 
    that char from input in next call;
4. base condition is when input became empty.

               prefix  Input
                 ""   abc
                /        \
             ""  bc       a  bc
             /     \      /     \
         ""  c    b c    a  c   ab  c
         /   \   /   \   /   \   /   \
        ""   c  b    bc a    ac  ab   abc    <- results
*/
void printSubsequenceRec(string prefix, string input)
{
    int size = input.size();
    if (size == 0)
    {
        cout << prefix << " ";
        return;
    }
    printSubsequenceRec(prefix, input.substr(1, size - 1));
    printSubsequenceRec(prefix += input.at(0), input.substr(1, size - 1));
}

//////////////////////// Solution 2 (Back tracking) //////////////////////////
/*
1. add char to prefix in loop
2. for each of prefix call same function, where loop starts from next index
3. each function call will print prefix
4. after function call backtrack to previous prefix and repeat for next index 
    in the loop
5. each node in the tree is forming output, so we'll print when length of 
    prefix is greater than 0.

                    ""
                  /  |   \
                a    b    c
              /  \   |
            ab   ac  bc
          /
        abc
*/
void printSubSeqBackTracking(string prefix, string input, int index, int size)
{
    int len = prefix.size();

    if (len > 0)
        cout << prefix << " ";

    while (index < size)
    {
        prefix += input[index];
        printSubSeqBackTracking(prefix, input, index + 1, size);
        prefix = prefix.erase(len); // removing last char
        index++;
    }
}

/*////////////////////////// Solution 3 (Using Bitwise Shift) //////////////////////
Algorithm:

Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size (or set_size-1 to 0)
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print separator for subsets i.e., newline

Example:

Set  = [a,b,c]
power_set_size = pow(2, 3) = 8
Run for binary counter = 000 to 111

Value of Counter            Subset
    000                    -> Empty set
    001                    -> a
    010                    -> b
    011                    -> ab
    100                    -> c
    101                    -> ac
    110                    -> bc
    111                    -> abc
////////////////////////////////////////////////////////////////////////////////////////////////////*/
void printSubSeqWithBits(string input)
{
    int size = input.size();
    int SeqCount = pow(2, size);

    //each iteration will print one sequence
    //for (int i = SeqCount - 1; i >= 0; i--) //Starting from 1111
    for (int i = 0; i < SeqCount; i++) //Starting from 0000
    {
        for (int j = size - 1; j >= 0; j--)
        {
            if (i & (1 << j))
            {
                cout << input[size - j - 1];
            }
        }
        cout << " ";
    }
}

int main()
{
    string input = "abcd";
    printSubsequenceRec("", input);
    cout << endl;
    printSubSeqBackTracking("", input, 0, input.size());
    cout << endl;
    printSubSeqWithBits(input);
}