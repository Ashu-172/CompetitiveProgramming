/*///////////////////// Q 334: Babbar450: Detect Cycle in Undirected Graph ///////////////////////
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
////////////////////////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Edge2 {
    int u;
    int v;

    Edge2(int u, int v) {
        this.u = u;
        this.v = v;
    }
}

public class Graph_DisjointSet_CycleDetectionUndirectedGraph {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().trim().split(" ");
        int V = Integer.parseInt(s[0]);
        int E = Integer.parseInt(s[1]);
        ArrayList<Edge2> edges = new ArrayList<>();

        for (int i = 0; i < E; i++) {
            String[] S = br.readLine().trim().split(" ");
            int u = Integer.parseInt(S[0]);
            int v = Integer.parseInt(S[1]);
            edges.add(new Edge2(u, v));
        }

        DisjointSet obj = new DisjointSet(V);
        boolean ans = obj.hasCycle(edges);
        if (ans)
            System.out.println("1");
        else
            System.out.println("0");
    }
}

class DisjointSet {
    int parent[];
    int rank[];
    int v;

    DisjointSet(int v) {
        this.v = v;
        parent = new int[v];
        rank = new int[v];

        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]); // level compression
    }

    void union(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (rank[parentU] < rank[parentV]) {
            parent[u] = parentV;
        } else if (rank[parentV] < rank[parentU]) {
            parent[v] = parentU;
        } else {
            parent[u] = parentV;
            rank[v]++; // hight gets increased for node v
        }
    }

    boolean hasCycle(ArrayList<Edge2> edges) {
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            Edge2 edge = edges.get(i);
            int parentU = findParent(edge.u);
            int parentV = findParent(edge.v);

            if (parentU == parentV)
                return true;

            union(edge.u, edge.v);
        }
        return false;
    }
}