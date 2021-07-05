
/*///////////////////// Q 334: Babbar450: Detect Cycle in Undirected Graph ///////////////////////
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;

public class Graph_DetectCycleInUndirectedGraph {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().trim().split(" ");
        int V = Integer.parseInt(s[0]);
        int E = Integer.parseInt(s[1]);
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < V; i++)
            adj.add(i, new ArrayList<Integer>());
        for (int i = 0; i < E; i++) {
            String[] S = br.readLine().trim().split(" ");
            int u = Integer.parseInt(S[0]);
            int v = Integer.parseInt(S[1]);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        // SolutionDFS obj = new SolutionDFS();
        SolutionBFS obj = new SolutionBFS();
        boolean ans = obj.isCyclic(V, adj);
        if (ans)
            System.out.println("1");
        else
            System.out.println("0");
    }
}

/*
 * When we do a DFS, we follow a particular path at a time till its end. in this
 * path if we encounter a node which we have already visited then it means there
 * is a cycle in the graph.
 * 
 * For checking the cycle we can use the visited array, if a node is already
 * marked as visited we can return true since it is an indication of the cycle.
 * But there is an edge case, for each pair of node in undirected graph there
 * are two entries in the adjacency list. (i,j) abd (j,i). while doing DFS if we
 * move from i to jth node, we need to ensure that (j,i) will not be considered
 * as a loop. for this we can use the parent node while calling the method
 * recursively. we'll not call the method for parent node present in the
 * adjacency list of child node.
 */
class SolutionDFS {
    public boolean isCyclic(int v, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[v];
        for (int i = 0; i < v; i++) {
            if (visited[i] != true) {
                if (dfsForCycle(i, -1, adj, visited) == true)
                    return true;
            }
        }
        return false;
    }

    private boolean dfsForCycle(int curr, int prev, ArrayList<ArrayList<Integer>> adj, boolean visited[]) {
        if (visited[curr] == true)
            return true;

        visited[curr] = true;
        for (int node : adj.get(curr)) {
            if (node != prev) {
                if (true == dfsForCycle(node, curr, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

}

class SolutionBFS {
    public boolean isCyclic(int v, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[v];
        for (int i = 0; i < v; i++) {
            if (visited[i] != true)
                if (bfsForCycle(i, visited, adj) == true)
                    return true;
        }
        return false;
    }

    private boolean bfsForCycle(int start, boolean visited[], ArrayList<ArrayList<Integer>> adj) {
        LinkedList<ArrayList<Integer>> q = new LinkedList<ArrayList<Integer>>();
        ArrayList<Integer> firstPair = new ArrayList<Integer>();

        // in a pair first element is node and second is its parent
        firstPair.add(start);
        firstPair.add(-1); // parent
        q.add(firstPair);
        visited[start] = true;

        while (q.isEmpty() != true) {
            ArrayList<Integer> pair = q.poll();
            int node = pair.get(0);
            int parent = pair.get(1);
            for (int n : adj.get(node)) {
                if (visited[n] != true) {
                    visited[n] = true;
                    ArrayList<Integer> childPair = new ArrayList<Integer>();
                    childPair.add(n);
                    childPair.add(node);
                    q.add(childPair);
                } else if (n != parent)
                    return true;
            }
        }
        return false;
    }
}