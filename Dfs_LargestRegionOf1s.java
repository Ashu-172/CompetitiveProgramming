import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.

Your Task:
You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/

public class Dfs_LargestRegionOf1s {
    private static int moves[][] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { -1, -1 }, { -1, 1 }, { 1, -1 },
            { 1, 1 } };

    private static int findMaxArea(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int maxCount = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = countNodesInRegion(grid, n, m, i, j, 1);
                    if (count > maxCount)
                        maxCount = count;
                }
            }
        return maxCount;
    }

    private static int countNodesInRegion(int[][] grid, int n, int m, int r, int c, int count) {
        grid[r][c] = -1;
        for (int i = 0; i < 8; i++) {
            int row = r + moves[i][0];
            int col = c + moves[i][1];

            if (row >= 0 && row < n && col >= 0 && col < m) {
                if (grid[row][col] == 1) {
                    count = countNodesInRegion(grid, n, m, row, col, count + 1);
                }
            }
        }
        return count;
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
        int ans = findMaxArea(grid);
        System.out.println(ans);
    }
}
