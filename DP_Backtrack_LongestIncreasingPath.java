
/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].


Example 2:
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:
Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

///////////////// Solution //////////////////
/*
The basic approach to solve this problem is to use DFS. for every location in the matrix we'll find the longest increasing path and update the global longest Increasing Path. the problem with this solution is that when we calculate the longest increasing path for a particular location, we'll calculate the longest increasing path for the other neighbour locations in the next recursive calls but we are not storing them. because of this we are repeatedly calculating longest increasing path for many locations again and again in subsequent recursive calls, this is making dfs approach a slow solution and causing TLE.

we can use memoization technique to store the result once calculated for every location and reuse the values in future instead of recalculating the same thing. in the following code comments are added to the lines which are added for memoization (DP).
*/
public class DP_Backtrack_LongestIncreasingPath {
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

        int res = longestIncreasingPath(grid);
        System.out.println(res);
    }

    static int moves[][] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    private static int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;

        int n = matrix.length;
        int m = matrix[0].length;
        int maxLen = 0;
        int mem[][] = new int[n][m]; // added for DP

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                maxLen = Math.max(maxLen, dfs(matrix, n, m, i, j, mem));
            }

        return maxLen;
    }

    private static int dfs(int[][] matrix, int n, int m, int r, int c, int[][] mem) {
        if (mem[r][c] != 0) // added for DP
            return mem[r][c]; // added for DP
        int max = 0;
        for (int i = 0; i < 4; i++) {
            int row = r + moves[i][0];
            int col = c + moves[i][1];

            if (row >= 0 && col >= 0 && row < n && col < m && matrix[row][col] > matrix[r][c]) {
                max = Math.max(max, dfs(matrix, n, m, row, col, mem));
            }
        }
        mem[r][c] = max + 1; // added for DP
        return max + 1;
    }
}
