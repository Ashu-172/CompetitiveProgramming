/*////////////////////// Q 51: Babbar450 (CtCI Q1.9): Check String is rotation of Other /////////////////////////////
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

using namespace std;

/////////////////////////////// Solution 1 ///////////////////////////
/*
1. Search for str1[0] in second string and start comparing characters of both the strings
*/
bool isRotation(string str1, string str2)
{
    int size1 = str1.size();
    int size2 = str2.size();

    if (size1 != size2)
        return false;

    int i = 0;
    for (int j = 0; j < size2; j++)
    {
        int temp = j;
        while (str1[i] == str2[j] && i < size1)
        {
            i++;
            j++;
            if (j == size2)
                j = 0;
        }
        if (i == size1) //matched all characters
            return true;
        j = temp;
        i = 0;
    }
    return false;
}

int main()
{
    string str1 = "ABCD";
    string str2 = "ACBD";

    if (isRotation(str1, str2))
        cout << "true";
    else
        cout << "false";
}
