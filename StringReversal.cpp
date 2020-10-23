/////////////////////////////////// Q1: Babbar450 : Reversal of Array/ String /////////////////////////////
//Reverse a given array with and without using extra space
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace ::std;

void reverseInline(int input[], int size)
{
    /////////////////// Solution 2. (without using Extra space) /////////////////
    int temp = 0;
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverse(int input[], int size)
{
    /////////////////// Solution 1. (using Extra space) /////////////////
    int temp[size];

    for (int i = 0; i < size; i++)
    {
        temp[i] = input[size - 1 - i];
    }

    for (int i = 0; i < size; i++)
    {
        input[i] = temp[i];
    }
}

void reverseString(vector<char> &s)
{
    if (s.size() != 0)
    {
#if 0
        vector<char>::iterator start = s.begin();
        vector<char>::iterator end = s.end() - 1; //end is not last point of the string, it is one beyond that has to be decremented
                                                  //by 1 to reach to the last elemt or we can use rbegin() to get the iterator poing to end

        while (start < end)
        {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
#endif

        for (int i = 0, j = s.size() - 1; i < j; swap(s[i++], s[j--]))
            ;
    }
}

int main()
{
    int input[] = {1, 6, 33, 99, 21, 78};
    int size = sizeof(input) / sizeof(int);

    //reverse(input, size);
    reverseInline(input, size);

    for (int num : input)
    {
        cout << num << " ";
    }
    cout << endl;
    string inputStr = "test string";

    vector<char> inputV;
    for (char c : inputStr)
        inputV.push_back(c);

    reverseString(inputV);

    for (vector<char>::iterator itr = inputV.begin(); itr != inputV.end(); itr++)
        cout << *itr;
}

/* in Solution 1  loop will be iterated 2 times Time complexity: O(2n) => O(n), Space Complexity O(n)
   in Solution 2 loop will be iterated only n/2 times Time Complexity: O(n/2) => O(n) Space Complexity O(1)

    Here Order of time complexity in same O(n) but in real execution second solution is 4 times faster then first.
*/
