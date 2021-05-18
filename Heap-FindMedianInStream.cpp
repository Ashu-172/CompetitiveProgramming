/*//////////////////////////////// Q 323: Babbar450: Find Median In a Stream ////////////////////////////////////
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
////////////////////////////////////////////////// Solution 1 (Insertion Sort) ///////////////////////////////////////////
/*
If we can sort the data as it appears, we can easily locate median element. Insertion Sort is one such online algorithm that sorts the data appeared so far. At any instance of sorting, say after sorting i-th element, the first i elements of array are sorted. The insertion sort doesn’t depend on future data to sort data input till that point. In other words, insertion sort considers data sorted so far while inserting next element.

However, insertion sort takes O(n^2) time to sort n elements. Perhaps we can use binary search on insertion sort to find location of next element in O(log n) time. Yet, we can’t do data movement in O(log n) time. No matter how efficient the implementation is, it takes polynomial time O(n^2) in case of insertion sort.
*/
class Solution1
{
private:
    vector<int> input;
    int median;

    int findLocation(int x)
    {
        //Binary Search for next bigger value
        int start = 0;
        int end = input.size() - 1;
        int mid = (start + end) / 2;

        while (start < end)
        {
            if (input[mid] > x)
                end = mid;
            else
                start = mid + 1;

            mid = (start + end) / 2;
        }
        if (input[start] > x)
            return start;
        else // when x is the largest element
            return start + 1;
    }

public:
    void medianInsertionSort(int x)
    {
        int size = input.size();
        if (size == 0)
        {
            input.push_back(x);
            median = x;
        }
        else
        {
            int loc = findLocation(x);

            // shifting elements to make empty space at loc for inserting x
            input.push_back(input[size - 1]);
            for (int i = size - 1; i > loc; i--)
            {
                input[i] = input[i - 1];
            }
            input[loc] = x;
            size++;

            // calculating median
            if (size % 2 == 0)
            {
                median = (input[(size / 2) - 1] + input[size / 2]) / 2;
            }
            else
            {
                median = input[size / 2];
            }
        }
    }

    int getMedian()
    {
        return median;
    }
};
/////////////////////////////////////////////////// Solution 2 (Using Heaps) /////////////////////////////////////////////
/*
    we can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to represent elements that are greater than effective median.

    After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective median from the root of heap containing more elements.
*/
class Solution2
{
private:
    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (median == 0)
        {
            maxHeap.push(x);
            median = x;
        }
        else
        {
            if (x <= median)
                maxHeap.push(x);
            else
                minHeap.push(x);

            balanceHeaps();

            if (maxHeap.size() > minHeap.size())
                median = maxHeap.top();
            else if (minHeap.size() > maxHeap.size())
                median = minHeap.top();
            else
                median = (minHeap.top() + maxHeap.top()) / 2;
        }
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        /*
        Here type casting is needed because size() method return result of type size_t which is alias of unsigned integer. if difference is negative than size_t will convert the result in a very huge number, then if we compare that value with 1, we'll get incorrect velue.
        
        How size_t store negative values ?
            The conversion from signed to unsigned happens by logically adding the maximum value the unsigned type can hold +1 to the numeric value of the signed type until the result is in the range of the unsigned type. Note that this happen regardless of the underlying representation of the relevant integer types.

            So for example, assuming size_t is a 64 bit type, the largest value it can hold is 18446744073709551615. So if you input -1 then 18446744073709551616 is added to -1 to give you 18446744073709551615 which is the result.

        */
        while ((int)(minHeap.size() - maxHeap.size()) > 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        while ((int)(maxHeap.size() - minHeap.size()) > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};

int main()
{
    int n, x;

    /*
    Solution2 ob;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        ob.insertHeap(x);
        cout << floor(ob.getMedian()) << endl;
    }
    */
    Solution1 obj;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        obj.medianInsertionSort(x);
        cout << floor(obj.getMedian()) << endl;
    }

    return 0;
}
