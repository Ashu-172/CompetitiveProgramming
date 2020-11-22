/*////////////////////// Q 47: Babbar450 (CtCI 1.1) : Print the Duplicates /////////////////////////////
Write an efficient program to print all the duplicates and their counts in the input string.
///////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void merge(string &input, int start, int mid, int end)
{
    int lLen = mid - start + 1;
    int rLen = end - mid;

    char left[lLen];
    char right[rLen];

    for (int i = 0; i < lLen; i++)
    {
        left[i] = input[start + i];
    }

    for (int i = 0; i < rLen; i++)
    {
        right[i] = input[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < lLen && j < rLen)
    {
        if (left[i] > right[j])
        {
            input[k++] = right[j++];
        }
        else
        {
            input[k++] = left[i++];
        }
    }
    while (i < lLen)
    {
        input[k++] = left[i++];
    }
    while (j < rLen)
    {
        input[k++] = right[j++];
    }
}

void mergeSort(string &input, int start, int end)
{
    if (end > start)
    {
        int mid = (start + end) / 2;

        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);
        merge(input, start, mid, end);
    }
    return;
}

/////////////////////////////////// Solution 1 (Sorting String) ///////////////////////////
// Time complexity for this solution is O(n log n)
void printDuplicatesSorted(string input)
{
    int size = input.size();
    mergeSort(input, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        int count = 0;
        while (i < size - 1)
        {
            if (input[i] == input[i + 1])
            {
                count++;
                i++;
            }
            else
            {
                break;
            }
        }
        if (count > 0)
            cout << input[i] << " " << count + 1 << endl;
    }
}

///////////////////////////// Solution 2 (Using Hash Table) ////////////////////
// Time complexity for this solution is O(n) and space complexity is O(1) since
// of the Hash Table is is not dependent on string size, it'll be maximum 26 or 52.
void printDuplicatesHashTable(string input)
{
    unordered_map<char, int> HT;
    int size = input.size();
    for (int i = 0; i < size; i++)
    {
        auto itr = HT.find(input[i]);
        if (itr != HT.end())
        {
            itr->second++;
        }
        else
        {
            HT.insert(make_pair(input[i], 1));
        }
    }
    auto itr = HT.begin();
    while (itr != HT.end())
    {
        if (itr->second > 1)
            cout << itr->first << " " << itr->second << endl;
        itr++;
    }
}

////////////////////// Solution 3 /////////////////
/*
Instead of storing frequency in Hash Table we can use array of bigger size like 128, 
because it can cover all the alphabets, in this array we can use ASCII value of each 
char as index and count the occurrence and store at that index in the array.
*/
int main()
{
    string input = "abab";

    printDuplicatesSorted(input);
    printDuplicatesHashTable(input);
}