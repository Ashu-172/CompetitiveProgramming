import java.util.PriorityQueue;

public class Heap_KthSmallestElement {
    public static void main(String[] args) {
        int arr[] = { 2, 8, 9, 1, 6, 4, 8, 0 };
        int k = 4;

        int res = FindKthSmallestElement(arr, arr.length, k);
        System.out.println(res);
    }

    private static int FindKthSmallestElement(int[] arr, int n, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((a, b) -> b.compareTo(a));
        for (int i = 0; i < n; i++) {
            maxHeap.add(arr[i]);
            if (maxHeap.size() > k)
                maxHeap.poll();
        }
        return maxHeap.peek();
    }
}
