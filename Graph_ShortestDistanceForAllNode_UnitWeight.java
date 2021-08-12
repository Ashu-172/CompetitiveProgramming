
/*///////////////////// Q: Striver- Graph Series : Shortest Distance for all Nodes ///////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph_ShortestDistanceForAllNode_UnitWeight {
    public static void main(String[] args) throws IOException {
        int n, e;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String ne[] = reader.readLine().trim().split(" ");
        n = Integer.parseInt(ne[0]);
        e = Integer.parseInt(ne[1]);

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < e; i++) {
            String edgeNodes[] = reader.readLine().trim().split(" ");
            int u = Integer.parseInt(edgeNodes[0]);
            int v = Integer.parseInt(edgeNodes[1]);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int src = Integer.parseInt(reader.readLine().trim().split(" ")[0]);

        ShortestPath obj = new ShortestPath();
        int distances[] = obj.findShortestPaths(n, adj, src);

        for (int d : distances)
            System.out.print(d + " ");
    }
}

class ShortestPath {
    int[] findShortestPaths(int n, ArrayList<ArrayList<Integer>> adj, int src) {
        int distances[] = new int[n];
        for (int i = 0; i < n; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        distances[src] = 0;

        Queue<Integer> q = new LinkedList<Integer>();
        q.add(src);

        while (q.isEmpty() != true) {
            int node = q.remove();
            for (int e : adj.get(node)) {
                if (distances[node] + 1 < distances[e]) {
                    distances[e] = distances[node] + 1;
                    q.add(e);
                }
            }
        }

        return distances;
    }
}
