/////////////////////////////////// Q2: Babbar450 : Maximum-minimum element in array /////////////////////////////
//Write a function to return minimum and maximum in an array. You program should make minimum number of comparisons.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace ::std;

//////////////////////////// Solution 1  ///////////////////////////////
void getMaxMin(int input[], int size, int &min, int &max)
{
    min = input[0];
    max = input[0];

    for (int i = 1; i < size; i++)
    {
        if (input[i] > max)
        {
            max = input[i];
        }
        else if (input[i] < min)
        {
            min = input[i];
        }
    }
}

/*///////////////
since we are traversing only once, time Complexity will be O(n).,
////////////////*/

////////////////////////////// Solution 2 (Divide & Conquer) ///////////////////////////
struct maxmin
{
    int min;
    int max;
};
typedef struct maxmin Result;

Result getMinMax(int input[], int start, int end)
{
    int mid = (start + end) / 2;
    Result res, resL, resR;

    if (end > start)
    {
        resL = getMinMax(input, start, mid);
        resR = getMinMax(input, mid + 1, end);

        if (resL.min < resR.min)
            res.min = resL.min;
        else
            res.min = resR.min;

        if (resL.max > resR.max)
            res.max = resL.max;
        else
            res.max = resR.max;

        return res;
    }
    else
    {
        res.min = input[start];
        res.max = input[start];
        return res;
    }
}
/*////////////////
getMinMax function is dividing  the array into two parts at each level. function call will be doubles at each level.
each function call is doing exactly 3 comparision irrespective of array size passed to it except last level, on last level each function call is doing only one comparision.

hence complexity of each function call at any level is O(1).
there will be total log n levels of call since array is dividing into half.

for example if we have array of size 4. at level 0 there will be 1 call for getMinMax function, at level 1 there will be 2 calls and at level 2 there will be 4 calls.
        total time complexity = O(1) + 2*O(1) + 4*O(1) + ....
                              = O(1) * (2^0 + 2^1 + ..... + 2^log n)
                              = O(1) * [1 * ((2^log n)-1) / (2-1)]
                              = O(1) * [(n-1)/1]
                              = O(1) * (n-1)
                              = O(n)

////////////////*/
int main()
{
    int input[] = {1, 7, 19, 11, 64, 14};
    int size = sizeof(input) / sizeof(int);
    /*  //for solution 1.
    int min = 0;
    int max = 0;

    getMaxMin(input, size, min, max);
    cout << "min: " << min << " max: " << max << endl;
*/

    //for solution 2
    Result res = getMinMax(input, 0, size - 1);
    cout << "min: " << res.min << " max: " << res.max << endl;
}

/*////////////////
other solution is to sort the array and take values as min = input[0], max=input[size-1];
but for this Time Complexity will be O(n * log n).
///////////////*/