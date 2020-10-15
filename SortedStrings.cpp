/*//////////////////////// CtCI V.11 exercise Problem Statement /////////////////////////
Print all the strings of length k where the characters are in sorted order.
*/
////////////////////// Solution //////////////////////////

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int totalAlphabets = 26;
int count = 0;

//code written by me
void stringPrinter(int n, string prefix, int position)
{
    //Base case: on every function call we are choosing a char for the string and n is decressing for the next call
    //so when we'll have n characters chosen, n will be zero and prifix will be the n length sorted string and we
    //can print the string here.
    if (n == 0)
    {
        count++;
        cout << prefix << endl;
        return;
    }

    //Strings will be sorted, we can not take totalAlphabets-n+1(th) character from alphabet to form n sized sorted string
    //For example if we want to generate strings of size 5 then n=5, we can choose first characters from 'a' to 'v' then final sorted string will be 'vwxyz'.
    for (int i = position; i <= totalAlphabets - n; i++)
    {
        // adding the choosen character to prefix and passing it to the next iteration
        stringPrinter(n - 1, prefix + alphabets[i], i + 1);
    }
}

//Code Written in the CtCI Book
bool isInOrder(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        //cout << "1: " << s[i] << " 2: " << s[i + 1] << endl;
        if (s[i - 1] >= s[i])
            return false;
    }
    return true;
}

void printSortedStrings(int remaining, string prefix)
{
    if (remaining == 0)
    {
        if (isInOrder(prefix))
        {
            count++;
            cout << prefix << endl;
        }
    }
    else
    {
        for (int i = 0; i < totalAlphabets; i++)
        {
            printSortedStrings(remaining - 1, prefix + alphabets[i]);
        }
    }
}

void printSortedStrings(int remaining)
{
    printSortedStrings(remaining, "");
}

int main()
{
    int n = 0;
    cin >> n;
    auto start = high_resolution_clock::now();
    //stringPrinter(n, "", 0);
    printSortedStrings(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " count: " << count << endl;
}