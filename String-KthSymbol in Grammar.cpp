/*///////////// Q 67: Babbar450: Find Kth Symbol in a Grammar //////////////
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].
//////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*///////////////////// Solution (Recursive) ////////////////
if n = 4 then we will have 4 rows as following,
    0
    01
    0110
    01101001

Here we can see that any row after 1st row, second Half of the string is
bitwise not of its first half or its previous row since first half of any 
row is same as the complete previous row.

so if we want to find Kth element in Nth row we have two cases,
case 1: k is present in the first half of the row.
    in this case we can search k in previous row wwhich is smaller in size

case 2: k is present in 2nd half of the row.
    in this case we can search (k-mid)th element in previous row, which will 
    be bit wise opposit of the actual result, so we will do bit wise NOT of 
    the search result.

for exaample if we want to find 3rd element in  4th row,
    total elements will be 2^(n-1) = 2^3 = 8
    mid = 8/2 = 4
    first half will be 1 to 4 and second half will be 5 to 8.

    since k <=4, its in first half of the row, we can call following function
        return find(N-1, k)

if we want to fine 6th element in 4th row, 
    since 6 > mid, it is present in second half of the row.
    elements present in the previous row are just opposite of 2nd half of the row
    we can search k-mid th element in previous row and perform bitwise not on the 
    result.
        return ! find(N-1, k-mid)
    =>  return ! find(3, 6-4) 
    =>  return ! find(3, 2)
    =>  return ! 1 
    =>  return 0;
        
Here Base condition is as following
1.  when N = 1, it is indicating row 1, in row 1 we have only one element which is 
    0 so we will return that.
2.  when k = 1, it is indicating 1st element of the row, which will always be 0. so 
    we can return 0 in this case also.

    if(N == 1 || k == 1)
        return 0;


///////////////////////////////////////////////////////////*/

int findInGrammar(int n, int k)
{
    if (n == 1 || k == 1)
        return 0;

    int mid = pow(2, (n - 1)) / 2;

    if (k <= mid)
        return findInGrammar(n - 1, k);
    else
        return !findInGrammar(n - 1, k - mid);
}

int main()
{
    int n;
    int k;
    cin >> n >> k;

    int result = findInGrammar(n, k);
    cout << result << endl;
}