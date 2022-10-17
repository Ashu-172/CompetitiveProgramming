import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000


Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000


Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
public class S_S_MedianOfTwoSortedArray {
    public static void main(String[] args) throws IOException {
        int n, m;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        n = reader.read();
        m = reader.read();

        int nums1[] = new int[n];
        int nums2[] = new int[m];

        String str1[] = reader.readLine().trim().split(" ");
        String str2[] = reader.readLine().trim().split(" ");

        for (int i = 0; i < n; i++)
            nums1[i] = Integer.parseInt(str1[i]);

        for (int i = 0; i < n; i++)
            nums2[i] = Integer.parseInt(str2[i]);

        System.out.println(findMedianSortedArraysSol1(nums1, nums2));
        System.out.println(findMedianSortedArrays(nums1, nums2));

    }

    /*
     * Method 1 (Simply count while Merging) Use the merge procedure of merge sort.
     * Keep track of count while comparing elements of two arrays. If count becomes
     * n(For 2n elements), we have reached the median. Take the average of the
     * elements at indexes n-1 and n in the merged array. See the below
     * implementation.
     * 
     * Time Complexity : O(n) Auxiliary Space: O(1)
     */
    private static double findMedianSortedArraysSol1(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int prev = 0, curr = 0;
        int i = 0, j = 0, k = 0;
        int mid = (n + m) / 2;
        while (i < n && j < m && k <= mid) {
            prev = curr;
            if (nums1[i] < nums2[j])
                curr = nums1[i++];
            else
                curr = nums2[j++];
            k++;
        }

        while (i < n && k <= mid) {
            prev = curr;
            curr = nums1[i++];
            k++;
        }

        while (j < m && k <= mid) {
            prev = curr;
            curr = nums2[j++];
            k++;
        }

        if ((n + m) % 2 == 0)
            return (double) (prev + curr) / 2;
        else
            return curr;
    }

    /*
     * Using binary search : https://www.youtube.com/watch?v=NTop3VTjmxk
     */
    private static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums2.length < nums1.length)
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.length;
        int m = nums2.length;
        int low = 0, high = n;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? Integer.MIN_VALUE : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? Integer.MIN_VALUE : nums2[cut2 - 1];
            int r1 = (cut1 == n) ? Integer.MAX_VALUE : nums1[cut1];
            int r2 = (cut2 == m) ? Integer.MAX_VALUE : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0)
                    return (double) (Math.max(l1, l2) + Math.min(r1, r2)) / 2;
                else
                    return Math.max(l1, l2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else { // l2>r1
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
}
