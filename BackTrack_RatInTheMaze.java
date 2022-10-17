import java.util.ArrayList;
import java.util.Scanner;

public class BackTrack_RatInTheMaze {

    private static int moves[][] = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };
    // keep it in sorted order to get all the paths in sorted order in the end
    private static char dir[] = { 'D', 'L', 'R', 'U' };

    private static ArrayList<String> findPath(int[][] m, int n) {
        ArrayList<String> paths = new ArrayList<String>();
        if (m[0][0] == 0)
            return paths;

        StringBuilder sb = new StringBuilder();
        m[0][0] = 0;
        traverse(m, n, paths, 0, 0, sb);
        return paths;
    }

    private static void traverse(int[][] m, int n, ArrayList<String> paths, int r, int c, StringBuilder path) {
        if (r == n - 1 && c == n - 1) {
            paths.add(path.toString());
            return;
        }

        for (int i = 0; i < 4; i++) {
            int row = r + moves[i][0];
            int col = c + moves[i][1];

            if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1) {
                path.append(dir[i]);
                m[row][col] = 0;
                traverse(m, n, paths, row, col, path);
                m[row][col] = 1;
                path.deleteCharAt(path.length() - 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = sc.nextInt();

        ArrayList<String> res = findPath(a, n);
        if (res.size() > 0) {
            for (int i = 0; i < res.size(); i++)
                System.out.print(res.get(i) + " ");
            System.out.println();
        } else {
            System.out.println(-1);
        }
        sc.close();
    }
}
