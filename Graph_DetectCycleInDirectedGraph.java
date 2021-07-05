
/*///////////////////// Q 333: Babbar450: Detect Cycle in directed Graph ///////////////////////
Given an directed graph with V vertices and E edges, check whether it contains any cycle or not.
////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Graph_DetectCycleInDirectedGraph {
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

        }
        boolean ans = isCycle(V, adj);
        if (ans)
            System.out.println("1");
        else
            System.out.println("0");
    }

    /*
     * To detect a cycle, we need to keep track of vertices currently in the
     * recursion stack of function for DFS traversal. If a vertex is reached that is
     * already in the recursion stack, then there is a cycle in the tree. we'll use
     * a boolean array to store visited nodes in current recursion stack, and while
     * backtracking we'll unset those node since they are no longer in the recursion
     * stack. We'll also have another array to track visited nodes, so that while
     * visiting aparticular path if we reach to a already visited node which is not
     * in the current recursion stack then we don't need to check further, we can
     * directly return false from there.
     * 
     * Algorithm:
     * 
     * 1. Create a recursive function that initializes the current index or vertex,
     * visited, and recursion stack.
     * 
     * 2. Mark the current node as visited and also mark the index in recursion
     * stack.
     * 
     * 3. Find all the vertices which are not visited and are adjacent to the
     * current node. Recursively call the function for those vertices, If the
     * recursive function returns true, return true.
     * 
     * 4. else if the adjacent vertices are already marked as visited and also part
     * of current recursion stack then return true since it is alrady visited in the
     * same path, there is a cycle present.
     * 
     * Time Complexity O(v+e) and Space Complexity = O(v+e)
     */
    public static boolean isCycle(int v, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[v];
        boolean visitStack[] = new boolean[v]; // to track nodes present in recursion stack currently
        for (int i = 0; i < v; i++) {
            if (visited[i] != true)
                if (dfsCycle1(i, adj, visitStack, visited) == true)
                    return true;
        }
        return false;
    }

    //////////////////////// Approach 1 /////////////////////////
    private static boolean dfsCycle1(int node, ArrayList<ArrayList<Integer>> adj, boolean visitStack[],
            boolean visited[]) {
        if (visitStack[node] == true)
            return true;

        if (visited[node] == true)
            return false;

        visitStack[node] = true;
        visited[node] = true;

        for (int n : adj.get(node)) {
            // if (dfsCycle1(n, adj, visitStack, visited) == true)
            if (dfsCycle2(n, adj, visitStack, visited) == true)
                return true;
        }
        visitStack[node] = false;
        return false;
    }

    ////////////////////////////////// Approach 2 ////////////////////////////////
    private static boolean dfsCycle2(int node, ArrayList<ArrayList<Integer>> adj, boolean visitStack[],
            boolean visited[]) {
        visitStack[node] = true;
        visited[node] = true;

        for (int n : adj.get(node)) {
            if (visited[n] != true) { // if not visited
                if (dfsCycle2(n, adj, visitStack, visited) == true)
                    return true;
            } else if (visitStack[n] == true) // if visited in the same recursion stack
                return true;
        }
        visitStack[node] = false;
        return false;
    }
}
