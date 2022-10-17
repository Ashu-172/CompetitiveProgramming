import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class S_S_FirstAndLastPositionOfX {
    public static void main(String[] args) throws IOException {
        int n, x;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] str = reader.readLine().trim().split(" ");
        n = Integer.parseInt(str[0]);
        x = Integer.parseInt(str[1]);
        long arr[] = new long[n];
        String s[] = reader.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(s[i]);
        }

        ArrayList<Long> list = findFirstLast(arr, n, x);
        for (long num : list)
            System.out.println(num + " ");
    }

    private static ArrayList<Long> findFirstLast(long arr[], int n, int x) {
        int l = 0, r = n - 1;
        ArrayList<Long> list = new ArrayList<Long>();
        // long first = -1, last = -1;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (x <= arr[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (l == r && arr[l] == x) {
            list.add((long) l);
            r = n - 1;
            while (l < r) {
                mid = (l + r + 1) / 2;
                if (x >= arr[mid])
                    l = mid;
                else
                    r = mid - 1;
            }
            list.add((long) r);
        } else {
            list.add((long) -1);
            list.add((long) -1);
        }
        return list;
    }
}