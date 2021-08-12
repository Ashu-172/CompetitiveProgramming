
/*///////////////////// Q: Striver- Graph Series : Shortest path in weighted DAG ///////////////////////
Find shortest path from source node to all other nodes in a weighted Directed Acyclic Graph.
Refer: https://www.youtube.com/watch?v=CrxG4WJotgg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////// Solution ///////////////////////////////////
we can implement this using simple DFS algorithm, whenever we reach to a node we need to check whether its current distance is smaller than its previously calculated distance or not. if it is then we'll update the distance with smaller value. in this way in the end of the dfs we'll have smallest distance to all nodes from source node.

This approach is not the best approach because we need to do repeatative work. consider the case when we already updated a node's distance by a dfs() call and lets say its 7 and as it is DFS then its obvious that we also have updated all the nodes in its segment of DFS call . now lets say we have reached to the same node from different dfs() call and now the distance is 4 , so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , we now again have to do the same so that its updated with new min distance.
Same is the scenario for the simple BFS approach.

To improve it we can use the topological sort, it'll give us the order in which we have to traverse instead of processing in all other orders.
Following is complete algorithm for finding shortest distances. 
1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex. 
2) Create a topological order of all vertices. 
3) Do following for every vertex u in topological order. 
………..Do following for every adjacent vertex v of u 
………………if (dist[v] > dist[u] + weight(u, v)) 
………………………dist[v] = dist[u] + weight(u, v) 

Time Complexity: 
Time complexity of topological sorting is O(V+E). After finding topological order, the algorithm process all vertices and for every vertex, it runs a loop for all adjacent vertices. Total adjacent vertices in a graph is O(E). So the total time complexity will be O(E) + O(V+E) = O(V+E)


Note: 
For a general weighted graph, we can calculate single source shortest distances in O(VE) time using Bellman–Ford Algorithm. 
For a graph with no negative weights, we can do better and calculate single source shortest distances in O(E + VLogV) time using Dijkstra’s algorithm. 
For Directed Acyclic Graph (DAG) we can calculate single source shortest distances in O(V+E) time using Topological Sorting.
///////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Pair {
    int v, w;

    public Pair(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

public class Graph_ShortestPathInWeightedDAG_TopoSort {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Pair>> list = new ArrayList<ArrayList<Pair>>();
        String st[] = read.readLine().trim().split(" ");
        int edg = Integer.parseInt(st[0]);
        int n = Integer.parseInt(st[1]);

        for (int i = 0; i < n + 1; i++)
            list.add(i, new ArrayList<Pair>());

        for (int i = 1; i <= edg; i++) {
            String s[] = read.readLine().trim().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            int w = Integer.parseInt(s[2]);
            list.get(u).add(new Pair(v, w));
        }

        int topoSort[] = topoSortUtil(n, list);
        int path[] = findShortestPath(n, topoSort, list);
        for (int node : topoSort)
            System.out.print(node + " ");
        System.out.println();

        for (int dist : path)
            System.out.print(dist + " ");
        System.out.println();

    }

    static int[] topoSortUtil(int n, ArrayList<ArrayList<Pair>> adj) {
        int indegree[] = new int[n];
        int result[] = new int[n];
        int index = 0;

        for (int i = 0; i < n; i++) {
            for (Pair pair : adj.get(i))
                indegree[pair.v]++;
        }

        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.add(i);

        while (q.isEmpty() != true) {
            int node = q.poll();
            result[index++] = node;
            for (Pair adjNode : adj.get(node)) {
                indegree[adjNode.v]--;
                if (indegree[adjNode.v] == 0) {
                    q.add(adjNode.v);
                }
            }
        }
        return result;
    }

    static int[] findShortestPath(int n, int[] toposort, ArrayList<ArrayList<Pair>> adj) {
        int path[] = new int[n];
        for (int i = 0; i < n; i++) {
            path[i] = Integer.MAX_VALUE;
        }

        path[toposort[0]] = 0;
        for (int i = 0; i < n; i++) {
            int node = toposort[i];
            for (Pair pair : adj.get(node)) {
                if (path[node] + pair.w < path[pair.v]) {
                    path[pair.v] = path[node] + pair.w;
                }
            }
        }
        return path;
    }
}
