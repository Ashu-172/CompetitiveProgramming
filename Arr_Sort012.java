public class Arr_Sort012 {
    // Dutch National Flag
    private static void sortArrMethod1(int arr[]) {
        int i = 0, j = 0, k = arr.length - 1;
        while (j < k) {
            if (arr[j] < 1) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j++;
            } else if (arr[j] > 1) {
                int temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
                k--;
            } else
                j++;
        }
    }

    // count based method (Better)
    private static void sortArrMethod2(int arr[]) {
        int count[] = new int[3];

        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }
        int k = 0;
        for (int i = 0; i < count.length; i++) {
            System.out.println(arr[i]);
            while (count[i] != 0) {
                arr[k++] = i;
                count[i]--;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 0, 2, 2, 1, 1, 0, 0, 2, 0, 2, 2, 1, 0, 0 };
        sortArrMethod1(arr);
        sortArrMethod2(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
