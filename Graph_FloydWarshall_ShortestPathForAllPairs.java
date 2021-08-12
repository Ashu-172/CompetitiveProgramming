import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

/*///////////////////// Q 351: Babbar450: Floyd Warshall Algorithm ///////////////////////
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1.
 

Example 1:

Input: matrix = {{0,25},{-1,0}}
Output: {{0,25},{-1,0}}
Explanation: The shortest distance between
every pair is already given(if it exists).
Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}
Output: {{0,1,7},{1,0,6},{-1,-1,0}}
Explanation: We can reach 3 from 1 as 1->2->3
and the cost will be 1+6=7 which is less than 
43.
 

Your Task:
You don't need to read, return or print anything. Your task is to complete the function shortest_distance() which takes the matrix as input parameter and modify the distances for every pair in-place.
 

Expected Time Complexity: O(n3)
Expected Space Compelxity: O(1)
////////////////////////////////////////////////////////////////////////////////////////////////*/
public class Graph_FloydWarshall_ShortestPathForAllPairs {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] matrix = new int[n][n];
            for (int i = 0; i < n; i++) {
                String[] s = br.readLine().trim().split(" ");
                for (int j = 0; j < n; j++)
                    matrix[i][j] = Integer.parseInt(s[j]);
            }
            FloydWarshallAlgo obj = new FloydWarshallAlgo();
            obj.shortest_distance(matrix);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
            }
        }
    }
}

/*
 * //////////////////////// Solution 1 : Bellman Ford /////////////////////////
 * if we anaylze the Bellman Ford algo, we are calculating shortest path from
 * node 0. by using an additional loop we can do it for all the nodes. Time
 * complexity = O(n^2 * e)
 */
class Edge3 {
    int u, v, w;

    Edge3(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

class ShortestDistanceBellmanFord {

    void shortestPathBellmanFord(int[][] matrix) {

        int n = matrix.length;
        ArrayList<Edge3> edges = new ArrayList<Edge3>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > 0) {
                    edges.add(new Edge3(i, j, matrix[i][j]));
                }
                if (i != j)
                    matrix[i][j] = 1000000;
            }
        }

        for (int src = 0; src < n; src++) {
            for (int i = 0; i < n - 1; i++) {
                for (Edge3 e : edges) {
                    if (matrix[src][e.u] + e.w < matrix[src][e.v]) {
                        matrix[src][e.v] = matrix[src][e.u] + e.w;
                    }
                }
            }
        }
        // in the matrix value 1000000 will indicate not reachable nodes from src, it
        // can be converted to -1 by uncommenting following lines

        // for (int i = 0; i < n; i++)
        // for (int j = 0; j < n; j++)
        // if (matrix[i][j] == 1000000)
        // matrix[i][j] = -1;
    }
}

////////////////////////// Solution 2 : Dijkstra ////////////////////////
// Time Complexity = O(v * ((v+e) * log e))
class ShortestDistanceDijkstra {
    public void shortest_distance(int[][] matrix) {
        int n = matrix.length;
        for (int src = 0; src < n; src++) {
            int distance[] = new int[n];
            for (int i = 0; i < n; i++)
                distance[i] = Integer.MAX_VALUE;

            distance[src] = 0;
            PriorityQueue<Edge> minHeap = new PriorityQueue<Edge>();
            minHeap.add(new Edge(src, 0));
            while (minHeap.isEmpty() != true) {
                Edge p = minHeap.poll();
                for (int i = 0; i < n; i++) {
                    if (matrix[p.node][i] != -1 && p.dist + matrix[p.node][i] < distance[i]) {
                        distance[i] = p.dist + matrix[p.node][i];
                        minHeap.add(new Edge(i, distance[i]));
                    }
                }
            }
            for (int i = 0; i < n; i++)
                matrix[src][i] = (distance[i] != Integer.MAX_VALUE) ? distance[i] : -1;
        }
    }
}

/////////////////////////// Solution 3 : Floyd Warshall ////////////////////

class FloydWarshallAlgo {
    void shortest_distance(int matrix[][]) {
        // consider initial values as shortest distance between nodes i and j withput
        // any intermediate node. Now we'll add nodes k = 0 to n-1 one by one as
        // intermediate nodes between i and j to get more shorter distances.
        int n = matrix.length;

        // setting distance for unreachable node as infinite
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1000000;

        // potential intermediate node
        for (int k = 0; k < n; k++) {
            // source vertices
            for (int i = 0; i < n; i++) {
                // destination node
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }

        // in the matrix value 1000000 will indicate not reachable nodes from src, it
        // can be converted to -1 by uncommenting following lines
        // for (int i = 0; i < n; i++)
        // for (int j = 0; j < n; j++)
        // if (matrix[i][j] == 1000000)
        // matrix[i][j] = -1;
    }
}