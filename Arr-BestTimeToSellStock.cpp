/*////////////////////////////////////// Q 17: Babbar450 : Best timr to sell stock. //////////////////////////////////
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;
/////////////////////////////////// Solution 1 //////////////////////////////////////
//brute force approach TimeComplexity = O(n^2)
int getMaxProfit(int input[], int size)
{
    int profit = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[j] - input[i] > profit)
                profit = input[j] - input[i];
        }
    }
    return profit;
}

////////////////////////////////// Solution 2 //////////////////////////////////////
int getMaximumProfit(int input[], int size)
{
    int cMin = 0, gMin = 0, cDiff = 0, gDiff = 0, high = 0;
    // searching for first Heighest point from end
    int i = size - 1;

    if (size == 0 || size == 1)
        return 0;
    // getting first high from the end of graph
    while (i > 0)
    {
        if (input[i - 1] < input[i])
        {
            high = input[i];
            break;
        }
        i--;
    }

    cMin = high;
    gMin = high;
    cDiff = 0;
    gDiff = 0;

    for (int j = i - 1; j > 0; j--)
    {
        //if we found any higher point than current high, capture the
        //current max Differnce and reset currents high and min points
        if (input[j] > high)
        {
            //        gDiff = cDiff;
            high = input[j];
            cMin = high;
        }
        // if encounter uptrend from back to front (<--) its a current Min point
        // calculate the difference. if current diff is greater than global diff
        // assign the diff to global diff.
        // if two values are equal before uptreand, condition should be true
        if ((input[j - 1] > input[j]) && (input[j] <= input[j + 1]))
        {
            cMin = input[j];
            cDiff = high - cMin;
        }
        if (cDiff > gDiff)
        {
            gMin = cMin;
            gDiff = cDiff;
        }
    }
    // here j =0, for 0th index check if it is giving the max diff or not
    // <= because last to values can be same also
    if (input[0] <= input[1])
    {
        cDiff = high - input[0];
        if (cDiff > gDiff)
            gDiff = cDiff;
    }
    return gDiff;
}
//Time Complexity is O(n) for this solution.

//////////////////////////////////// solution 3 (easiest solution) /////////////////////////////
/*
The points of interest are the peaks and valleys in the given graph. We need to find the largest peak following the smallest valley. We can maintain two variables - minprice and maxprofit corresponding to the smallest valley and maximum profit (maximum difference between selling price and minprice) obtained so far respectively.
*/
int getMaximumProfit3(int input[], int size)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < size; i++)
    {
        if (input[i] < minPrice)
            minPrice = input[i];
        else if (input[i] - minPrice > maxProfit)
            maxProfit = input[i] - minPrice;
    }
    return maxProfit;
}

///////////////////////////////////// solution 4  (Kadane's Algorithm) //////////////////////////////////////
/*
Suppose we have original array:
[a0, a1, a2, a3, a4, a5, a6]

what we are given here(or we calculate ourselves) is:
[b0, b1, b2, b3, b4, b5, b6]

where,
b[i] = 0, when i == 0
b[i] = a[i] - a[i - 1], when i != 0

suppose if a2 and a6 are the points that give us the max difference (a2 < a6)
then in our given array, we need to find the sum of sub array from b3 to b6.

b3 = a3 - a2
b4 = a4 - a3
b5 = a5 - a4
b6 = a6 - a5

adding all these, all the middle terms will cancel out except two
i.e.

b3 + b4 + b5 + b6 = a6 - a2

a6 - a2 is the required solution.

so we need to find the largest sub array sum to get the most profit
*/

int KadaneMaxProfit(int input[], int size)
{
    int maxCurr = 0;
    int maxSoFar = 0;

    for (int i = 1; i < size; i++)
    {
        maxCurr += input[i] - input[i - 1];
        if (maxCurr < 0)
            maxCurr = 0; // if sum of diff became negative reset sum
        if (maxSoFar < maxCurr)
            maxSoFar = maxCurr;
    }
    return maxSoFar;
}

int main()
{
    int input[] = {5, 5, 4, 9, 3, 8, 5, 5, 1, 6, 8, 3, 4};
    int size = sizeof(input) / sizeof(int);

    int profit = getMaxProfit(input, size);
    cout << profit << endl;
    profit = getMaximumProfit(input, size);
    cout << profit << endl;
    profit = getMaximumProfit3(input, size);
    cout << profit << endl;
    profit = KadaneMaxProfit(input, size);
    cout << profit << endl;
}