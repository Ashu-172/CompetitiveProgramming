/*////////////////////////////////////// Q 14: Babbar450 : Merge Intervals. //////////////////////////////////
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Quick sort implementation for ranges
int partition(vector<vector<int>> &input, int start, int end)
{
    vector<int> pivot = input[end];
    int i = start;
    for (int j = start; i < j, j < end; j++)
    {
        if (input[j][0] < pivot[0])
        {
            swap(input[i], input[j]);
            i++;
        }
        else if (input[j][0] == pivot[0]) // if first value is equal, compare second value
        {
            if (input[j][1] < pivot[1])
            {
                swap(input[i], input[j]);
                i++;
            }
        }
    }
    swap(input[i], input[end]);
    return i;
}

void sortIntervals(vector<vector<int>> &input, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(input, start, end);

        sortIntervals(input, start, pivot - 1);
        sortIntervals(input, pivot + 1, end);
    }
}

vector<vector<int>> getMergedIntervals(vector<vector<int>> &input)
{
    if (input.size() == 0 || input.size() == 1)
        return input;

    vector<vector<int>> result;
    sortIntervals(input, 0, input.size() - 1); // same as sort(input.begin(), input.end());

    //inserting first interval to the result
    result.push_back(input[0]);

    for (int j = 1; j < input.size(); j++)
    {
        /*
        if start of j th interval is less than or equal to the end of last inserted interval,
        intervals can be merged. End of the merged interval should be max of the end values 
        of both of the intervals. if above condition not met, then ntervals are not mergable,
        we can direcly push the current interval to the result.
        */
        if (result.back()[1] >= input[j][0])
        {
            result.back()[1] = max(result.back()[1], input[j][1]);
        }
        else
        {
            result.push_back(input[j]);
        }
    }

    return result;
}
//space complexity is O(n) time complexity is O(n log n)

vector<vector<int>> mergeIntervals(vector<vector<int>> &input)
{
    if (input.size() <= 1)
        return input;

    sort(input.begin(), input.end());

    int i = 0;
    for (int j = 1; i < input.size(), j < input.size(); j++)
    {
        if (input[i][1] >= input[j][0])
            input[i][1] = max(input[i][1], input[j][1]);
        else
        {
            i++;
            input[i] = input[j];
        }
    }
    //remove intervals from i+1 th index to end
    for (auto itr = input.end(); itr != input.begin() + i + 1; itr--)
        input.erase(itr);
    return input;
}
//this solution will take addition time for removing elements from input
//space complexity is O(1) time complexity is O(n log n)

int main()
{

    vector<vector<int>> input{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    //vector<vector<int>> result = getMergedIntervals(input);
    vector<vector<int>> result = mergeIntervals(input);
    for (vector<int> tuple : result)
    {
        cout << "[ " << tuple[0] << ", " << tuple[1] << " ]" << endl;
    }
}
