/*////////////////////// Q 52: Babbar450: Shuffel Of Two Strings /////////////////////////////
Write a Program to check whether a string is a valid shuffle of two strings or not

////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*/////////////////////////////////// Solution 1 ///////////////////////////////
1. sort target string.
2. sort the other two strings.
2. prepare a temporary string by concatinating str1 and str2 with sorting char.
3. compare target and temp strings, if equal return true.
//////////////////////////////////////////////////////////////////////////////*/
bool isShuffledUsingSort(string target, string str1, string str2)
{
    int size = target.size();
    sort(target.begin(), target.end());
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    // if number of chars are different
    if (size != (str1.size() + str2.size()))
        return false;

    string temp(size, '-');
    int i = 0, j = 0, k = 0;
    while (k < size && i < str1.size() && j < str2.size())
    {
        if (str1[i] < str2[j])
            temp[k++] = str1[i++];
        else
            temp[k++] = str2[j++];
    }
    while (i < str1.size())
        temp[k++] = str1[i++];

    while (j < str2.size())
        temp[k++] = str2[j++];

    if (target == temp)
        return true;
    else
        return false;
}

/*/////////////////////////////////// Solution 2 ///////////////////////////////
1. count frequency of each char present in target string
2. for each char present in str1, decrease the count by 1
3. for each char present in str2, decrease the count by 1
4. traverse the array to check if any non 0 value present, 
        if not then return true
        else return false
//////////////////////////////////////////////////////////////////////////////*/
bool isShuffle(string target, string str1, string str2)
{
    // since all alphabets resides within 128 ASCII value
    // for leser memory use we can use Hash Table(unordered_map)
    int arr[128] = {0};
    int size = target.size();
    int size1 = str1.size();
    int size2 = str2.size();

    //counting chars in target
    for (char c : target)
        arr[c]++;

    //decreasing count for str1
    for (char c : str1)
        arr[c]--;

    //decreasing count for str2
    for (char c : str2)
        arr[c]--;

    //checking if there is any non-zero number present
    for (int count : arr)
        if (count != 0)
            return false;

    return true;
}
int main()
{
    string target = "abdcdrw";
    string str1 = "acdd";
    string str2 = "bwr";

    cout << isShuffle(target, str1, str2) << endl;
    cout << isShuffledUsingSort(target, str1, str2) << endl;
}