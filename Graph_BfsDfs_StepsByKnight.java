/*///////////////////// Q 336: Babbar450: Minimum Steps By Knight ///////////////////////
Given an directed graph with V vertices and E edges, check whether it contains any cycle or not.
////////////////////////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Graph_BfsDfs_StepsByKnight {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        String[] S1 = br.readLine().trim().split(" ");
        String[] S2 = br.readLine().trim().split(" ");
        int[] KnightPos = new int[2];
        int[] TargetPos = new int[2];
        for (int i = 0; i < 2; i++) {
            KnightPos[i] = Integer.parseInt(S1[i]);
            TargetPos[i] = Integer.parseInt(S2[i]);
        }
        // StepsCalculatorDFS obj = new StepsCalculatorDFS();
        StepsCalculatorBFS obj = new StepsCalculatorBFS();
        int ans = obj.minStepToReachTargetBFS(KnightPos, TargetPos, N);
        System.out.println(ans);
    }
}
// Here in DFS Solution we will check all the paths, which will be bad for time
// complexity and lead to StackOverflow error for larger input, DFS algorithm
// goes deeper and deeper on all the paths even if the shortes path was found
// much earlier. if we use BFS here we can return the minSteps when we find the
// first path to the target because it'll be the smallest path.

//////////////////////////////////// DFS Solution ///////////////////////////
class StepsCalculatorDFS {
    int minSteps = Integer.MAX_VALUE;

    // Function to find out minimum steps Knight needs to reach target position.
    public int minStepToReachTargetDFS(int KnightPos[], int TargetPos[], int N) {
        int moves[][] = { { 2, 1 }, { -2, 1 }, { 2, -1 }, { -2, -1 }, { 1, 2 }, { -1, 2 }, { 1, -2 }, { -1, -2 } };
        int board[][] = new int[N][N];
        int steps = 0;
        findMinStepsDFS(KnightPos, TargetPos, moves, steps, board, N);
        return minSteps;
    }

    private void findMinStepsDFS(int curr[], int target[], int moves[][], int steps, int board[][], int n) {
        if (false == isSafe(curr, n, board))
            return;

        if (curr[0] == target[0] && curr[1] == target[1]) {
            if (steps < minSteps)
                minSteps = steps;
            return;
        }
        if (steps > minSteps)
            return;

        board[curr[0] - 1][curr[1] - 1] = 1;

        for (int i = 0; i < 8; i++) {
            int[] next = new int[2];
            next[0] = curr[0] + moves[i][0];
            next[1] = curr[1] + moves[i][1];
            findMinStepsDFS(next, target, moves, steps + 1, board, n);
        }
        board[curr[0] - 1][curr[1] - 1] = 0;

    }

    boolean isSafe(int curr[], int n, int board[][]) {
        if (curr[0] < 1 || curr[0] > n || curr[1] < 1 || curr[1] > n || board[curr[0] - 1][curr[1] - 1] == 1)
            return false;
        return true;
    }
}

class Coordinates {
    int x;
    int y;
    int dist;

    public Coordinates(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

class StepsCalculatorBFS {
    public int minStepToReachTargetBFS(int KnightPos[], int TargetPos[], int n) {
        int moves[][] = { { 2, 1 }, { -2, 1 }, { 2, -1 }, { -2, -1 }, { 1, 2 }, { -1, 2 }, { 1, -2 }, { -1, -2 } };
        boolean board[][] = new boolean[n + 1][n + 1];

        LinkedList<Coordinates> q = new LinkedList<Coordinates>();
        Coordinates start = new Coordinates(KnightPos[0], KnightPos[1], 0);

        q.add(start);

        while (q.isEmpty() == false) {

            Coordinates curr = q.poll();

            if (curr.x == TargetPos[0] && curr.y == TargetPos[1])
                return curr.dist;

            for (int i = 0; i < 8; i++) {
                Coordinates next = new Coordinates(curr.x + moves[i][0], curr.y + moves[i][1], curr.dist + 1);

                if (true == isSafe(next, n, board)) {
                    board[next.x][next.y] = true;
                    q.add(next);
                }
            }
        }
        return -1;
    }

    boolean isSafe(Coordinates curr, int n, boolean board[][]) {
        if (curr.x >= 1 && curr.x <= n && curr.y >= 1 && curr.y <= n && board[curr.x][curr.y] == false)
            return true;
        return false;
    }
}
