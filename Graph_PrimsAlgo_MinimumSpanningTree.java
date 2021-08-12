
/*///////////////////// Q 348: Babbar450: Implement Prim's ALgorithm ///////////////////////
Implement Prim's Algorithm in order to find minimum spanning tree for given graph.
//////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

/*//////////////////////////////// Solution ////////////////////////////////////

Ref: https://www.youtube.com/watch?v=HnD676J56ak&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=20
Time Complexity : Time Complexity for this solution is O(n * (n + e))
            
Space Complexity : Space Complexity for this solution is O(n)

//////////////////////////////////////////////////////////////////////////////*/
class PrimEdge {
    int u, v, w;

    PrimEdge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

public class Graph_PrimsAlgo_MinimumSpanningTree {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Pair>> list = new ArrayList<ArrayList<Pair>>();
        String st[] = read.readLine().trim().split(" ");
        int n = Integer.parseInt(st[0]);
        int edg = Integer.parseInt(st[1]);

        for (int i = 0; i < n + 1; i++)
            list.add(i, new ArrayList<Pair>());

        for (int i = 1; i <= edg; i++) {
            String s[] = read.readLine().trim().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            int w = Integer.parseInt(s[2]);
            list.get(u).add(new Pair(v, w));
        }

        // ArrayList<Pair> mst = findMinSpanningTree(n, list);
        ArrayList<Pair> mst = findMSTOptimized(n, list);
        for (Pair edge : mst)
            System.out.println(edge.v + " " + edge.w);
    }

    static ArrayList<Pair> findMinSpanningTree(int n, ArrayList<ArrayList<Pair>> adj) {
        int distance[] = new int[n]; // store the minimum distance
        int parent[] = new int[n]; // store parent nodes
        boolean inMST[] = new boolean[n]; // mark nodes added to MST

        ArrayList<Pair> result = new ArrayList<Pair>();

        for (int i = 0; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }
        distance[0] = 0;

        // iterate n-1 times because MST has n-1 edges
        for (int i = 0; i < n - 1; i++) {
            int next = findNextNode(n, distance, inMST);

            inMST[next] = true; // adding to MST
            for (Pair node : adj.get(next)) {
                if (inMST[node.v] != true) {
                    if (distance[node.v] > node.w) {
                        distance[node.v] = node.w;
                        parent[node.v] = next;
                    }
                }
            }
        }
        // check from the 1st node, because 0th node won't have parent
        for (int i = 1; i < n; i++) {
            result.add(new Pair(parent[i], i));
        }
        return result;
    }

    static int findNextNode(int n, int distance[], boolean inMST[]) {
        int minDistNode = -1;
        int minDist = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (inMST[i] != true && distance[i] < minDist) {
                minDist = distance[i];
                minDistNode = i;
            }
        }
        return minDistNode;
    }

    /////////////////// Solution 2 (Optimized) ///////////////////////////////
    /*
     * in the above solution we are using findNextNode funtction which gives us the
     * node with minimum distance which is not part of MST. time complexity for this
     * method is O(N) which is making Time complexity of this solution O(N^2). we
     * can use priority queue to reduce the complexity to O(log n) for finding
     * minimum distant node which is not part of MST.
     */
    static ArrayList<Pair> findMSTOptimized(int n, ArrayList<ArrayList<Pair>> adj) {
        int distance[] = new int[n]; // store the minimum distance
        int parent[] = new int[n];
        boolean inMST[] = new boolean[n];
        PriorityQueue<Edge> minHeapDist = new PriorityQueue<Edge>();
        ArrayList<Pair> result = new ArrayList<Pair>();

        for (int i = 0; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }

        minHeapDist.add(new Edge(0, 0));

        // iterate n-1 times because MST has n-1 edges
        for (int i = 0; i < n - 1; i++) {
            Edge min = minHeapDist.poll();
            inMST[min.node] = true;
            for (Pair p : adj.get(min.node)) {
                if (inMST[p.v] != true && distance[p.v] > p.w) {
                    minHeapDist.add(new Edge(p.v, p.w));
                    distance[p.v] = p.w;
                    parent[p.v] = min.node;
                }
            }
        }

        // check from the 1st node, because 0th node won't have parent
        for (int i = 1; i < n; i++) {
            result.add(new Pair(parent[i], i));
        }
        return result;
    }
}
