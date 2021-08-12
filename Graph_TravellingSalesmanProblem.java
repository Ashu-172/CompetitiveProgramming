
/*///////////////////// Q 352: Babbar450: Travelling Salesman Problem ///////////////////////
Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
 

Example 1:

Input: cost = {{0,111},{112,0}}
Output: 223
Explanation: We can visit 0->1->0 and 
cost = 111 + 112.
Example 2:

Input: cost = {{0,1000,5000},{5000,0,1000},
{1000,5000,0}}
Output: 3000
Explanation: We can visit 0->1->2->0 and cost 
= 1000+1000+1000 = 3000

Expected Time Complexity: O(2n * n2)
Expected Space Compelxity: O(2n * n)
 

Constraints:
1 <= n <= 10
1 <= cost[i][j] <= 103
///////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class Graph_TravellingSalesmanProblem {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine().trim());
        int[][] cost = new int[n][n];
        for (int i = 0; i < n; i++) {
            String[] S = br.readLine().trim().split(" ");
            for (int j = 0; j < n; j++)
                cost[i][j] = Integer.parseInt(S[j]);
        }
        MinimumCostPath obj = new MinimumCostPath();
        MinimumCostPath_DP obj2 = new MinimumCostPath_DP();
        int ans = obj.total_cost(cost);
        int ans2 = obj2.total_cost(cost);
        System.out.println(ans + " " + ans2);
    }
}

///////////////////////// Solution 1 : Naive Approach ////////////////////
/*
 * 1) Consider city 0 as the starting and ending point.
 * 
 * 2) Generate all (n-1)! Permutations of cities.
 * 
 * 3) Calculate cost of every permutation and keep track of minimum cost
 * permutation.
 * 
 * 4) Return the permutation with minimum cost.
 * 
 * Time Complexity = O(!n)
 */
class MinimumCostPath {
    int gTotalCost = Integer.MAX_VALUE;
    Vector<Integer> result;

    public int total_cost(int[][] cost) {
        Vector<Integer> currStack = new Vector<Integer>();
        int n = cost.length;
        int currCost = 0;
        int count = 0;
        boolean visited[] = new boolean[n];
        visited[0] = true;

        calculateTotalCost(cost, 0, currStack, visited, currCost, count, n);

        for (int node : result)
            System.out.print(node + " ");
        System.out.println();
        return gTotalCost;
    }

    void calculateTotalCost(int[][] cost, int node, Vector<Integer> currStack, boolean visited[], int currCost,
            int count, int n) {
        if (count == n - 1 && gTotalCost > currCost + cost[node][0]) {
            gTotalCost = currCost + cost[node][0];
            currStack.add(0);
            result = (Vector<Integer>) currStack.clone();
            currStack.remove(currStack.size() - 1);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                visited[i] = true;
                currStack.add(i);
                calculateTotalCost(cost, i, currStack, visited, currCost + cost[node][i], count + 1, n);
                currStack.remove(currStack.size() - 1);
                visited[i] = false;
            }
        }
    }
}

/*
 * ///////////////////////// Solution 2 (DP) //////////////////// Ref:
 * https://www.youtube.com/watch?v=hh-uFQ-MGfw
 * 
 * Time Complexity : There are at most O(n * 2^n) subproblems, and each one
 * takes linear time to solve. The total running time is therefore O(n^2 * 2^n).
 *//////////////////////////////////////////////////////////////
class MinimumCostPath_DP {
    public int total_cost(int[][] cost) {
        int n = cost.length;
        boolean visited[] = new boolean[n];
        visited[0] = true;
        int count = 1;

        return calculateMinimumCost(0, cost, visited, n, count);
    }

    int calculateMinimumCost(int node, int cost[][], boolean visited[], int n, int count) {
        if (count == n)
            return cost[node][0];

        int minCost = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                visited[i] = true;
                int currCost = cost[node][i] + calculateMinimumCost(i, cost, visited, n, count + 1);
                visited[i] = false;

                if (currCost < minCost)
                    minCost = currCost;
            }
        }
        return minCost;
    }
}