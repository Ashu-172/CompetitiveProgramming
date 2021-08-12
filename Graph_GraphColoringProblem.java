
/*///////////////////// Q 353: Babbar450: Graph Coloring Problem ///////////////////////
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
Note: In the given 2d-array graph[], if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 20
1 ≤ E ≤ (N*(N-1))/2
1 ≤ M ≤ N
//////////////////////////////////////////////////////////////////////////////////////*/
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Graph_GraphColoringProblem {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int V = scan.nextInt();
        int C = scan.nextInt();
        int E = scan.nextInt();

        List<Integer>[] G = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            int u = scan.nextInt() - 1;
            int v = scan.nextInt() - 1;
            G[u].add(v);
            G[v].add(u);
        }
        int[] color = new int[V];
        GraphColorRecursive obj = new GraphColorRecursive();
        System.out.println(obj.graphColoring(G, color, V, C) ? 1 : 0);
        scan.close();
    }
}

class GraphColorRecursive {
    public boolean graphColoring(List<Integer>[] adj, int[] color, int n, int c) {
        boolean visited[] = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] != true)
                color[i] = 1;
            if (false == fillColor(adj, color, n, c, i, visited))
                return false;
        }
        return true;
    }

    boolean fillColor(List<Integer>[] adj, int[] colored, int n, int c, int node, boolean[] visited) {
        for (int next : adj[node]) {
            if (colored[next] == 0) {
                for (int i = 1; i <= c; i++) {
                    if (isSafe(adj[next], colored, i)) {
                        colored[next] = i;
                        if (fillColor(adj, colored, n, c, next, visited) == true)
                            break;
                        else
                            colored[next] = 0;
                    }
                }
            }
            if (colored[next] == 0)
                return false;
        }
        visited[node] = true;
        return true;
    }

    boolean isSafe(List<Integer> nodeAdj, int[] colored, int color) {
        for (int node : nodeAdj) {
            if (colored[node] == color)
                return false;
        }
        return true;
    }
}
