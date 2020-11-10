/*////////////////////////////////////// Q 22: Babbar450 : Factorial of Large Number //////////////////////////////////
Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////// solution 1 //////////////////////////////////////////////
since factorial of a larger number will be a very large number that an int or a long can not hold
we can store digits of each multiplication in an array.

to store the number we can find remainder from multiplication result for every n*n-1*n-2...
the remainder we'll calculate for 10 to get last digit.

step 1. set arr[0] = 1 and do following for i = 2 to N
step 2. multiply i with each number present in arr and divide by 10. 
step3. put remainder in arr[j] and keep quotient stored. add quotient 
to the next multiplication and repeat step 2 and 3.
*/
///////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num = 25;

    int divisor = 10;

    vector<int> result;

    result.push_back(1);
    for (int i = 2; i <= num; i++)
    {
        int quotient = 0;
        for (int j = 0; j < result.size(); j++)
        {
            int temp = result[j] * i + quotient;
            result[j] = temp % divisor;
            quotient = temp / divisor;
        }
        while (quotient > 0)
        {
            result.push_back(quotient % divisor);
            quotient /= divisor;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
}