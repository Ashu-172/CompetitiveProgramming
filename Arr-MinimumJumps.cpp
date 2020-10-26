/*////////////////////// Q 10: Babbar450 : Minimum Number of Jumps /////////////////////////////
Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

int getMinJump(int input[], int size, int start)
{
    int minJumps = -1, jumps = -1;

    // if we can directly jump from current position to end return 1 as number of Jumps required
    if (start + input[start] >= size - 1)
    {
        return 1;
    }

    //iterating for all the possible jumps from current position
    for (int j = 1; (j <= input[start]) && (start + j < size); j++)
    {

        jumps = getMinJump(input, size, start + j);

        // if possible to reach end from start+j th location
        if (jumps != -1)
        { // setting minimum jump value to jump if minJumps is -1 or minJumps > jumps
            if (minJumps == -1 || minJumps > jumps)
                minJumps = jumps;
        }
    }
    // if end is reachable from any of the 1-jump reachable points we'll have
    // minimum of all the possible minimum jumps from all the 1-jump rechable points.
    // if end is not reachable we'll have -1 as minJump

    if (minJumps == -1)
        return -1;
    else
        // adding one jump using which we reached above 1-jump reachable positions
        minJumps += 1;

    return minJumps;
}

int getMinJumpDp(int input[], int size, int minJumpStore[], int start)
{
    int minJumps = -1, jumps = -1;

    // if we can directly jump from current position to end return 1 as number of Jumps required
    if (start + input[start] >= size - 1)
    {
        minJumpStore[start] = 1; // store required jump in the store before return
        return 1;
    }

    //iterating for all the possible jumps from current position
    for (int j = 1; (j <= input[start]) && (start + j < size); j++)
    {
        if (minJumpStore[start + j] != 0)
            jumps = minJumpStore[start + j];
        else
            jumps = getMinJumpDp(input, size, minJumpStore, start + j);

        // if possible to reach end from start+j th location
        if (jumps != -1)
        { // setting minimum jump value to jump if minJumps is -1 or minJumps > jumps
            if (minJumps == -1 || minJumps > jumps)
                minJumps = jumps;
        }
    }
    // if end is reachable from any of the 1-jump reachable points we'll have
    // minimum of all the possible minimum jumps from all the 1-jump rechable points.
    // if end is not reachable we'll have -1 as minJump

    if (minJumps == -1)
    {
        minJumpStore[start] = -1;
        return -1;
    }
    else
    { // adding one jump using which we reached above 1-jump reachable positions
        minJumps += 1;
    }

    minJumpStore[start] = minJumps;
    return minJumps;
}

int main()
{
    int input[] = {1, 4, 3, 2, 6, 7};
    int size = sizeof(input) / sizeof(int);

    int jumpStore[size] = {0};

    int minJump = getMinJumpDp(input, size, jumpStore, 0);

    cout << minJump << endl;

    minJump = getMinJump(input, size, 0);
    cout << minJump << endl;
}