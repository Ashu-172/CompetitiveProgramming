/*////////////////////// Q 63: Babbar450:  Word Break /////////////////////////////
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 


Example 1:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

â€‹Example 2:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".
 

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.


Expected time complexity: O(s2)
â€‹Expected auxiliary space: O(s) , where s = length of string A

 

Constraints:
1 <= N <= 12
1 <= s <=1000 , where s = length of string A
 The length of each word is less than 15.
//////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

///////////////////////////////// Solution 1 ///////////////////////////
/*
the idea here is to put every string of  dictonary in map using
first char as key and then search map for the first char in the map.
map will give a range for the key, since there will be key conflicts.
in this range we'll search for max length match. if we found then we'll 
skip remaining matched characters in the string and repeat same for next char.

Algorithm:
1. Fill all the words from the dictonary in the map.
2. use first char of string as key to search for a word.
3. get a list of words starting with current char.
4. if list is empty, no word present in map starting with current char, return false.
5. else search for max length matched word in the list using loop over the range,
    in the end if maxMatched string is empty then we didn't find any matching word 
    present in the string and dictonary, returning false;
6. if found max Length match, increment i with the length of matched word, so that 
    the next search will start from the char present after matched word in string.

Time Complexity: 
    1. Time complexity for insert in multimap in avrg case is O(1), we are inserting 
        n words. Time complexity is O(n) for map insertion.
    2. while searching words in dictonary we are not traversing complete string, we are 
        jumping from one position to another but we are using substr() function there
        for which time complexity is O(k) where k is the length of substring.
        if we add all values of k, it will be equal to string length.
        Hence time complexity for traversing string is O(S) where S is size of input string.
    3. we are using equal_range for map searching for which time complexity is O(log n) and 
        in the range we are traversing linearly. in avrg case each range will have n/26 words,
        for each char n/26 equal number of words. then linear traversal will give O(n/26) time complexity.
        total time complexity for map search is O(n/26 log n) it will always be less than n.
        max Time omplexity for searching is O(n), where n is number of words in dictonary.

    Final Time Complexity = O(n) + O(m)*O(n) = O(n*n)
                            where m is number of matched words present in string
                                  n is number of words present in dictonary
        
*/
bool isValidString(vector<string> dict, string input)
{
    int size = input.size();

    unordered_multimap<char, string> dictMap;
    //inserting dictonary in multimap
    for (string str : dict)
    {
        dictMap.insert(make_pair(str[0], str));
    }

    for (int i = 0; i < size;)
    {
        // extracting range for first char of the remaining string
        pair<unordered_multimap<char, string>::iterator,
             unordered_multimap<char, string>::iterator>
            range = dictMap.equal_range(input[i]);

        // if
        if (range.first == range.second)
            return false;
        auto itr = range.first;
        string maxMatch = "";
        while (itr != range.second)
        {
            int length = itr->second.size(); //size of strings in the range
            //extracting substring of length equal to current word's length
            string temp = input.substr(i, length);

            // if temp is equal to current word
            if (temp == itr->second)
            { // checking if it is max length matched word
                if (maxMatch.size() < length)
                    maxMatch = temp;
            }
            itr++;
        } // checking for next word in the range in loop

        /* in the end if maxMatch is of 0 zero length i.e. "", 
            then there is no matching word  present in the 
            dictonary starting with ith char, returning false*/
        if (maxMatch == "")
            return false;

        // moving to next unmatched character in the string
        i = i + maxMatch.size();
    }
    return true;
}

/////////////////////////////////// Solution 2 (Uisng Recursion) /////////////////////////////
bool wordBreak(vector<string> dict, string input)
{
    if (input.size() == 0)
        return true;

    bool result = false;
    for (string word : dict)
    {
        string temp = input.substr(0, word.size());
        if (temp == word)
            result = result || wordBreak(dict, input.substr(word.size()));
    }
    return result;
}

int main()
{
    vector<string> dict{"i", "like", "sam", "sung", "samsung", "mob", "ice", "cream", "icecream", "man", "go", "mango"};
    string input = "ilikemang";
    cout << isValidString(dict, input) << endl;
    cout << wordBreak(dict, input) << endl;
}