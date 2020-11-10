/*////////////////////////////////////// Q 18: Babbar450 : count pairs with sum //////////////////////////////////
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:
Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <unordered_map>
using namespace std;

/////////////////////////////// Solution 1 : Brute Force approach ////////////////////////////

long getPairCount(int input[], int size, int sum)
{
    long count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (input[j] == sum - input[i])
                count++;
    }
    return count;
}
//Time complexity = O(n^2)

//////////////////////////////// Solution 2 : Using Hash Table //////////////////////////////////
/*If we traverse from end and put every element a into the map and check b = sum-1 is present in the map.
if it is present then we found a pair we can increase the count
there are two points to Note here
1. we need to first search the map for b before inserting a otherwise we'll count a as be if both are same.
   for rxample if array is [1,1,1,1] and sum  = 2 then 
   if we first insert a = 1 in the map then b = 2-1 = 1 will already be there in the map even if we are checking 1st 1 which is not a pair at all

2. since we are inserting each a in the map, we need to increase the frequency of it from second occurrence and whenever we find
    any b in the map we need to incrase the count by frequcncy instead of 1.
    in above example on second occurrence of 1 we found a pair. this time we already have a in the map if we don't increment its frequency then on next occurrance of a, b = 1 then count = 1++ = 2 which is not correct because we have 3 pairs now for [1,1,1].
    if we increase the frequency by 1 on 2nd occurrence then map[1] = 2. on third occurrence of 1, b = 2-1 = 1, count = 1+map[1] = 1+2 = 3.
 */
long getPairCountHM(int input[], int size, int sum)
{
    if (size == 0)
        return 0;
    unordered_map<int, int> map;
    int a, b;
    long count = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        a = input[i];
        b = sum - a;
        auto itrB = map.find(b);
        if (itrB != map.end())
        {
            count += itrB->second;
        }

        auto itrA = map.find(a);
        if (itrA != map.end())
        {
            itrA->second++;
        }
        else
        {
            map.insert(make_pair(a, 1));
        }
    }
    return count;
}
// Time complexity for this solution is O(n) Space Complexity is O(n).

int main()
{
    int input[] = {4, 1, 1, 5, 4, 0};
    int size = sizeof(input) / sizeof(int);
    int k = 5;
    long count = getPairCount(input, size, k);
    cout << count << endl;
    count = getPairCountHM(input, size, k);
    cout << count << endl;
}