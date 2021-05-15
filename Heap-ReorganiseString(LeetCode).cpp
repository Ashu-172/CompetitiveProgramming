/*//////////////////////////////// Q 320: Babbar450: ReOrganize String ////////////////////////////////
Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
Note:

s will consist of lowercase letters and have length in range [1, 500].
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

////////////////////////////////////// Solution 1 (Using Heap) /////////////////////////////////////////
/*
we can solve this problem using Heap. we can understand the approach using following example.
ex: S = aaabbacdccddc

if we count each character then we'll have following structure:
a=4 b=2 c=4 d=3

now if we put above structure in a Heap then we'll following Heap
    <4,a>
    <4,c>
    <3,d>
    <2,b>

now we can take top two characters from the heap and put in the result string. so the result string is "ac". now if we decrease the counts and heapify the above structure.
    <3,a>
    <3,c>
    <3,d>
    <2,b>

we can repeat the above step again and the result string will be "acac" and Heap will be as:
    <3,d>
    <2,a>
    <2,c>
    <2,b>

this time if we repeat the same step the result string will be "acacda" and Heap will be as:
    <2,d>
    <2,c>
    <2,b>
    <1,a>
on repeating above step result = "acacdadc"
    <2,b>
    <1,d>
    <1,c>
    <1,a>
on repeating above step result = "acacdadcbd", now counter for d became 0 so it'll be removed from heap
    <1,b>
    <1,c>
    <1,d>

in next step result = "acacdadcbdbc", and heap will be as
    <1,d>

now we can directly insert the last character in the string since count for this is 1, if it would be more then we can not insert it as the string will have same characters in the end. in this case we need to return empty string.

Observation: in priority queue we can not get the second max char directly, the better way is to pop the first element from the heap so that the second will come on top.

Algorithm:

1. count the occourrence of elements in the array.
2. create a max heap of pair of characters and their counts.
3. repeat following steps until only one element remain in the heap
    1. store top element from the heap into a variable (first max) and pop it from the heap.
    2. store top element from the heap into another variable (second max) and pop it from the heap.
    3. insert characters from both the variables in the result string and decrease their counter value by one.
    4. insert both the pairs back to the heap if their counter value is not 0.
4. when there is only one element present in the heap, there can be following conditions based on which result will be returned.
    1. if counter value of this element is more than one, then we need to return empty string since we can not insert same characters togather in result.
    2. if count value of this element is 1 then if last element in the string is different, we need to insert this element in the result string, if it is same as the last element in the result string, we can not insert it in the result string and will return empty string.
5. there can be a case when there is no element present in heap (when last two elements had count value as 1 in the last iteration of the step 3, in this case we need to return the result string.

*/

string reorganizeString(string S)
{
    int arr[26] = {0};
    for (int i = 0; i < S.length(); i++)
    {
        arr[S[i] - 97]++;
    }

    priority_queue<pair<int, char>> maxHeap;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > 0)
            maxHeap.push(make_pair(arr[i], i + 97));
    }

    string result = "";
    while (maxHeap.size() > 1)
    {
        pair<int, char> top1 = maxHeap.top();
        maxHeap.pop();
        pair<int, char> top2 = maxHeap.top();
        maxHeap.pop();

        result.push_back(top1.second);
        result.push_back(top2.second);

        top1.first--;
        top2.first--;

        if (top1.first != 0)
            maxHeap.push(top1);

        if (top2.first != 0)
            maxHeap.push(top2);
    }

    if (maxHeap.size() == 1)
    {
        if (maxHeap.top().first > 1 || maxHeap.top().second == result[result.size() - 1])
        {
            return "";
        }
        else
        {
            result.push_back(maxHeap.top().second);
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << reorganizeString(s) << endl;
}