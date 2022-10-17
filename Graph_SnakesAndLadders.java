import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

/*///////////////////// Q 348: Babbar450: Implement Prim's ALgorithm ///////////////////////
You are given an n x n integer matrix board where the cells are labeled from 1 to n^2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n^2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n^2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

Example 1:

Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.


Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1

Constraints:
n == board.length == board[i].length
2 <= n <= 20
grid[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes.
//////////////////////////////////////////////////////////////////////////////////////////*/
////////////////////////// Solution /////////////////////////
/*
This problem can be substituted to the standard problem of finding shortest path in unit weight directed graph. we can convert the input matrix to Adjacency list and then perform simple BFS. (Refer : Graph_BfsDfs_StepsByKnight.java)

we can further optimise it by adding distance array. (Refer: Graph_ShortestDistanceForAllNode_UnitWeight.java).

Below solution is using matrix itself instead of converting it into adjacency list.
*/
public class Graph_SnakesAndLadders {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());

        int input[][] = new int[n][n];
        String val[] = reader.readLine().trim().split(" ");

        for (int i = 0; i < n * n; i++) {
            input[i / n][i % n] = Integer.parseInt(val[i]);
        }

        int steps = snakesAndLadder(input);
        System.out.println("Total Steps Required: " + steps);
    }

    static int snakesAndLadder(int[][] input) {
        int n = input.length;
        int board[][] = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = input[n - 1 - i][j];

        int distance[] = new int[n * n + 1];
        for (int i = 0; i <= n * n; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[1] = 0;

        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);

        while (q.isEmpty() == false) {
            int node = q.remove();
            for (int i = 1; i <= 6; i++) {
                if (node + i <= n * n) {
                    int cellVal;
                    if (((node + i - 1) / n) % 2 == 0)
                        cellVal = board[(node + i - 1) / n][(node + i - 1) % n];
                    else
                        cellVal = board[(node + i - 1) / n][n - (node + i - 1) % n - 1];

                    int next = cellVal == -1 ? node + i : cellVal;
                    if (next <= n * n && distance[next] > distance[node] + 1) {
                        distance[next] = distance[node] + 1;
                        q.add(next);
                    }
                }
            }
        }
        return (distance[n * n] == Integer.MAX_VALUE ? -1 : distance[n * n]);
    }
}
