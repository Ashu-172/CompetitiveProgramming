///////////////////////////// CtCI P45 Example ///////////////////////////
/*////////////////////////// Problem Statement //////////////////////////
Given an array of distinct integer values, count  the number of the pairs of 
integers that have difference k. for examole, given {1, 7, 5, 9, 2, 12, 3}
and the difference k=2, there are four pairs with difference 2:
(1,3), (3, 5), (5, 7), (7, 9).
//////////////////////////////////////////////////////////////////////*/

/*///////////////////// Solution 1 ///////////////////////
the brute force solution is to find the difference for each element with every other element

for(int i=0; i< len; i++)
{
    for(int j = i+1; j<len; j++)
    {
        int diff = arr[i] - arr[j]
        if(diff == k || diff == -k)
            cout<<"("<<arr[i]<<", "<<arr[j]<<")"<<endl;
    }
}

for this solution time complexity is O(n^2).
///////////////////////////////////////////////////////////*/

/*/////////////////////// Solution 2 ////////////////////////
in brute force approach we are using following equation
            arr[i] - arr[j] = k
from this equation we can find the paired value for every value present in the array.
                A - B = k
            =>  B = A + k
instead of iterating two times over the array we can calculate value of B for every
value of A and we can search B in the array using Binary search algorithm.

binary search will give O(log n) time complexity and this search will happen for n-1 
values of B. So the final time complexity for this approach will be O(n log n)

////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>

using namespace std;

bool binarySearch(int start, int end, int num, int arr[])
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            return true;
        }
        if (arr[mid] < num)
        {
            return binarySearch(mid + 1, end, num, arr);
        }
        return binarySearch(start, mid - 1, num, arr);
    }
    return false;
}

void merge(int input[], int start, int mid, int end)
{
    int lLen = mid - start + 1;
    int rLen = end - mid;

    int left[lLen];
    int right[rLen];

    for (int i = 0; i < lLen; i++)
    {
        left[i] = input[start + i];
    }

    for (int i = 0; i < rLen; i++)
    {
        right[i] = input[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < lLen && j < rLen)
    {
        if (left[i] > right[j])
        {
            input[k++] = right[j++];
        }
        else
        {
            input[k++] = left[i++];
        }
    }
    while (i < lLen)
    {
        input[k++] = left[i++];
    }
    while (j < rLen)
    {
        input[k++] = right[j++];
    }
}

void mergeSort(int input[], int start, int end)
{
    if (end > start)
    {
        int mid = (start + end) / 2;

        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);
        merge(input, start, mid, end);
    }
    return;
}

#if 0
int main()
{
    int len = 0;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int diff;
    cin >> diff;

    mergeSort(arr, 0, len - 1);

    // for (int index = 0; index < len; index++)
    //     cout << arr[index] << endl;

    for (int i = 0; i < len; i++)
    {
        int first = arr[i];
        int second = first + diff;
        if (binarySearch(i + 1, len - 1, second, arr))
        {
            cout << " ( " << first << ", " << second << ")" << endl;
        }
    }
}
#endif
/*///////////////////////////////// Solution 3 //////////////////////////////////
in the above solution we are using Binary search to find the value of B
but for applying Binary search we are sorting the array which is a Bottleneck

Binary search gives O(log n) time complexity but sorting takes O(n log n) time.

we can search for B with O(n) time by using Hash Table. Hash Tables can search 
an elenent in O(n) from unsorted data which is a good approach to use here.

we don't need to sort the array hence total time complexity will be of order O(n).
////////////////////////////////////////////////////////////////////////////////*/
int main()
{
    int len = 0;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int diff;
    cin >> diff;

    unordered_multimap<int, int> umap;
    int key = 0;
    //inserting all values in the unordered map i.e. Hash Table
    for (int i = 0; i < len; i++)
    {
        key = arr[i] % len;
        umap.insert(make_pair(key, arr[i]));
    }
    int totalRun = 0;

    // searching for pairs with difference of diff
    for (int i = 0; i < len; i++)
    {
        int first = arr[i];
        int second = first + diff;

        key = second % len;

        auto itr = umap.equal_range(key);
        for (auto it = itr.first; it != itr.second; it++)
        {
            totalRun++;
            if (second == it->second)
            {
                cout << " ( " << first << ", " << second << ")" << endl;
            }
        }
    }
    // just for checking the order of the algorithm
    cout << "totalRun: " << totalRun << endl;
}
