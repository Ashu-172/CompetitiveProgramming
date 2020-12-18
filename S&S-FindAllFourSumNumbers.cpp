/*////////////////////////// Q 100: Babbar450: Find All Four Sum Numbers ////////////////////////
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100
///////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

////////////////////////////////////// Solution 1 /////////////////////////////////
/*
first we'll sort the array. 
using three loops we'll find a+b+c and subtract it from k.
then result value can be searched in remaining array using binary search algorithm.

Time complexity for this solution is O(n^3 log n)
Space complexity for this solution is O(n) in worst case when all elements are part of result.
In best case space complexity will be much more lesser.
*/
vector<vector<int>> fourSum(vector<int> input, int num)
{
    sort(input.begin(), input.end());
    int size = input.size();

    // to maintain uniqueness we'll insert all result vectors in a set of vector<int>
    set<vector<int>> resultSet;
    for (int i = 0; i < size - 3; i++)
        for (int j = i + 1; j < size - 2; j++)
            for (int k = j + 1; k < size - 1; k++)
            {
                int val = num - (input[i] + input[j] + input[k]);
                if (binary_search(input.begin() + k + 1, input.end(), val))
                {
                    vector<int> temp;
                    temp.push_back(input[i]);
                    temp.push_back(input[j]);
                    temp.push_back(input[k]);
                    temp.push_back(val);
                    resultSet.insert(temp);
                }
            }

    // Converting result  set to a vector<vector<int>>
    vector<vector<int>> result(resultSet.begin(), resultSet.end());
    return result;
}

/////////////////////////// Solution 2 //////////////////////////////
/*
1. first we'll sort the array.
2. using two loops we can fix values of a and b and then in the remaining array
we can use two pointer approach to find out values of c and d.
3. we'll set one pointer low to next index from b and aanother pointer high to size-1
4. if a+b+input[low]+input[high] is equals to k then we'll insert these values in the vector 
4. if sum is larger than k we'll move high to high -1
5. if sum is lower than k we'll move low to low +1

Time Complexity = O(n^3)
Space Complexity = O(n^2) in worst case.
*/
vector<vector<int>> fourSumOptimized(vector<int> input, int num)
{
    sort(input.begin(), input.end());
    int size = input.size();
    set<vector<int>> resultSet;
    for (int i = 0; i < size - 3; i++)
        for (int j = i + 1; j < size - 2; j++)
        {
            int low = j + 1;
            int high = size - 1;
            while (low < high)
            {
                int sum = input[i] + input[j] + input[low] + input[high];
                if (sum == num)
                {
                    vector<int> temp{input[i], input[j], input[low], input[high]};
                    resultSet.insert(temp);
                    low++;
                    high--;
                }
                else if (sum > num)
                    high--;
                else
                    low++;
            }
        }
    vector<vector<int>> result(resultSet.begin(), resultSet.end());
    return result;
}

//////////////////////////// Solution 3 /////////////////////////////
/* 
we can make unique pairs of numbers from the array and store them with their sum value either using a map where key will be the sum, or using an array of a class having sum and pair values.
Now our task is to find combinations of the pairs whose sum equals to num. it can be done using two pointer approach which we have used in Solution 2. for that we need to sort the array first.

Since two pairs can have a common num example [3,2,1,6,0] and num=9
pairs(3,1) and (3,2) also sum up to 9, but 3 is repeating here, to avoid this we'll put all the elements in a temp set and then if its size is 4 then only will put it in vector<int>.
To get unique result of vectors we'll put all the vectors in a set, and then will convert set<vector> to vector<vector> and return.

Time complexity for ths solution is O(n^2 log n^2) = O(n^2 log n). since we are sorting array of size n*(n-1).
Space complexity for this solution is O(n^2)

This solution only works when all elements are unique in the input array.
*/
class pairSum
{
public:
    int first, second;
    int sum;
};
vector<vector<int>> fourSumWithMap(vector<int> input, int num)
{
    int size = input.size();
    int pairs = size * (size - 1) / 2;

    set<vector<int>> resultSet;
    pairSum arr[pairs];
    int k = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            arr[k].sum = input[i] + input[j];
            arr[k].first = input[i];
            arr[k].second = input[j];
            k++;
        }

    // sorting array, using lambda function for comparision
    // Refer: https://stackoverflow.com/a/12823634/8416962
    sort(arr, arr + pairs, [](pairSum const &a, pairSum const &b) -> bool {
        return a.sum < b.sum;
    });

    int low = 0, high = pairs - 1;

    while (low < high)
    {
        if (arr[low].sum + arr[high].sum == num)
        {
            set<int> tempSet;
            tempSet.insert(arr[low].first);
            tempSet.insert(arr[low].second);
            tempSet.insert(arr[high].first);
            tempSet.insert(arr[high].second);

            // if elements are not duplicate
            if (tempSet.size() == 4)
            {
                vector<int> temp(tempSet.begin(), tempSet.end());
                resultSet.insert(temp);
            }
            low++;
            high--;
        }
        else if (arr[low].sum + arr[high].sum > num)
            high--;
        else
            low++;
    }
    vector<vector<int>> result(resultSet.begin(), resultSet.end());
    return result;
}

int main()
{
    int num = 23;
    vector<int> input = {10, 2, 3, 4, 5, 7, 8};

    //vector<vector<int>> result = fourSum(input, num);
    //vector<vector<int>> result = fourSumOptimized(input, num);
    vector<vector<int>> result = fourSumWithMap(input, num);

    for (vector<int> temp : result)
    {
        for (int n : temp)
            cout << n << " ";
        cout << "$ ";
    }
}