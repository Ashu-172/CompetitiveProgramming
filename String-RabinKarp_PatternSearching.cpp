/*/////////////////// Q 64: Babbar450: RabinKarp Algorithm for Pattern Searching /////////////////////
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.
Examples: 

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printPatternIndexes(string input, string pattern)
{
    int size = input.size();
    int pLen = pattern.size();

    for (int i = 0; i <= size - pLen; i++)
    {
        if (input[i] == pattern[0])
        {
            int j = 1;
            while (j < pLen)
            {
                if (input[i + j] != pattern[j])
                    break;
                j++;
            }
            if (j == pLen)
                cout << i << " ";
        }
    }
}
// Time complexity for above solution is O(m*n) where n is input length and m is pattern length.

///////////////////////////////// Solution 2 (Rabin Karp Algorithm) //////////////////////////
/*
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters. So Rabin Karp algorithm needs to calculate hash values for following strings.
1) Pattern itself. 
2) All the substrings of the text of length m. 

the calculation of Hase will be done in following way:
A prime Number and ASCII value of chars will be used for generating Hash
for example we are generating Hash for 4 char string and using prime number 101 for Hashing
    Hash = input[0] + input[1]*101 + input[2]*101^2 + input[3]*101^3

    lets say pattern is abc and input is dabcde
    Hash(pattern) = a +  b* 101 + c *101^2
    Hash(dab) = d + a*101 + b*101^2

    now to get Hash of next Substring of length 3, we can calculate from previous Hash
    Hash(abc) = a + b *101 + c * 101^2
    Step 1: substract first char from previous substring Hash
                Hash(dab) - d = a *101 + b* 101^2
    Step 2: divide result of step 1 by prime number
                (a*101 + b* 101^2) / 101 = a + b *101
        
    Step 3: add (ASCII of new char * prime ^ patternLen-1 ) in the result
                a + b *101 + c * 101 ^(3-1)
              = a + b*101 + c* 101^2  


After matching Hash values of substrings and pattern, we'll check that substring char by char
if matched then we'll print out the index.
*/

int getHash(string input, int len)
{
    int hash = input[0];
    int prime = 101;
    for (int i = 1; i < len; i++)
        hash += input[i] * pow(prime, i);
    return hash;
}

int reHash(string input, int hash, int start, int len)
{
    int prime = 101;
    hash = hash - input[start];
    hash /= prime;
    hash += input[start + len] * pow(prime, len - 1);
    return hash;
}

void rabinKarp(string input, string pattern)
{
    int size = input.size();
    int pLen = pattern.size();

    int pHash = getHash(pattern, pLen);
    int iHash = getHash(input, pLen);

    for (int i = 0; i < size - pLen; i++)
    {
        if (pHash == iHash)
            cout << i << " ";
        iHash = reHash(input, iHash, i, pLen);
    }
    if (pHash == iHash)
    {
        cout << size - pLen << " ";
    }
}

//////////////////////////////////// KMP Algorithm Using Prefix-suffix /////////////////////////////
// preparing prefix-suffix array
void getPrefixSuffix(string input, int arr[])
{
    arr[0] = 0;
    int size = input.size();
    for (int i = 0, j = 1; i < size && j < size;)
    {
        if (input[i] == input[j])
        {
            arr[j] = arr[i] + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
                i = arr[i - 1];
            else
                j++;
        }
    }
}

int findPatternKMP(string input, string pattern)
{
    int size = input.size();
    int pLen = pattern.size();

    int arr[pLen];
    // fill array with prefix suffix information for pattern
    getPrefixSuffix(pattern, arr);

    for (int i = 0, j = 0; i < pLen && j < size;)
    {
        if (pattern[i] == input[j])
        {
            i++;
            j++;
            if (i == pLen)
                return j - pLen;
        }
        else
        {
            if (i != 0)
                i = arr[i - 1];
            else
                j++;
        }
    }
    return -1;
}

int main()
{
    string input = "AABAACAADAABAABA";
    string pattern = "AABA";

    printPatternIndexes(input, pattern);
    cout << endl;
    rabinKarp(input, pattern);
    cout << endl;
    //printing only first occurrence
    cout << findPatternKMP(input, pattern) << endl;
}