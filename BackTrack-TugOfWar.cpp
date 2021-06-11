/*////////////////////////////////// Q 264: Babbar450: Tug of War ///////////////////////////////////
Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference 
of the sum of two subsets is as minimum as possible. If n is even, then sizes of two subsets must be 
strictly n/2 and if n is odd, then size of one subset must be (n-1)/2 and size of other subset must 
be (n+1)/2.

For example, let given set be {3, 4, 5, -3, 100, 1, 89, 54, 23, 20}, the size of set is 10. Output 
for this set should be {4, 100, 1, 23, 20} and {3, 5, -3, 89, 54}. Both output subsets are of size 
5 and sum of elements in both subsets is same (148 and 148).

another example where n is odd. Let given set be {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}. The 
output subsets should be {45, -34, 12, 98, -1} and {23, 0, -99, 4, 189, 4}. The sums of elements in 
two subsets are 120 and 121 respectively.
///////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;
///////////////////////////////////////////////////////// Solution ////////////////////////////////////////////////////
/*
The idea here is to try out every possible subset of size n/2 calculate the difference of sum of this subset and the remaining part of the array.
maintain a global min sum difference and compare this calculated sum difference. if it isminimum then capture the current arrangement of the numbers in the subsets.
After trying out all the possible combinations return the subsets based on the final arrangement which was captured for minimum sum difference of the subsets.

Algorithm:
1.  initialize the sum of the left subset with 0 and right subset with total sum. in the starting left subset is empty and the right subset has all the numbers. also initialize count with 0 which is indicating the number of elements in left subset.
2.  Initialize a merker array with 0, which will show the arrangement of the numbers in the sets. if at ith index in this array value stored is 1 then it means ith number from the input array is present in the left subset, if it is 0 then ith input value is in right subset.
3.  To try out all the possible subsets,iterate from i=0 to n and do following:
        a. put ith number in left subset by marking it in marker array.
        b. call the function recursively with increased count, and updated values of left and right sum, since we have put one number in the left subset, count should be increased. each level of recursive call will put one number in the left subset from right subset.
        c. move ith number from left subset to right subset back by marking it with 0 again. it will discard the affect of previous steps made for ith number.
4.  The base condition is when the left subset size becomes n/2, in this case we need to check whether the differece between left subset sum and right subset sum is lesser than the minimum difference or not. if it is then we found a set of numbers which can be the final solution, so we need to capture the current configuration of the numbers by copying marker array to result array and return from here.

Time complexity:
    Here we have n choices for each position in the left vector (technically it is n then n-1 then n-2 and so on but for Big-O time  complexity calculation we can assume it n) and the there will be n/2 levels of recursion since we need to put n/2 numbers in left subset from the right subset. So the time complexity will be O((n/2)^n)

Space Complexity:
Space complexity for this solution will be O(n) since we are maintaining an array of size n for marking the subset configurations.
*/
void findMinSumDiffPartition(vector<int> input, int n, int marker[], int &minDiff, int sumL, int sumR, int count, int result[])
{
    if (count == n / 2)
    {
        if (abs(sumL - sumR) < minDiff)
        {
            minDiff = abs(sumL - sumR);
            for (int i = 0; i < n; i++)
                result[i] = marker[i];
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (marker[i] == 0)
        {
            marker[i] = 1;
            findMinSumDiffPartition(input, n, marker, minDiff, sumL + input[i], sumR - input[i], count + 1, result);
            marker[i] = 0;
        }
    }
}

void TOW_util(vector<int> input, int n, vector<int> &left, vector<int> &right)
{
    int sumL = 0;
    int sumR = 0;
    int marker[n] = {0};
    int result[n] = {0};

    for (int num : input)
        sumR += num;

    int minDiff = INT_MAX;
    int count = 0;
    findMinSumDiffPartition(input, n, marker, minDiff, sumL, sumR, count, result);

    for (int i = 0; i < n; i++)
    {
        if (result[i] == 1)
            left.push_back(input[i]);
        else
            right.push_back(input[i]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> input;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }
    vector<int> left, right;
    TOW_util(input, n, left, right);

    for (int num : left)
        cout << num << " ";
    cout << endl;
    for (int num : right)
        cout << num << " ";

    return 0;
}
