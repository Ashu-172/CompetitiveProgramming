/*/////////////////////////////////// Q 19: Babbar450 : FInd Common Elements in 3 sorted arrays ///////////////////////////////
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?
Example 1:
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
 
Your Task:  
You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order. 
If there are no such elements return an empty array. In this case the output will be printed as -1.
 
Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)
 
Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//////////////////////////////////////////////// Solution 1 ///////////////////////////////////////////////
bool binarySearch(int input[], int start, int end, int num)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        bool res;
        if (input[mid] == num)
            return true;
        else if (num < input[mid])
            res = binarySearch(input, start, mid - 1, num);
        if (res == false)
            return binarySearch(input, mid + 1, end, num);
        return res;
    }
    return false;
}

vector<int> findCommonElements(int input1[], int input2[], int input3[], int size1, int size2, int size3)
{
    vector<int> result;
    for (int i = 0; i < size1; i++)
    {
        //moving to last occurrence
        while (i < size1 - 1)
            if (input1[i] == input1[i + 1])
                i++;
            else
                break;
        int j;
//searching current element in second array
//with Lenier search
#if 0
        for (j = 0; j < size2; j++)
        {
            if (input1[i] == input2[j])
                break;
        }
        // if found in array
        if (j != size2)
        {
            //Lenier search
            for (int k = 0; k < size3; k++)
                if (input1[i] == input3[k])
                {
                    result.push_back(input1[i]);
                    break;
                }
        }
#endif
#if 1
        //binary search
        if (binarySearch(input2, 0, size2 - 1, input1[i]))
        {

            if (binarySearch(input3, 0, size3 - 1, input1[i]))
            {
                result.push_back(input1[i]);
            }
        }
#endif
    }
    return result;
}
//Time complexity for Linear search is O(n1(n2+n3)) and for binary search O(n1(log n2 + log n3))

vector<int> getCommonElements(int input1[], int input2[], int input3[], int size1, int size2, int size3)
{
    vector<int> result;
    if (size1 <= size2 && size1 <= size3)
        result = findCommonElements(input1, input2, input3, size1, size2, size3);
    else if (size3 <= size1 && size3 <= size2)
        result = findCommonElements(input3, input1, input2, size3, size1, size2);
    else
        result = findCommonElements(input2, input1, input3, size2, size1, size3);

    return result;
}

////////////////////////////////////////// Solution 2 //////////////////////////////////
/*
in this approach first we'll put all the elements of array1 in  a map then 
we'll search elements of array2 in the map in  O(1) time and prepare a new 
map for common elements of array1 and array2.
now we'll search elements of array3 in this new map and get the final result 
as all common elements in all three arrays.

time complexity for worst case (wehre all the elements are common in all arrays)
will be O(n1) =>inserting + O(n2) =>searching + O(n3) => searching
              = O(n1+n2+n3)
space complexity will be O(n1) =>prepring hash map 
                       + O(n2) =>preparing second hash map
                       + O(n3) =>preparing result array of vector
                       = O(n1+n2+n3)
*/

vector<int> findCommonElementsHM(int input1[], int input2[], int input3[], int size1, int size2, int size3)
{
    unordered_multimap<int, int> hashTable1;
    for (int i = 0; i < size1; i++)
    {
        auto itr = hashTable1.find(input1[i]);
        if (itr == hashTable1.end())
            hashTable1.insert(make_pair(input1[i], 1));
        //    else
        //      itr->second++;
    }

    unordered_multimap<int, int> hashTable2;
    for (int i = 0; i < size2; i++)
    {
        auto itr1 = hashTable1.find(input2[i]);
        if (itr1 != hashTable1.end())
        {
            if (itr1->second != 0)
            {
                //if presentin map2 then increasing count else inserting
                auto itr2 = hashTable2.find(input2[i]);
                if (itr2 != hashTable2.end())
                {
                    //      itr2->second++;
                }
                else
                {
                    hashTable2.insert(make_pair(input2[i], 1));
                }
                //decreasing count because we have read one occurance
                //itr1->second--;
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < size3; i++)
    {
        auto itr2 = hashTable2.find(input3[i]);
        if (itr2 != hashTable2.end())
        {
            if (itr2->second != 0)
            {
                //inserting in result and decresing count because we have read one occurrance
                result.push_back(input3[i]);
                itr2->second--;
            }
        }
    }
    return result;
}

vector<int> getCommonElementsHM(int input1[], int input2[], int input3[], int size1, int size2, int size3)
{
    vector<int> result;
    if (size1 <= size2 && size1 <= size3)
        result = findCommonElementsHM(input1, input2, input3, size1, size2, size3);
    else if (size3 <= size1 && size3 <= size2)
        result = findCommonElementsHM(input3, input1, input2, size3, size1, size2);
    else
        result = findCommonElementsHM(input2, input1, input3, size2, size1, size3);

    return result;
}

////////////////////////////////// Solution3  triple pointer ///////////////////
vector<int> getCommonsThreePointer(int input1[], int input2[], int input3[], int size1, int size2, int size3)
{
    int i = 0, j = 0, k = 0;
    vector<int> result;
    while (i < size1 && j < size2 && k < size3)
    {
        //moving to last occurrence if duplicates present
        while (i < size1 - 1)
            if (input1[i] == input1[i + 1])
                i++;
            else
                break;
        if (input1[i] == input2[j] && input2[j] == input3[k])
        {
            result.push_back(input1[i]);
            i++;
            j++;
            k++;
        }
        else if (input1[i] < input2[j] || input1[i] < input3[k])
            i++;
        else if (input2[j] < input1[i] || input2[j] < input3[k])
            j++;
        else
            k++;
    }
    return result;
}
//time complexity for this solution is O(n1+n2+n3) in worst case.
//space complexity is O(1).

int main()
{
    int input1[] = {3, 3, 3};
    int input2[] = {3, 3, 3};
    int input3[] = {3, 3, 3};

    int size1 = sizeof(input1) / sizeof(int);
    int size2 = sizeof(input2) / sizeof(int);
    int size3 = sizeof(input3) / sizeof(int);

    vector<int> result;
    result = getCommonElements(input1, input2, input3, size1, size2, size3);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    result = getCommonElementsHM(input1, input2, input3, size1, size2, size3);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    result = getCommonsThreePointer(input1, input2, input3, size1, size2, size3);

    for (int num : result)
    {
        cout << num << " ";
    }
}