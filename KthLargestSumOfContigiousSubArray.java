import java.util.PriorityQueue;

public class KthLargestSumOfContigiousSubArray {
    public static void main(String[] args) {
        int arr[] = { 20, -5, -1 };
        int k = 3;

        int res = FindKthLargestSum(arr, arr.length, k);
        System.out.println(res);
    }

    private static int FindKthLargestSum(int arr[], int n, int k) {
        int sum[] = new int[n];
        sum[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sum[i] = sum[i + 1] + arr[i];
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();
        for (int i = 0; i < n; i++) {
            minHeap.add(sum[i]);
            if (minHeap.size() > k)
                minHeap.poll();

            for (int j = i + 1; j < n; j++) {
                minHeap.add(sum[i] - sum[j]);
                if (minHeap.size() > k)
                    minHeap.poll();
            }
        }
        return minHeap.poll();
    }
}
