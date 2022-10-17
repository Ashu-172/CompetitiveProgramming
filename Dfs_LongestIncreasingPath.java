/*
Given a matrix of N rows and M columns. From m[i][j], we can move to m[i+1][j], if m[i+1][j] > m[i][j], or can move to m[i][j+1] if m[i][j+1] > m[i][j]. The task is print longest path length if we start from (0, 0).
Examples: 
 

Input : N = 4, M = 4
        m[][] = { { 1, 2, 3, 4 },
                  { 2, 2, 3, 4 },
                  { 3, 2, 3, 4 },
                  { 4, 5, 6, 7 } };
Output : 7
Longest path is 1 2 3 4 5 6 7.

Input : N = 2, M =2
        m[][] = { { 1, 2 },
                  { 3, 4 } };
Output :3
Longest path is either 1 2 4 or 
1 3 4.
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Dfs_LongestIncreasingPath {

    static int maxLen = 0;
    static int moves[][] = { { 0, 1 }, { 1, 0 } };

    private static void LongestIncreasingPath(int[][] grid, int n, int m, int r, int c, int len) {
        if (len > maxLen)
            maxLen = len;

        for (int i = 0; i < 2; i++) {
            int row = r + moves[i][0];
            int col = c + moves[i][1];

            if (row >= 0 && row < n && col >= 0 && col < m) {
                if (grid[row][col] > grid[r][c]) {
                    LongestIncreasingPath(grid, n, m, row, col, len + 1);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().trim().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            String[] S = br.readLine().trim().split(" ");
            for (int j = 0; j < m; j++) {
                grid[i][j] = Integer.parseInt(S[j]);
            }
        }
        LongestIncreasingPath(grid, n, m, 0, 0, 1);
        System.out.println(maxLen);
    }
}
