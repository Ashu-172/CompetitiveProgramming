import java.util.PriorityQueue;

public class Heap_MergeTwoMaxHeaps {
    public static void main(String[] args) {
        int arr1[] = { 10, 5, 6, 2 };
        int arr2[] = { 12, 7, 9 };

        int res[] = mergeHeaps(arr1, arr2, arr1.length, arr2.length);
        for (int num : res)
            System.out.print(num + " ");
        System.out.println();
    }

    private static int[] mergeHeaps(int[] a, int[] b, int n, int m) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((p, q) -> q.compareTo(p));
        for (int num : a)
            maxHeap.add(num);

        for (int num : b)
            maxHeap.add(num);

        int res[] = new int[n + m];

        for (int i = 0; i < n + m; i++) {
            res[i] = maxHeap.poll();
        }
        return res;
    }
}
