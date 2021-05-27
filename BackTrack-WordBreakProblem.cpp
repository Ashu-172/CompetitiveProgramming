/*////////////////////////////////// Q 257: Babbar450: Word Break Problem ///////////////////////////////////
Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

Follow examples for better understanding.

Example 1:

Input: s = "catsanddog", n = 5 
dict = {"cats", "cat", "and", "sand", "dog"}
Output: (cats and dog)(cat sand dog)
Explanation: All the words in the given 
sentences are present in the dictionary.
Example 2:

Input: s = "catsandog", n = 5
dict = {"cats", "cat", "and", "sand", "dog"}
Output: Empty
Explanation: There is no possible breaking of the string s where all the words are present in dict.

Expected Time Complexity: O(N2*n) where N = |s|
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ n ≤ 20
1 ≤ dict[i] ≤ 15
1 ≤ |s| ≤ 500 
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
/////////////////////////////////////////////// Solution /////////////////////////////////////////
/*
we can understand it with the following example

s = catsand
dict = [cat, cats, sand, and]

                                                    catsand
                                              *               *
        c atsand         ca tsand         cat sand         cats and         catsa nd         catsan d
    
    here we need to check for every combination, whether both the parts are present in dictonary, if present then we can make a sentence with them. Here we can say that if left word is not in the dictonary then a sentance can not be formed even if we partition the right word.

    here one more thing to notice is if the right part of the word is not in the dictonary, there is still chances that breaking it may result in more words which can be present in the dictonary.

    Algorithm:
    1. do following for all the possible places of space (index 1 to n-1)
        a. break the word in two parts having i characters and n-i characters.
        b. check if first part is present in the dictonary, if not then current pair of words can not form a sentance so skip current pair.
        c. if first part is present in the dictonary then check for second part.
        d. if second part is also present in the dictonary, create a sentence with prefix, first and second parts and put in the result vector.
        e. irrespective of presence of second part in the dictonary, it is possible that breaking the second part can result in set of words which are present in the dictonary and can form sentence. so call the function and pass the second part as the input string. also append the first part in the prefix since it is present in the dictonary and will be part of sentences formed by the second part.

Complexity Analysis:
    here we are creating two parts of the word on every call but we are calling function only for one part, in each function call the loop will execute by n times (max) so function calls will be n. the recursive levels will be called till the length of the word reaches to 1.

    Hierarchy of function calls in loops for each call
                            6
        5       4       3       2        1       0
     4 3 2 1   3 2 1   2 1      1        
     ............
     ............  
    at each level the total function calls will be  (N-1)(N-2)/2 where N is total possibel places for space. total levels will also be N.

        time complexity = O(N^2) * N = O(N^3)

    
*/
void makeSentences(unordered_set<string> &dict, vector<string> &result, string prefix, string s)
{
    string left = "";
    string right = "";
    for (int i = 1; i < s.size(); i++)
    {
        left = s.substr(0, i);
        right = s.substr(i);

        // if prefix is valid then only check suffix can form a sentance
        if (dict.find(left) != dict.end())
        {
            // if prefix and suffix both present in dict, make a sentance and put in result
            if (dict.find(right) != dict.end())
            {
                result.push_back(prefix + left + " " + right);
            }
            // suffix can be broken in words may for sentance
            makeSentences(dict, result, prefix + left + " ", right);
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    unordered_set<string> dictonary(dict.begin(), dict.end());
    vector<string> result;
    if (dictonary.find(s) != dictonary.end())
        result.push_back(s);

    makeSentences(dictonary, result, "", s);
    return result;
}

int main()
{

    int n;
    vector<string> dict;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        dict.push_back(s);
    }
    cin >> s;

    vector<string> ans = wordBreak(n, dict, s);
    if (ans.size() == 0)
        cout << "Empty\n";
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << "(" << ans[i] << ")";
        cout << endl;
    }

    return 0;
}