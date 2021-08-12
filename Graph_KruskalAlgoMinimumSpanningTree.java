/*///////////////////// Q 347: Babbar450: Implement Kruskal's ALgorithm ///////////////////////
Implement Kruskal's Algorithm in order to find minimum spanning tree for given graph.
////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////// Solution ////////////////////////////////////
Time Complexity : 
            O(n log n ) for sorting the list of edges based on weights
            O(n * 4 C) where O(4C ) is complexity for Union find algo

    Final Time complexity = O(n log n).


Space Complexity = O(3 * n) or O(n) for parent, rank and edge list.
//////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;

class NodeComparator implements Comparator<KruskalEdge> {
    @Override
    public int compare(KruskalEdge n1, KruskalEdge n2) {
        if (n1.w < n2.w)
            return -1;
        else if (n1.w > n2.w)
            return 1;
        else
            return 0;
    }
}

class KruskalEdge {
    int u, v, w;

    KruskalEdge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

public class Graph_KruskalAlgoMinimumSpanningTree {
    public static void main(String[] args) throws IOException {
        int n, e;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String ne[] = reader.readLine().trim().split(" ");
        n = Integer.parseInt(ne[0]);
        e = Integer.parseInt(ne[1]);

        ArrayList<KruskalEdge> edges = new ArrayList<KruskalEdge>();

        for (int i = 0; i < e; i++) {
            String edgeNodes[] = reader.readLine().trim().split(" ");
            int u = Integer.parseInt(edgeNodes[0]);
            int v = Integer.parseInt(edgeNodes[1]);
            int w = Integer.parseInt(edgeNodes[2]);

            edges.add(new KruskalEdge(u, v, w));
        }

        edges.sort(new NodeComparator());
        FindMstDisjointSet obj = new FindMstDisjointSet(n);
        ArrayList<KruskalEdge> mst = obj.findMinSpanningTree(edges);
        for (KruskalEdge edge : mst)
            System.out.println(edge.u + " " + edge.v);
    }
}

class FindMstDisjointSet {
    int v;
    int rank[];
    int parent[];

    public FindMstDisjointSet(int v) {
        this.v = v;
        rank = new int[v + 1];
        parent = new int[v + 1];

        for (int i = 1; i < v; i++) {
            parent[i] = i;
        }
    }

    public ArrayList<KruskalEdge> findMinSpanningTree(ArrayList<KruskalEdge> edges) {
        edges.sort(new NodeComparator());
        ArrayList<KruskalEdge> result = new ArrayList<KruskalEdge>();
        int counter = 0;
        int cost = 0;
        for (KruskalEdge edge : edges) {
            int p1 = findParent(edge.u);
            int p2 = findParent(edge.v);

            if (p1 != p2) {
                union(edge.u, edge.v);
                result.add(edge);
                counter++;
                cost += edge.w;
                if (counter >= v - 1)
                    break;
            }
        }
        System.out.println("Cost : " + cost);
        return result;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    boolean union(int nodeA, int nodeB) {
        int a = findParent(nodeA);
        int b = findParent(nodeB);

        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
            } else if (rank[b] < rank[a]) {
                parent[b] = a;
            } else {
                parent[a] = b;
                rank[b]++;
            }
        } else
            return false;

        return true;

    }
}
