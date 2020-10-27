/*////////////////////// Q 11: Babbar450 : Find Duplicate in an Array of size N+1 /////////////////////////////
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one duplicate number in nums, return this duplicate number.
NOTE: one number duplicateddoesn't mean that it will come only twice, it can come any number of time (max n+1) times
but it will be int the range 1-n.  eg [2, 2, 2, 2] is valid.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/////////////////////Solution 1 ////////////////////////
// O(n^2) solution
int getDuplicate(vector<int> &input)
{
    int size = input.size();
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (input[i] == input[j])
                return input[i];
}

// Sorting based solution Time Complexity O(n log n)
int getDuplicateSort(vector<int> &input)
{
    sort(input.begin(), input.end());
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == input[i + 1])
            return input[i];
    }
}

// use hash tables to maintain counts
int getDuplicates(vector<int> &input)
{
    unordered_map<int, int> counter;

    for (int i = 0; i < input.size(); i++)
    {
        unordered_map<int, int>::iterator itr = counter.find(input[i]);
        //if element is present increment if not then initialize with 0 then increment
        if (counter[input[i]] == 1)
            return input[i];
        counter[input[i]]++;
    }
    return -1;
}
#if 0
int getDuplicateTortoiseHare(vector<int> &input)
{
    int size = input.size();
    int intersection = 0;
    //start from first position (0th location)
    //NOTE: don't initialize with 0, it'll waste one step for both
    // and positions will be incorrect for both
    for (int hare = input[0], tortoise = input[0]; hare < size, tortoise < size;)
    {
        int tortoiseIndex = tortoise; //storing tortoise index, it'll give intersection index
        hare = input[input[hare]];    // taking two steps
        tortoise = input[tortoise];

        if (tortoise == hare)
        {
            intersection = tortoiseIndex;
            break;
        }
    }
    cout << intersection << endl;
    //tortoise starting from index 0 again and hare starting from intersect point
    for (int tortoise = input[0], hare = input[intersection]; tortoise < size, hare < size;)
    {
        //checking in starting because if cycle starts from index 0, itt should be detected
        if (tortoise == hare) //meeting at entrance of cycle
            return tortoise;  //or hare

        cout << "hare: " << hare << " tortoise: " << tortoise << endl;
        hare = input[hare]; //taking one step at a time
        tortoise = input[tortoise];
    }
    return -1;
}
#endif

int getDuplicateTortoiseHare(vector<int> &input)
{
    int size = input.size();
    //start from first position (0th location)
    //NOTE: don't initialize with 0, it'll waste one step for both
    // and positions will be incorrect for both
    int hare = input[0], tortoise = input[0];
    while (hare < size && tortoise < size)
    {
        hare = input[input[hare]]; // taking two steps
        tortoise = input[tortoise];

        if (tortoise == hare)
            break;
    }
    //tortoise starting from index 0 again and hare starting from intersection point
    tortoise = input[0];
    while (tortoise < size && hare < size)
    {
        //checking in start, bcz cycle may occur on first place (0th index)
        if (tortoise == hare) //meeting at entrance of cycle
            return tortoise;  //or hare

        hare = input[hare]; //taking one step at a time
        tortoise = input[tortoise];
    }
    return -1;
}

int main()
{
    vector<int> input{3, 1, 3, 4, 2};
    int size = sizeof(input) / sizeof(int);

    //int duplicate = getDuplicate(input);

    //cout << duplicate;

    //cout << getDuplicateSort(input) << endl;

    //cout << getDuplicates(input) << endl;

    cout << getDuplicateTortoiseHare(input) << endl;
}