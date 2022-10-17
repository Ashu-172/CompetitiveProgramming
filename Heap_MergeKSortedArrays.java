import java.util.ArrayList;
import java.util.PriorityQueue;

class ArrayNode {
    int data;
    int i;
    int j;

    public ArrayNode(int data, int i, int j) {
        this.data = data;
        this.i = i;
        this.j = j;
    }
}

public class Heap_MergeKSortedArrays {
    public static void main(String[] args) {
        int arr[][] = { { 1, 2, 3, 4 }, { 2, 2, 3, 4 }, { 5, 5, 6, 6 }, { 7, 8, 9, 9 } };
        int k = 4;

        ArrayList<Integer> res = mergeKArrays(arr, k);
        System.out.println(res);
    }

    public static ArrayList<Integer> mergeKArrays(int[][] arr, int k) {
        PriorityQueue<ArrayNode> minHeap = new PriorityQueue<ArrayNode>((a, b) -> a.data - b.data);

        for (int i = 0; i < arr.length; i++)
            minHeap.add(new ArrayNode(arr[i][0], i, 0));

        ArrayList<Integer> res = new ArrayList<Integer>();
        while (minHeap.isEmpty() != true) {
            ArrayNode node = minHeap.poll();
            res.add(node.data);

            if (node.j < arr[node.i].length - 1) {
                minHeap.add(new ArrayNode(arr[node.i][node.j + 1], node.i, node.j + 1));
            }
        }
        return res;
    }
}
