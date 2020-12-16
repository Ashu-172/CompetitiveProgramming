/*///////////////// Q 97: Babbar450: Majority Element //////////////////
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Example 1:

Input:
N = 3 
A[] = {1,2,3} 
Output: -1

Explanation: Since, each element in 
{1,2,3} appears only once so there 
is no majority element.
Example 2:

Input:
N = 5 
A[] = {3,1,3,3,2} 
Output: 3
Explanation: Since, 3 is present 
more than N/2 times, so it is 
the majority element.
Your Task:
The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^7
0 <= A[i] <= 10^6
//////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

int findCandidate(int n, int input[])
{
    int count = 1;
    int majIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (input[i] == input[majIndex])
            count++;
        else
            count--;

        if (count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }
    return input[majIndex];
}

bool isMajority(int n, int input[], int candidate)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == candidate)
            count++;
    }
    if (count > n / 2)
        return true;
    return false;
}

int findMajorityNum(int n, int input[])
{
    int candidate = findCandidate(n, input);
    if (isMajority(n, input, candidate))
    {
        return candidate;
    }
    return -1;
}
int main()
{
    int n = 5;
    int input[] = {3, 1, 3, 3, 2};

    cout << findMajorityNum(n, input) << endl;
}
/* // when elemnts range from 0 to n only
int majorityElement(int input[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(input[i] >= 0)
        {
            if(input[input[i]] >=0)
                input[input[i]] = -1;
            else
                input[input[i]]--;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(input[i] <= -(n/2) )
            return i;
    }

    return -1;
    
}
*/
