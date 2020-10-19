///////////////////////////// CtCI P47 Example //////////////////////////
/*////////////////////////// Problem Statement //////////////////////////
Given a smaller string s and a bigger string b, design an algorithm to 
find all permutation of the shorter string within the longer one. print
the location of each permutation.
///////////////////////////////////////////////////////////////////////*/

/*//////////////////////////// Solution /////////////////////////////////
to designthe algo for this problem we can use example given in the book.
                    s: abbc
                    b: cbabadcbbabbcbabaa

locations of permutation: 0, 6, 9, 11, 12

How did we find these locations..?
1. check first char of b i.e. 'c' is present in s or not.
    it's present so now we'll check for next char 'b'
    'b' is also present in string s, now we'll check for 'a',
    'a' is also present in string s so next we'll check for next
     char in string s i.e. 'b'. 
    'b' is also present in the string s.
2. we founnd one permutation of string s in string b, now we need 
    to print starting index of the permutation, for first permutation
    it is 0.
    Observation: we need to maintain starting index of the permutation.
    Observation: we need to maintain a counter which will tell us that 
                 we found the permutation and we need to stop and print 
                 the starting index. this counter will be initialized 
                 by length of string s.and every time we found a char 
                 of string b in string s, we'll decrease the counter.
                 when the counter becomes 0 we'll know that we found
                 comtinuous b.length number of characters of string b 
                 in string s and this is a permutation  of s.
    Observation: we need to maintain counts of each char in string s, 
                 bwcause we need to take care of number of occurrance 
                 of each char in permutation, it should be same as 
                 occurrance in string s.
                 to do this we can create a HashTable where key will be 
                 the char and value will be total number of occurrances.
    Observation: on finding a char of string b in syring s, instead of
                 decreasing count for that char in the map, we can create 
                 a temporary map and insert and increase count for those 
                 char in this temp map, and compare values of count for the
                 char in temp map with count in main map.
                 if we decrease count in the main map than again we need to
                 iterate over string s and fill the map, this repeated work
                 will increase time complexity unnecessarily.
    Observation: whenever we encounter a char which is not part of string s,
                 we can skip the current permutation string and set start to 
                 next to that char, because this substring can not be a 
                 permutation of string s.
///////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    string s = "abbc";
    string b = "cbabadcbbabbcbabaabccbabc";

    unordered_map<char, int> map;

    //inserting char of string s in HashTable with count, complexity = s * O(1) = O(s)
    for (int i = 0; i < s.length(); i++)
    {
        auto itr = map.find(s[i]);
        if (itr == map.end())
            map.insert(make_pair(s[i], 1));
        else
            itr->second++;
    }

    int start = 0;
    int match_left = s.length();

    unordered_map<char, int> localMap;
    for (int i = 0; i < b.length(); i++)
    {
        // checking if the current character is present in the source strting or not, if not then setting start to next character to i,
        //because current string can not be a permutation, window will start from next character.
        //removing all the entries from the map, none of characters from older window present in new window
        auto check_s = map.find(b[i]);
        if (check_s == map.end())
        {
            start = i + 1;
            match_left = s.length();
            localMap.clear();
        }
        else
        {
            //inserting value as one of the key or incrementing by 1
            auto check_b = localMap.find(b[i]);
            pair<unordered_map<char, int>::iterator, bool> result;
            if (check_b == localMap.end())
            {
                result = localMap.insert(make_pair(b[i], 1));
                check_b = result.first;
            }
            else
            {
                check_b->second++;
            }

            match_left--;
            //if all the characters from current window is present in the source match_left will be 0, even if source is abbc and windoe is accb or aabc
            if (match_left == 0)
            {
                // if count of current character is equal in both strings and window, we have the permutation of source in the window,
                // printing the starting location of the permutation
                // moving the start pointer to next char by doing start++ because next permutation can occur from next character
                // since we are movind the window to its right by 1 location, we'll have to decrease value for the char at start of older window in the local_map by 1.
                // increasing match_left by 1 to check whether next char i.e. i+1 th  char creates a permutation or not.
                if (check_s->second == check_b->second)
                {

                    cout << start << endl; // printing location of permutation
                    //going to location of start char and decreasing count by 1 (sliding the window to right by one position)
                    auto loc_itr = localMap.find(b[start]);
                    loc_itr->second--;

                    start++;      // moving to next location to check next permutation
                    match_left++; // only one character needs to be matched
                }
                // if match left is 0 but string in window is not a permutation for eg, source is abbc but string in window is aabc or abcc
                // in this case start has to move to the location next to the first occurrance of current character
                // in our example, window at location 18 in string b contains "abcc" for this match_left is 0 but value for c in the local map is 2 while
                // value for c in the main map is 1, in this case this string can not be a permutation. we need to set start to location 21 (just after the first occurrance of c) because next permutation can start from 2nd c,
                // values for the characters till the new start will be decreased based on the occurrance
                //match_left will be incremented for each char from old start(inclusive) to new start(exclusive).
                else if (check_s->second < check_b->second)
                {
                    //shifting start to the  location next to the first occurance of current character which has occurred more than required number,
                    //current window is not a permutation. new window will start from the location next to the first occurance of the charater.
                    for (int j = start; j < i; j++)
                    {
                        auto loc_itr = localMap.find(b[j]);
                        loc_itr->second--;
                        match_left++;
                        if (b[j] == b[i])
                        {
                            start = j + 1;
                            break;
                        }
                    }
                }
            }
            // if match left is not 0 and number of occurrance of current char in the window is more than occurrences in source string
            // in this case start has to move to the location next to the first occurrance of current character
            // in our example, window at location 17 in string b contains "aabc" for second a match_left is 2 and value for a in the local map is 2 while
            // value for a in the main map is 1, in this case this string can not be a permutation. we need to set start to location 18 (just after the first occurrance of a) because next permutation can start from next character i.e. 2nd a,
            // values for the characters till the new start will be decreased based on the occurrance
            //match_left will be incremented for each char from old start(inclusive) to new start(exclusive).
            else if (check_s->second < check_b->second)
            {
                //shifting start to the  location next to the first occurance of current character which has occurred more than required number,
                //current window is not a permutation. new window will start from the location next to the first occurance of the charater.
                for (int j = start; j < i; j++)
                {
                    auto loc_itr = localMap.find(b[j]);
                    loc_itr->second--;
                    match_left++;
                    if (b[j] == b[i])
                    {
                        start = j + 1;
                        break;
                    }
                }
            }
        }
    }
}