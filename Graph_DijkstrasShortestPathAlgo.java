
/*///////////////////// Q 342: Babbar450: Dijkstra's Shortest Path Algorithm ///////////////////////
Implement Dijkstra's Shortest Path Algorithm.
//////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

// Note: Dijkstra's algo can be performed on any type of graph
// Ref: https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=18
public class Graph_DijkstrasShortestPathAlgo {
    public static void main(String[] args) throws IOException {
        int n, e;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String ne[] = reader.readLine().trim().split(" ");
        n = Integer.parseInt(ne[0]);
        e = Integer.parseInt(ne[1]);

        ArrayList<ArrayList<Edge>> adj = new ArrayList<ArrayList<Edge>>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Edge>());
        }

        for (int i = 0; i < e; i++) {
            String edge[] = reader.readLine().trim().split(" ");
            int u = Integer.parseInt(edge[0]); // start of edge
            int v = Integer.parseInt(edge[1]); // end of edge
            int w = Integer.parseInt(edge[2]); // weight
            for (int j = 0; j < e; j++) {
                adj.get(u).add(new Edge(v, w));
                adj.get(v).add(new Edge(u, w));
            }
        }

        int start, end;
        String startend[] = reader.readLine().trim().split(" ");
        start = Integer.parseInt(startend[0]);
        end = Integer.parseInt(startend[1]);

        ShortestPathDijkstra obj = new ShortestPathDijkstra();

        int distance[] = obj.findAllShortestPaths(n, start, adj);

        for (int i = 0; i < n; i++) {
            System.out.print(distance[i] + " ");
        }

        System.out.println(distance[end]);
    }
}

class Edge implements Comparable<Edge> {
    int node;
    int dist;

    Edge(int node, int dist) {
        this.node = node;
        this.dist = dist;
    }

    @Override
    public int compareTo(Edge o) {
        return this.dist - o.dist;
    }
}

class ShortestPathDijkstra {
    int[] findAllShortestPaths(int n, int start, ArrayList<ArrayList<Edge>> adj) {
        int distance[] = new int[n];
        for (int i = 0; i < n; i++)
            distance[i] = Integer.MAX_VALUE;

        distance[start] = 0;
        PriorityQueue<Edge> minHeap = new PriorityQueue<Edge>();
        minHeap.add(new Edge(start, distance[start]));

        while (minHeap.isEmpty() != true) {
            Edge edge = minHeap.poll();
            for (Edge next : adj.get(edge.node)) {
                if (edge.dist + next.dist < distance[next.node]) {
                    distance[next.node] = edge.dist + next.dist;
                    minHeap.add(new Edge(next.node, distance[next.node]));
                }
            }
        }
        return distance;
    }
}
