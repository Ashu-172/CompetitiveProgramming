
////////// Find Kth Smallest Element ///////////

public class Arr_FindKthMinMax {
    //////////// Using Merge Sort //////////////
    private static void mergeSort(int start, int end, int arr[]) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(start, mid, arr);
            mergeSort(mid + 1, end, arr);
            merge(start, mid, end, arr);
        }
    }

    private static void merge(int start, int mid, int end, int arr[]) {
        int temp[] = new int[end - start + 1];

        int l = start;
        int r = mid + 1;
        int k = 0;

        while (l <= mid && r <= end) {
            if (arr[l] < arr[r])
                temp[k++] = arr[l++];
            else
                temp[k++] = arr[r++];
        }

        while (l <= mid)
            temp[k++] = arr[l++];

        while (r <= end)
            temp[k++] = arr[r++];

        for (int i = start, j = 0; i <= end; i++)
            arr[i] = temp[j++];
    }

    //////////// Using Quick Select ///////////
    private static int QuickSelect(int start, int end, int k, int arr[]) {
        if (start <= end) {
            int loc = partition(start, end, arr); // do the partition and return final location of pivot
            if (loc == k)
                return arr[loc];
            else {
                int result = QuickSelect(start, loc - 1, k, arr);
                if (result == -1)
                    result = QuickSelect(loc + 1, end, k, arr);
                return result;
            }
        }
        return -1;
    }

    private static int partition(int start, int end, int arr[]) {
        int pivot = (int) (start + (end - start) * Math.random());
        swap(pivot, end, arr);
        int i = start, j = start;
        while (i < end && j < end) {
            if (arr[j] < arr[end]) {
                swap(i, j, arr);
                i++;
            }
            j++;
        }
        swap(i, end, arr);
        return i;
    }

    private static void swap(int i, int j, int arr[]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int input1[] = { 5, 7, 2, 9, 1, 3, 6, 4, 10, 8 };
        int input2[] = { 5, 7, 2, 9, 1, 3, 6, 4, 10, 8 };
        int k = 3;

        mergeSort(0, 9, input1);
        for (int i = 0; i < 10; i++)
            System.out.print(input1[i] + " ");
        System.out.println();

        System.out.println("Kth Smallest: " + input1[k - 1]);
        System.out.println("Kth largest: " + input1[10 - k]);

        System.out.println("Kth Smallest: " + QuickSelect(0, 9, k - 1, input2));
    }
}
