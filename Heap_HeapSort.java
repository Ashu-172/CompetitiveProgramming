public class Heap_HeapSort {
    public static void main(String[] args) {
        int arr[] = { 2, 8, 9, 1, 6, 4, 8, 0 };

        descSort(arr);
        printArr(arr);

        asceSort(arr);
        printArr(arr);
    }

    private static void printArr(int arr[]) {
        // printing Sorted Array
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    ////////////// Descending Sort ////////////////
    private static void descSort(int arr[]) {
        int lastParent = arr.length / 2 - 1;

        // converting to min Heap -> O(n/2 * log n)
        for (int i = lastParent; i >= 0; i--) {
            minHeapify(arr, i, arr.length);
        }

        // sorting the minHeapified array -> O(n * log n)
        for (int i = arr.length; i > 0; i--) {
            extractMin(arr, i);
        }
    }

    private static void minHeapify(int arr[], int index, int size) {

        int lc = index * 2 + 1;
        int rc = index * 2 + 2;

        int min = index;

        if ((lc < size) && (arr[lc] < arr[min]))
            min = lc;

        if ((rc < size) && (arr[rc] < arr[min]))
            min = rc;

        if (min != index) {
            int temp = arr[min];
            arr[min] = arr[index];
            arr[index] = temp;
            minHeapify(arr, min, size);
        }

    }

    private static void extractMin(int arr[], int size) {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;

        minHeapify(arr, 0, size - 1);
    }

    ///////////////// Ascending Sort /////////////////
    private static void asceSort(int arr[]) {
        int lastParent = arr.length / 2 - 1;

        // converting to min Heap -> O(n/2 * log n)
        for (int i = lastParent; i >= 0; i--) {
            maxHeapify(arr, i, arr.length);
        }

        // sorting the minHeapified array -> O(n * log n)
        for (int i = arr.length; i > 0; i--) {
            extractMax(arr, i);
        }
    }

    private static void maxHeapify(int arr[], int index, int size) {

        int lc = index * 2 + 1;
        int rc = index * 2 + 2;

        int max = index;

        if ((lc < size) && (arr[lc] > arr[max]))
            max = lc;

        if ((rc < size) && (arr[rc] > arr[max]))
            max = rc;

        if (max != index) {
            int temp = arr[max];
            arr[max] = arr[index];
            arr[index] = temp;
            maxHeapify(arr, max, size);
        }

    }

    private static void extractMax(int arr[], int size) {
        int temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;

        maxHeapify(arr, 0, size - 1);
    }

}
