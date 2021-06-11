/*////////////////////////////////// Q 266: Babbar450: Combination Sum ///////////////////////////////////
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.


Example 1:

Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)
Example 2:

Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Your Task:
Your task is to complete the function combinationSum() which takes the array A and a sum B as inputs and returns a list of list denoting the required combinations in the order specified in the problem description. The printing is done by the driver's code. If no set can be formed with the given set, then  "Empty" (without quotes) is printed.

Expected Time Complexity: O(X^2 * 2^N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2^N)

Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100

////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//////////////////////////////////////////////////// Solution /////////////////////////////////////////////
/*
Here we need to find all possible combinations for which sum is equal to the given value B so we can use backtracking. here there are some given conditions
1. numbers can be repeated so we need to iterate over all the numbers even if they are already visited and added in the combination.
2. all the combinations needs to be in ascending order, in order to achieve it we need to sort the input.
3. one thing to observe here is if any number is repeated in the input array, we'll get same combination repeated in the result for example is input is [1, 8, 8] and B=9 then we'll have two combinations in result one is [1,8] for index (0, 1). And another combination is also [1, 8] for index (0,2). To handle that we need to keep distinct values in the input vector, duplicate values should be removed.


Algorithm:
1. Sort the given array and copy distinct values in an array which will be used as input.
2. iterate over the input array from the given index and recursively try out all the combinations while adding current num in the sum.
3. when sum is equal to B we found a combination so insert the combination in the result vector.
4. if sum is greater than the given value B, then moving further will not lead to any combination with sum equal to B since sum is already greater than B, so we can return from here.

Time complexity for this solution will be O(X * 2^N) where X is average of all B/input[i] values.
Since maximum level of recursion will be B/input[0] where input[0] is smallest number so in worst case X will be B/input[0] but in avrg case we can take average of B/input[i]. for each number we have two choices, either we'll take it or not. so complexity will be multiplied by 2^N where N is distinct numbers.
final time complexity will be O(X * 2^N)
*/
void findAllCombinations(vector<int> &A, int B, int index, int sum, vector<vector<int>> &result, vector<int> &comb)
{
    if (sum == B)
    {
        result.push_back(comb);
        return;
    }

    // if current combination can not lead to answer, return
    if (sum > B)
        return;

    for (int i = index; i < A.size(); i++)
    {
        comb.push_back(A[i]);
        findAllCombinations(A, B, i, sum + A[i], result, comb);
        comb.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> result;
    sort(A.begin(), A.end());
    vector<int> input;

    // only keeping distinct elements in the input
    input.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        // skipping duplicates
        if (A[i] != A[i - 1])
            input.push_back(A[i]);
    }

    vector<int> combination;
    findAllCombinations(input, B, 0, 0, result, combination);

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int sum;
    cin >> sum;
    vector<vector<int>> result = combinationSum(A, sum);
    if (result.size() == 0)
    {
        cout << "Empty";
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << '(';
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << " ";
        }
        cout << ")";
    }
    cout << "\n";
}