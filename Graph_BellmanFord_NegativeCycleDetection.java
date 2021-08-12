
/*///////////////////// Q 350: Babbar450: Implement Bellman Ford Algorithm ///////////////////////
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 

Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
 

Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.
////////////////////////////////////////////////////////////////////////////////////////////////*/
/*/////////////////////////////////// Solution ///////////////////////////////////////////////////
For Finding Shortest paths to all the nodes from source node, we use dijkstra's algorithm.Dijkstra’s 
algorithm is a Greedy algorithm and time complexity is O(V+E LogV) (with the use of Fibonacci heap). 
Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs. 
Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. But time 
complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

Algorithm 
Following are the detailed steps.
Input: Graph and a source vertex src 
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest 
distances are not calculated, negative weight cycle is reported.

1) This step initializes distances from the source to all vertices as infinite and distance to the 
    source itself as 0. Create an array dist[] of size |V| with all values as infinite except 
    dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of 
    vertices in given graph. 
        a) Do following for each edge u-v 
              If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
                    dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v 
        If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle” 


The idea of step 3 is, step 2 guarantees that the shortest distances is calculated if the graph 
doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get 
a shorter path for any vertex, then there is a negative weight cycle.


Working:

Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. 
It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates 
the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the 
shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple 
path, that is why the outer loop runs |v| – 1 times. If we repeat the process one more time then shortest 
path distance  should not change if there is no cycle. if there is a negative cycle them the values for 
shortest path will get reduced which indicates the presence of negative cycle.

Time complexity = O(V*E)
Space complexity : O(V)
////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Graph_BellmanFord_NegativeCycleDetection {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] edges = new int[m][3];
            for (int i = 0; i < m; i++) {
                String S2[] = br.readLine().trim().split(" ");
                for (int j = 0; j < 3; j++)
                    edges[i][j] = Integer.parseInt(S2[j]);
            }
            BellmanFordAlgo obj = new BellmanFordAlgo();
            int ans = obj.isNegativeWeightCycle(n, edges);
            System.out.println(ans);
        }
    }
}

class BellmanFordAlgo {
    public int isNegativeWeightCycle(int n, int[][] edges) {
        int distance[] = new int[n];
        for (int i = 0; i < n; i++) {
            distance[i] = 100000000;
        }
        distance[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int[] edge : edges) {
                if (distance[edge[0]] + edge[2] < distance[edge[1]]) {
                    distance[edge[1]] = distance[edge[0]] + edge[2];
                }
            }
        }
        // Calculated shortest path
        // doing 1 extra iteration after n-1 iteration to detect negative cycle
        for (int[] edge : edges) {
            if (distance[edge[0]] + edge[2] < distance[edge[1]]) {
                return 1;
            }
        }

        return 0;
    }
}
