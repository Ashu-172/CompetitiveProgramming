import java.util.PriorityQueue;

public class Heap_K_LargestElements {
    public static void main(String[] args) {
        int arr[] = { 2, 8, 9, 1, 6, 4, 8, 0 };
        int k = 4;

        int res[] = getKLargest(arr, arr.length, k);
        for (int num : res)
            System.out.print(num + " ");
        System.out.println();
    }

    private static int[] getKLargest(int[] arr, int n, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>();

        for (int i = 0; i < n; i++) {
            minHeap.add(arr[i]);
            if (minHeap.size() > k)
                minHeap.poll();
        }

        int res[] = new int[k];
        for (int i = k - 1; i >= 0; i--)
            res[i] = minHeap.poll();

        return res;
    }
}
