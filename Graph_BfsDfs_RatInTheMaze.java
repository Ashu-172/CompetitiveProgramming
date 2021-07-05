import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/*/////////////////////////////// Q 335: Babbar450: Search In the Maze ///////////////////////////
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
////////////////////////////////////////////////////////////////////////////////////////////////*/
public class Graph_BfsDfs_RatInTheMaze {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
        sc.close();
    }
}

class Solution {
    public ArrayList<String> findPath(int[][] m, int n) {
        int[][] moves = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        char[] moveC = { 'D', 'R', 'U', 'L' };
        ArrayList<String> result = new ArrayList<String>();
        StringBuilder path = new StringBuilder();
        if (m[0][0] != 0 && m[n - 1][n - 1] != 0) {
            m[0][0] = 0;
            findPaths(0, 0, n, m, moves, moveC, path, result);
            Collections.sort(result);
        }
        return result;

    }

    void findPaths(int r, int c, int n, int[][] m, int moves[][], char moveC[], StringBuilder path,
            ArrayList<String> result) {
        if (r == n - 1 && c == n - 1) {
            result.add(path.toString());
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newR = r + moves[i][0];
            int newC = c + moves[i][1];
            if (isSafe(newR, newC, n, m) == true) {
                m[newR][newC] = 0;
                path.append(moveC[i]);
                findPaths(newR, newC, n, m, moves, moveC, path, result);
                path.deleteCharAt(path.length() - 1);
                m[newR][newC] = 1;
            }
        }
    }

    static boolean isSafe(int r, int c, int n, int m[][]) {
        if (r >= 0 && r < n && c >= 0 && c < n && m[r][c] == 1)
            return true;
        return false;
    }
}
