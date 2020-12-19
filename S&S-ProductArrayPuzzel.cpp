/*///////////////////// Q 105: Babbar450: Zero Sum Sub Array ///////////////////
Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all the elements of A except A[i].

Example 1:

Input:
N = 5
A[] = {10, 3, 5, 6, 2}
Output: 180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
 
Example 2:

Input:
N = 2
A[] = {12,0}
Output: 0 12

Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array A[] and N as input parameters and returns a list of N integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 1000
0 <= Ai <= 200
Array may contain duplicates.
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;
//////////////////////////// Solution (Best Approach) ////////////////////////
/*
1). we can iterate over the array and calculate the product of the complete array.
    But we should note that if any input[i] value is 0 then we should not mutiply 
    it with product, it'll make complete product = 0.

2). now since we have product of the complete array, we can iterate over the array 
    again and divide the product by input[i] to get the product of arrar excluding 
    current number itself.
    But if any input[i] value is 0, then we can not divide the product, it'll give 
    infinite result or arithmatic exception.
    we actually don't need to divide the product if there any 0 is present in the 
    input, because product for all the elements ill become 0.
    There are three cases for presence of 0.
    a) if there is no 0 present in the input:
        in this case we'll simply traverse the array and get the result for each 
        index by dividing product by input[i].
    b) if there is one occurrence of 0 is present:
        in this case all the values in the result will be 0, except the index where 
        0 is present, for this product value will be the result.
    c) if there are more than one occurrence of 0 present in the input:
        in this case products in the result array for all the elements will be 0.
*/
vector<long long int> productExceptSelf(vector<long long int> &input, int size)
{
    long long int product = 1;
    vector<long long int> result;
    int zeroCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] != 0)
            product = product * input[i];
        else
            zeroCount++;
    }
    if (zeroCount == 0)
        for (int i = 0; i < size; i++)
            result.push_back(product / input[i]);
    else if (zeroCount == 1)
        for (int i = 0; i < size; i++)
            if (input[i] == 0)
                result.push_back(product);
            else
                result.push_back(0);
    else
        for (int i = 0; i < size; i++)
            result.push_back(0);

    return result;
}

int main()
{
    vector<long long int> input{10, 3, 5, 6, 2};
    int size = input.size();

    vector<long long int> result = productExceptSelf(input, size);

    for (long long int num : result)
    {
        cout << num << " ";
    }
}
