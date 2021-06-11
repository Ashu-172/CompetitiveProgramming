/*/////////////////////////////////////////// find the sets of foreground and background application /////////////////////////////////////////
James is working on a system that divides applications to a mixes cluster of computing devices.eaxch application is identified by an integer ID, requires a fixed non-zero amount of memory to execute,and is defined to be either a foreground or background application. IDs are guaranteed to be unique within their own application type, but not access types.

Each device should be signed two applications at once, one foreground application and one background application, Devices have limited amount of memory and cannot execute applications that require more memory than the available memory .The goal of the system is to maximise the total utilization of the memory of a given device. A foreground/background application pair is considered to be optimal if there does not exist another pair that uses more memory than this pair,and also has a total less than or equal to the total memory of the device. For example, if the device has 10MB memory a foreground/background pair using a sum total of 9MB memory would be optimal if there does not exist a pair that uses a sum total of 10MB, but would not be optimal if such a pair did exist.

Write an algorithm to help James find the sets of foreground and background application pairs that optimally utilize the given device for a given list of foreground applications and a given list of background applications.

Input – The input to the function/method consists of three arguments:

devicecapacity, an integer representing the maximum capacity of the given device;

forgroundAppList, a list of pairs of integers where the first integer represents the unique ID of a foreground application and the second integer represents the amount of memory required by this application;

backgroundAppList, a list of pairs of integers where the first integer represents the unique ID of a background application and the second integer represents the amount of memory required by this application.

Output – Return a list of pairs of integers representing the pairs of IDs of foreground and background applications that optimally utilize the given device. If no pair is possible ,return a list with empty pair.


                                                    ////////// OR /////////

Given 2 lists a and b. Each element is a pair of integers where the first integer represents the unique id and the second integer represents a value. Your task is to find an element from a and an element form b such that the sum of their values is less or equal to target and as close to target as possible. Return a list of ids of selected elements. If no pair is possible, return an empty list.

Example 1:

Input:
a = [[1, 2], [2, 4], [3, 6]]
b = [[1, 2]]
target = 7

Output: [[2, 1]]

Explanation:
There are only three combinations [1, 1], [2, 1], and [3, 1], which have a total sum of 4, 6 and 8, respectively.
Since 6 is the largest sum that does not exceed 7, [2, 1] is the optimal pair.

Example 2:

Input:
a = [[1, 3], [2, 5], [3, 7], [4, 10]]
b = [[1, 2], [2, 3], [3, 4], [4, 5]]
target = 10

Output: [[2, 4], [3, 2]]

Explanation:
There are two pairs possible. Element with id = 2 from the list `a` has a value 5, and element with id = 4 from the list `b` also has a value 5.
Combined, they add up to 10. Similarily, element with id = 3 from `a` has a value 7, and element with id = 2 from `b` has a value 3.
These also add up to 10. Therefore, the optimal pairs are [2, 4] and [3, 2].

Example 3:

Input:
a = [[1, 8], [2, 7], [3, 14]]
b = [[1, 5], [2, 10], [3, 14]]
target = 20

Output: [[3, 1]]

Example 4:

Input:
a = [[1, 8], [2, 15], [3, 9]]
b = [[1, 8], [2, 11], [3, 12]]
target = 20

Output: [[1, 3], [3, 2]]

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> input1, vector<int> input2)
{
    return input1[1] < input2[1];
}

int lowerBound(vector<vector<int>> input, int num, int start, int end)
{
    if (start == end)
    {
        if (input[start][1] <= num)
            return start;
        else
            return -1;
    }
    else if (start < end)
    {
        int mid = (start + end + 1) / 2;

        if (input[mid][1] == num)
            return mid;
        else if (input[mid][1] < num)
            return lowerBound(input, num, mid, end);
        else
            return lowerBound(input, num, start, mid - 1);
    }
    else
        return -1;
}

vector<vector<int>> findOptimalUses(int mem, vector<vector<int>> fg, vector<vector<int>> bg)
{
    sort(fg.begin(), fg.end(), compare);
    sort(bg.begin(), bg.end(), compare);

    int maxUse = 0;
    vector<vector<int>> result;

    for (int i = 0; i < fg.size(); i++)
    {
        int index = lowerBound(bg, mem - fg[i][1], 0, bg.size() - 1);
        if (index != -1 && bg[index][1] + fg[i][1] >= maxUse)
        {
            // clear the result only when new utilization is more than maxUse
            // if it is equal then directly insert the pair of Application ids
            if (bg[index][1] + fg[i][1] > maxUse)
                result.clear();

            maxUse = bg[index][1] + fg[i][1];
            vector<int> pairApp;
            pairApp.push_back(fg[i][0]);
            pairApp.push_back(bg[index][0]);
            result.push_back(pairApp);
        }
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> fg, bg;
    for (int i = 0; i < n; i++)
    {
        vector<int> process(2);
        cin >> process[0] >> process[1];
        fg.push_back(process);
    }

    for (int i = 0; i < m; i++)
    {
        vector<int> process(2);
        cin >> process[0] >> process[1];
        bg.push_back(process);
    }

    int deviceMem;
    cin >> deviceMem;

    vector<vector<int>> result = findOptimalUses(deviceMem, fg, bg);

    for (vector<int> pair : result)
    {
        cout << pair[0] << " " << pair[1] << endl;
    }
}