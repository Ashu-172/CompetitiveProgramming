public class Arr_MoveNegativesAside {

    private static void moveNegatives(int arr[]) {
        int n = arr.length;
        if (n <= 1)
            return;

        for (int i = 0, j = 0; j < n; j++) {
            if (arr[j] < 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }

        }
    }

    public static void main(String[] args) {
        int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -7 };

        moveNegatives(arr);
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
