
/*//////////////////////////////// Q 345 : Babbar450: Find the number of Island ////////////////////////
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
/////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////// Solution /////////////////////////
This is a variation of the standard problem: "Counting the number of connected components in an undirected graph".

The idea here is to traverse all the connected nodes from a node and mark them visited, in the dfs call we'll always start from an unvisited node and in the end of each traversal, one componant of the graph will be marked as visited entirely. so every time we traverse a componant we increment the counter. In the end we'll have the count of the total componants or islands.

here from each node we have 8 places to move, so for each of these 8 places we'll call the function recursively.

Time complexity : O(n*m) because we are visiting each node only once.
////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Graph_FindNumberOfIsland {
    static int[][] moves = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S[j].charAt(0);
                }
            }
            int ans = numIslands(grid);
            System.out.println(ans);
        }
    }

    static int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] visited = new int[n][m];

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    findIsland(i, j, n, m, grid, visited);
                    count++;
                }
            }

        return count;
    }

    static void findIsland(int x, int y, int n, int m, char grid[][], int visited[][]) {
        visited[x][y] = 1;

        for (int i = 0; i < 8; i++) {
            int u = x + moves[i][0];
            int v = y + moves[i][1];
            if (u < n && v < m && u >= 0 && v >= 0 && visited[u][v] == 0 && grid[u][v] == '1')
                findIsland(u, v, n, m, grid, visited);
        }
    }
}