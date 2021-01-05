/*//////////////////////////// Q 289: Babbar450: Merge Overlapping Intervals ///////////////////////////
Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
N = 4
Intervals = {(1,3),(2,4),(6,8),(9,10)}
Output: 1 4 6 8 9 10
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
N = 4
Intervals = {(6,8),(1,9),(2,4),(4,7)}
Output: 1 9
Your Task:
Complete the function overlappedInterval() that takes the list of pairs and N as input parameters and returns sorted list of pairs of intervals after merging.

Expected Time Complexity: O(N*Log(N) ).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 1000
///////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> overlappedInterval(vector<pair<int, int>>, int);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> arr, res;
        int n, x, y;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }

        res = overlappedInterval(arr, n);

        for (int i = 0; i < res.size(); i++)
            cout << res[i].first << " " << res[i].second << " ";

        cout << endl;
    }
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else
        return false;
}

//////////////////////////// Solution 1 //////////////////////////////////
/*
1) sort the vector with respect to first element of the pair
2) put first pair in the result vector
3) check for remaing pairs
    a) if first part of the current pair is greater than the second part of alredy inserted pair then this is not overlapping pair, push it in the result vector and increment index.
    b) if first part of the current pair is smaller than the second part of already inserted pair than set the secod part of already inserted pair to max of itself and second of current pair.
*/

vector<pair<int, int>> overlappedInterval(vector<pair<int, int>> vec, int n)
{
    sort(vec.begin(), vec.end(), comp);
    vector<pair<int, int>> result;
    result.push_back(vec[0]);
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first <= result[j].second)
        {
            if (vec[i].second > result[j].second)
                result[j].second = vec[i].second;
        }
        else
        {
            result.push_back(vec[i]);
            j++;
        }
    }
    return result;
}
