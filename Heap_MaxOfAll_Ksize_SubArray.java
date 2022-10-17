import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.PriorityQueue;

public class Heap_MaxOfAll_Ksize_SubArray {
    public static void main(String[] args) {
        int arr[] = { 2, 8, 9, 1, 6, 4, 8, 0 };
        int k = 4;

        ArrayList<Integer> res1 = findMaxOfSubArrays1(arr, arr.length, k);
        ArrayList<Integer> res2 = findMaxOfSubArrays2(arr, arr.length, k);

        for (int num : res1)
            System.out.print(num + " ");
        System.out.println();

        for (int num : res2)
            System.out.print(num + " ");
        System.out.println();
    }

    /////////////////////// Max Heap solution /////////////////////////////
    // Reference: https://www.youtube.com/watch?v=xFJXtB5vSmM
    // Time complexity for this solution in O(N) and space complexity is O(N).
    private static ArrayList<Integer> findMaxOfSubArrays1(int[] arr, int n, int k) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((a, b) -> b.compareTo(a));
        int i = 0;
        for (i = 0; i < k; i++) {
            maxHeap.add(arr[i]);
        }

        res.add(maxHeap.peek());

        for (; i < n; i++) {
            maxHeap.remove(arr[i - k]); // O(k + log k) => because the heap size is k
            maxHeap.add(arr[i]); // O(log k)
            res.add(maxHeap.peek());
        }
        return res;
    } // total complexity = O(n * (k+ log k+ log k)) = O(n*k)

    ////////////////// Deque Solution (Better) /////////////////
    static ArrayList<Integer> findMaxOfSubArrays2(int arr[], int n, int k) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        Deque<Integer> buff = new ArrayDeque<Integer>(k);
        for (int i = 0; i < n; i++) {
            while (buff.size() != 0 && arr[buff.peekLast()] <= arr[i])
                buff.pollLast();

            buff.add(i);

            if (i >= k - 1) {
                res.add(arr[buff.peekFirst()]);

                if (buff.peekFirst() == i - k + 1)
                    buff.pollFirst();
            }
        }
        return res;
    }
}
