////////////////////// Q 312: Babbar450: Implement Min/Max Heap from array ///////////////////
public class Heap_ArrayToHeap {
    static void minHeapify(int arr[], int size, int index) {
        int l = 2 * index + 1;
        int r = 2 * index + 2;
        int min = index;

        if (l < size && arr[l] < arr[min])
            min = l;

        if (r < size && arr[r] < arr[min])
            min = r;

        if (min != index) {
            int temp = arr[min];
            arr[min] = arr[index];
            arr[index] = temp;
            minHeapify(arr, size, min);
        }
    }

    public static void main(String[] args) {
        int input[] = { 5, 3, 8, 4, 1, 0, 9, 10, 7, 6 };
        int size = input.length;
        for (int index = size / 2 - 1; index >= 0; index--)
            minHeapify(input, input.length, index);

        for (int num : input)
            System.out.print(num + " ");
        System.out.println();
    }
}
