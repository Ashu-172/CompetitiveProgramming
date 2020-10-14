/*//////////////////// CtCI V-Example 16 Problem Statement //////////////////
Function to print powers of 2 from 1 through n (includive). For example, if n is 4, it would print 1,2 and 4.
*/
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Code Written By Me
void print2Pow(int num)
{
    int output = 1;

    cout << output << endl;
    if (num != 0)
    {
        while (num >>= 1)
        {
            output = output << 1;
            cout << output << endl;
        }
    }
}

//Code Given in the Book
int powerof2(int n)
{
    if (n == 0 || n == 1)
    {
        cout << 1 << endl;
        return 1;
    }
    else
    {
        int prev = powerof2(n / 2);
        int curr = prev * 2;
        cout << curr << endl;
        return curr;
    }
}

int main()
{
    int input = 0;
    cin >> input;
    auto start = high_resolution_clock::now();
    print2Pow(input);
    //powerof2(input);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time: " << duration.count() << endl;

    return 0;
}
/*////////////////////////////////////////////

input: 999999999
output:
1
2
4
8
16
32
64
128
256
512
1024
2048
4096
8192
16384
32768
65536
131072
262144
524288
1048576
2097152
4194304
8388608
16777216
33554432
67108864
134217728
268435456
536870912
Time: 61206


Runtime:
any number n requires log(n) bits to represent it in binary form.
Solution 1.
In this code we are using binary form of the number and shifting it right to check how many bits it took in total.
since each number takes log(n) bits, loop will iterate exactly log(n) times. 
                    Time Complexity = O(log n).

Solution 2.
in this code we are dividing number by 2 and calling function recursively, we are using binary search approach.
since each time number is divided by 2, log(n) times function will be called. other operations in function are of O(1).
                    Time Complexity = O(log n)
*/
