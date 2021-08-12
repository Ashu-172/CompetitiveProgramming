
/*///////////////////// Q 341: Babbar450: Implement Topological Sort ///////////////////////
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:
Input:
[[1,0], [2,0], [3,0]]

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.

Example 2:
Input:
[[1,3], [2,3], [4,1], [4,0], [5,2], [5,0]]

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 2, 1, 3, 4, 0.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then console output will be 1 else 0.


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).


Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
//////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graph_TopologicalSort {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        String st[] = read.readLine().trim().split(" ");
        int edg = Integer.parseInt(st[0]);
        int nov = Integer.parseInt(st[1]);

        for (int i = 0; i < nov + 1; i++)
            list.add(i, new ArrayList<Integer>());

        for (int i = 1; i <= edg; i++) {
            String s[] = read.readLine().trim().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            list.get(u).add(v);
        }

        int[] res1 = topoSort(nov, list);
        KahnTopoSort obj = new KahnTopoSort();

        int[] res2 = obj.topoSort(nov, list);

        for (int v : res1)
            System.out.print(v + " ");
        System.out.println();

        if (check(list, nov, res1) == true)
            System.out.println("1");
        else
            System.out.println("0");

        for (int v : res2)
            System.out.print(v + " ");
        System.out.println();

        if (check(list, nov, res2) == true)
            System.out.println("1");
        else
            System.out.println("0");
    }

    static boolean check(ArrayList<ArrayList<Integer>> list, int V, int[] res) {
        int[] map = new int[V];
        for (int i = 0; i < V; i++) {
            map[res[i]] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int v : list.get(i)) {
                if (map[i] > map[v])
                    return false;
            }
        }
        return true;
    }

    /////////////////////// Solution 1 (DFS) ////////////////////////
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
        int result[] = new int[V];

        boolean visited[] = new boolean[V];
        Stack<Integer> s = new Stack<Integer>();
        for (int i = 0; i < V; i++) {
            if (visited[i] != true) {
                dfs(i, adj, visited, s);
            }
        }

        for (int i = 0; i < V; i++) {
            result[i] = s.pop();
        }
        return result;
    }

    static void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean visited[], Stack<Integer> s) {
        if (visited[node] == true)
            return;

        visited[node] = true;
        for (int n : adj.get(node)) {

            dfs(n, adj, visited, s);

        }
        s.push(node);
    }

}
/////////////////////// Solution 2 (Kahn's Algo - BFS) ////////////////////////

class KahnTopoSort {
    int[] topoSort(int n, ArrayList<ArrayList<Integer>> adj) {
        int result[] = new int[n];
        int indegree[] = new int[n];
        Queue<Integer> q = new LinkedList<Integer>();
        int index = 0;

        // Finding indegree of all the nodes
        for (int i = 0; i < n; i++) {
            for (int node : adj.get(i)) {
                indegree[node]++;
            }
        }

        // inserting nodes in the queue where indegree is 0
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.add(i);

        while (q.isEmpty() != true) {
            int node = q.remove();
            result[index++] = node; // adding to the result array
            for (int v : adj.get(node)) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.add(v);
            }
        }
        return result;
    }
}
