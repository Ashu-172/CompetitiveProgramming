/*//////////////////////////// Q 20: Babbar450 : Rearrange array in alternating positive & negative  /////////////////////////
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa. Order of elements in output doesn’t matter. Extra positive or negative elements should be moved to end.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*/////////////////////////////// Solution 1 : Double Pointer Approach ///////////////////////////////
we'll use double pointer approach for this problem, one pointer P will point
to next positive number and other pointer N will point to next negative number.

now we have two conditions here
1. if P < N, it is indicating that first positive number is present before 
    first negative number( any number of positive numbers can be present in between)
    eg [7,2,4,-1,-2]
    
    in this case we need to check if next number (at P+1) is also positive, if so then
    it should be replaced by negative number (pointed by P), and then P and N should be 
    moved to their next position.

2. if N < P, it is indicating that first negative number is present before first
    positive number (any number of negative numbers can be present in between).
    eg [-7,-2,-4,1,2]

    in this case we need to swap Number pointed by N with Number pointed by P, regardless
    of next number's value, because negative can not come in start.
    now if next number is also negative then we need to leave it as it is because previos
    number we have swapped with positive.
    now we can move P and N to their next values to follow same procedure.
    
if there is no more negative or positive numbers left in the array, we can leave 
rest of the elements as it is in the array, so that additional positiove or negative
numbers will come at the end.

Time complexity for this solution will be O(n) and space  complexity is O(1).
////////////////////////////////////////////////////////////////////////////////////////////////// */

#include <iostream>

using namespace std;

int getNextN(int input[], int size, int N)
{
    for (int i = N + 1; i < size; i++)
    {
        if (input[i] < 0)
            return i;
    }
    return -1;
}

int getNextP(int input[], int size, int P)
{
    for (int i = P + 1; i < size; i++)
    {
        if (input[i] > 0)
            return i;
    }
    return -1;
}

void reArrangeArray(int input[], int size)
{
    int N = -1, P = -1;

    N = getNextN(input, size, N);
    P = getNextP(input, size, P);

    while (P < size - 1 && N < size - 1)
    {
        // if P+1 is also positive swapping
        if (input[P + 1] > 0 && N > P)
            swap(input[P + 1], input[N]);

        // if N present before P, swapping N and P elements
        if (N < P)
        {
            swap(input[N], input[P]);
            /* skipping next number (which will alays be negative after swapping) after putting positive number
            eg 1 arr= [-1, -2, 1, 2] => [1,-2, -1, 2], here N=0, it should be moved to 1 so that search for 
            next N won't include it.
            eg 2 arr = [-1, 1, -2, 2] => [1, -1, -2, 2], here N=0, it should directly moved to 2 by search.
            here since next position 1 is positive doing N++ doesn't matter, result will be same if we do or not.*/
            if (input[N + 1] < 0) // condition can be removed
                N++;
        }

        // Moving P and N to next Positions
        N = getNextN(input, size, N);
        P = getNextP(input, size, P);

        // Breaking loop if there is no more N or P

        if (N == -1 || P == -1)
            break;
    }
    if (N != -1 && P != -1)
    {
        // when negatives are less than positives and last negative is on last index, loop will end before putting last negative at correct place. in this case N == size-1, we need to swap it with input[P+1] if its positive
        if (N == size - 1 && input[P + 1] > 0)
            swap(input[P + 1], input[N]);

        // when positives are less than negatives and last positive is on last index, loop will end before putting last positive at correct place. in this case P == size-1, we need to swap it with input[N] if input[N-1] is also negative.
        if (P == size - 1 && input[N - 1] < 0)
            swap(input[N], input[P]);
    }
}

////////////////////////// Solution 2 ////////////////////////
/*
The idea is to process array from left to right. While processing, find the first out of place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive and at even index. Once we find an out of place element, we find the first element after it with opposite sign. We right rotate the subarray between these two elements (including these two).
Time complexity for this solution is O(n^2)
*/

void reArrangeRotation(int input[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (i % 2 == 0 && input[i] < 0)
        {
            int j;
            //searching for next opposite sign number
            for (j = i + 1; j < size; j++)
                if (input[j] > 0)
                    break;
            //rotating subarray
            if (j < size) // only if next positive number present in array
            {
                int temp = input[j];
                for (int k = j; k > i && k < size; k--)
                    input[k] = input[k - 1];
                input[i++] = temp; //we are placing 2 numbers at correct position, no need to iterate for i+1 th element
            }
            else
            { //all remaing numbers are negative, no need to rearrange elements further
                break;
            }
        }
        else if (i % 2 == 1 && input[i] > 0)
        {
            int j;
            //searching for next opposite sign number
            for (j = i + 1; j < size; j++)
                if (input[j] < 0)
                    break;
            //rotating subarray
            if (j < size) // only if next negative number present in array
            {
                int temp = input[j];
                for (int k = j; k > i; k--)
                    input[k] = input[k - 1];
                input[i++] = temp; //we are placing 2 numbers at correct position, no need to iterate got i+1 th element
            }
            else
            { //all remaing numbers are positive, no need to rearrange elements further
                break;
            }
        }
        for (int k = 0; k < size; k++)
            cout << input[k] << " ";
        cout << endl;
    }
}

/*/////////////////////////////////////// Solution 3 //////////////////////////////////////
If we are allowed to change order of appearance, we can solve this problem in O(n) time and O(1) space.
The idea is to process the array and shift all negative values to the end in O(n) time. After all negative values are shifted to the end, we can easily rearrange array in alternating positive & negative items. We basically swap next positive element at even position from next negative element in this step. 
/////////////////////////////////////////////////////////////////////////////////////////*/
void reArrangeArrayTwoPass(int input[], int size)
{
    if (size > 1)
    {
        int n = 0, p = size - 1;
        //moving all negatives to end
        while (n < p)
        {
            if (input[p] < 0)
                p--;
            if (input[n] > 0)
                n++;

            if (input[n] < 0 && input[p] > 0 && n < p)
            {
                swap(input[n], input[p]);
                n++;
                p--;
            }
        }
        //all negatives are at end
        // setting n to first negative number
        for (n = 0; n < size; n++)
        {
            if (input[n] < 0)
                break;
        }
        //second pass for rearranging elements
        p = 1; //0th element should be positive, rearrange from 1
        while (input[p] > 0 && input[n] < 0)
        {
            swap(input[p], input[n]);
            p += 2; // leaving next p as it is and marking p+2 for rearranging
            n++;
        }
    }
}

int main()
{
    int input[] = {-6, -4, -2, -7, -4, -6, -3, -1, -8, -9, -11};
    int size = sizeof(input) / sizeof(int);

    //reArrangeArray(input, size);
    //reArrangeRotation(input, size);
    reArrangeArrayTwoPass(input, size);

    for (int num : input)
        cout << num << " ";
    cout << endl;
}
