/*///////////////////////////// Q6: Babbar450 : Find the Union and Intersection of the two sorted arrays. ////////////////////////
Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <set>

using namespace ::std;

////////////////////////////////////////////////////// Solution 1 ////////////////////////////////////////////////////
void printUnion(int arr1[], int arr2[], int size1, int size2)
{
    int i, j;
    for (i = 0, j = 0; i < size1 && j < size2;)
    {
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            while (i < size1 - 1)
            {
                if (arr1[i] == arr1[i + 1])
                    i++;
                else
                    break;
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            while (j < size2 - 1)
            {
                if (arr2[j] == arr2[j + 1])
                    j++;
                else
                    break;
            }
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            while (i < size1 - 1)
            {
                if (arr1[i] == arr1[i + 1])
                    i++;
                else
                    break;
            }
            while (j < size2 - 1)
            {
                if (arr2[j] == arr2[j + 1])
                    j++;
                else
                    break;
            }
            i++;
            j++;
        }
    }
    while (i < size1)
    {
        cout << arr1[i] << " ";
        while (i < size1 - 1)
        {
            if (arr1[i] == arr1[i + 1])
                i++;
            else
                break;
        }
        i++;
    }

    while (j < size2)
    {
        cout << arr2[j] << " ";
        while (j < size2 - 1)
        {
            if (arr2[j] == arr2[j + 1])
                j++;
            else
                break;
        }
        j++;
    }
}
/*
Time Complexity for this solution is O(n + m) which is equal to BCR (Best Concievable RunTime) and Space Complexity is O(1)
*/

////////////////////////////////////// Solution 2 ////////////////////////////////////////////////
void getUnionIntersection(int input1[], int size1, int input2[], int size2, set<int> &unionSet, set<int> &intersectSet)
{
    int i = 0, j = 0, indexU = 0, indexI = 0;

    while (i < size1 && j < size2)
    {
        if (input1[i] == input2[j])
        {
            intersectSet.insert(input1[i]);
        }

        if (input1[i] < input2[j])
            unionSet.insert(input1[i++]);
        else
            unionSet.insert(input2[j++]);
    }
    while (i < size1)
        unionSet.insert(input1[i++]);

    while (j < size2)
        unionSet.insert(input2[j++]);
}
/*
Time complexity for this solution is O(n + m) * log p where p is the total number of elements in the set. 
Time complexxity for insert operation in set is O(nog p) since we are inserting all  n + m elements in set resulting complexity is much  higher.
*/

int main()
{

    int arr1[] = {1, 6, 9, 15, 55, 55};
    int arr2[] = {2, 8, 33, 55, 99, 99, 99, 101};

    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);

    int unionArr[size1 + size2] = {0};
    int intersecArr[size1 < size2 ? size1 : size2] = {0};

    printUnion(arr1, arr2, size1, size2);
    cout << endl;

    set<int> unionSet;
    set<int> intersectSet;

    getUnionIntersection(arr1, size1, arr2, size2, unionSet, intersectSet);

    for (int i : unionSet)
        cout << i << " ";

    cout << endl;

    for (int i : intersectSet)
        cout << i << " ";
}