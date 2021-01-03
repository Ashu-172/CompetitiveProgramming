/*/////////////////// Q 282: Babbar450: Next larger element ////////////////////
Given an array A[] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.

Next greater element of an element in the array is the nearest element on the right which is greater than the current element.

If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
Example 2:

Input: 
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1 , for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.
Your Task:
This is a function problem. You only need to complete the function nextLargerElement that takes array and n as parameters and returns an array of length n denoting the next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= N <= 10^6
1 <= Ai <= 10^18
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/////////////////////////// Solution 1 (Brute Force) //////////////////////////
vector<long long> nextLarger(long long arr[], int n)
{
    vector<long long> result;
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        for (; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                result.push_back(arr[j]);
                break;
            }
        }
        if (j == n)
            result.push_back(-1);
    }
    result.push_back(-1);
    return result;
}

/////////////////////////// Solution 2 (using Extra space) ////////////////////
/*
in the brute force approach we are iterating over the array for each element, which is making it O(n^2) solution.

we can optimize it by using extra space. we can start from end of the vector and keep on storing position of next larger number in the next array. in this ay when we'll check next larger element for a number, first we'll check if next number itself is next larger. if not then we'll check next larger number of the next number directly instead of checking other numbers which we have laready checked for next number.

Ex:
input [1 3 2 4]   i=2
next  [      -1]
1. check for index 2, next element is 4 hich is also next largest,so we'll put index 3 in next array for index 2 indicating next larger element for index 2 is present  at index 3.

input [1 3 2 4]   i=1
next [     3 -1]
2. check for index 1, next element is 2 which is not larger that current element 3, so we'll check next larger for next element, next larger for next element is present at index 3, as we can see in next array at index 2.
    this value is also larger than current element 2  (4>2), so we'll put its index in next array at index 1

input [1 3 2 4]
next [   3 3 -1]
3. check for index 0, next element is 3 which is larger than 1, so we'll put index 1 at index 0 in next array.
input [1 3 2 4]
next  [1 3 3 -1]

In above steps whenever we found larger element for current element, we can put that element in result vector. this vector will have result in reverse order since we are traversing from back, we need to reverse it which we can do using double pointer approach or using stack.

we can also use next array to prepare result vector at the end.
vector<int> result;
for(int i=0;i<n;i++)
{
    if(next[i] == -1)
        result.push_back(-1)
    else
        result.push_back(input[next[i]]);
}
*/
vector<long long> nextLargerElement(long long arr[], int n)
{
    int next[n];
    vector<long long> result;
    stack<long long> temp;
    next[n - 1] = -1;
    temp.push(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        int j = i + 1;
        while (j != -1)
        {
            if (arr[j] > arr[i])
            {
                next[i] = j;
                temp.push(arr[j]);
                break;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == -1)
        {
            next[i] = j;
            temp.push(j);
        }
    }
    while (temp.empty() != true)
    {
        result.push_back(temp.top());
        temp.pop();
    }
    return result;
}

int main()
{

    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //vector<long long> res = nextLargerElement(arr, n);
    vector<long long> res = nextLarger(arr, n);
    for (long long i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}