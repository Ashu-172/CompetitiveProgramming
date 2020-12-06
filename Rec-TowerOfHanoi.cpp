/*///////////// Recursion:Aditya Verma: Tower of Hanoi //////////////
The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

Input:
The first line of input is T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Output:
For each testcase, print the steps and the total steps taken.

Constraints:
1 <= T <= 16
1 <= N <= 16

Example:
Input:
2
2
3
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7
//////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

void move(int n, int S, int H, int D, int &count)
{
    count++; // moving 1 disk in each call, increasing count
    if (n == 1)
    {
        cout << "moving Disk " << n << " From " << S << " to " << D << endl;
        return;
    }
    move(n - 1, S, D, H, count); // moving n-1 disks  from S to H
    //move(1, S, H, D, count);     // moving last disk at source S to D
    cout << "moving Disk " << n << " From " << S << " to " << D << endl;
    move(n - 1, H, S, D, count); // Moving Disks from
}

int main()
{
    int n;
    cin >> n;
    int S = 1;
    int H = 2;
    int D = 3;
    int count = 0;
    move(n, S, H, D, count);
    cout << count << endl;
}