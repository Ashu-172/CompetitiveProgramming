
/*///////////////////// Q 357: Babbar450: Detect Cycle in Undirected Graph ///////////////////////
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;

public class Graph_BipartiteGraph {
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
        Bipartite obj = new Bipartite();
        boolean ans = obj.isBipartite(V, adj);
        if (ans)
            System.out.println("1");
        else
            System.out.println("0");
    }
}

class Bipartite {
    boolean isBipartite(int v, ArrayList<ArrayList<Integer>> adj) {
        int colored[] = new int[v];
        for (int i = 0; i < v; i++) {
            if (colored[i] == 0) {
                // if (false == checkBipartiteBFS(i, adj, colored))
                if (false == checkBipartiteDFS(i, adj, colored))
                    return false;
            }
        }
        return true;
    }

    boolean checkBipartiteBFS(int start, ArrayList<ArrayList<Integer>> adj, int colored[]) {
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.push(start); // node
        colored[start] = -1; // colores are -1 and 1

        while (q.isEmpty() != true) {
            int node = q.poll();
            for (int n : adj.get(node)) {
                if (colored[n] == 0) // not yet traversed or colored
                {
                    if (colored[node] == -1)
                        colored[n] = 1;
                    else
                        colored[n] = -1;

                    q.push(n);
                } else if (colored[n] == colored[node])
                    return false;
            }
        }
        return true;
    }

    boolean checkBipartiteDFS(int node, ArrayList<ArrayList<Integer>> adj, int colored[]) {
        if (colored[node] == 0)
            colored[node] = 1;
        for (int n : adj.get(node)) {
            if (colored[n] == 0) {
                colored[n] = (colored[node] == -1) ? 1 : -1;
                if (false == checkBipartiteDFS(n, adj, colored))
                    return false;
            } else if (colored[n] == colored[node])
                return false;
        }
        return true;
    }
    /*
     * Time Complexity : O(N+E)
     * 
     * Space Complexity = O(N+E) for adjacency list + O(N) for Queue or recursion
     * stack + O(N) for color array
     */
}
