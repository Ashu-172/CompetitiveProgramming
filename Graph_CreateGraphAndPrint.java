/*///////////////////// Q 330,331,332: Babbar450: Implement Graph, BFS and DFS ///////////////////
Implement a Graph using Adjacency list and perform Bfs and Dfs traversal on it.
////////////////////////////////////////////////////////////////////////////////////////////////*/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.ListIterator;

public class Graph_CreateGraphAndPrint {
    public static void main(String[] args) {
        Graph graph = new Graph(5);
        graph.createEdge(0, 1);
        graph.createEdge(0, 4);
        graph.createEdge(1, 2);
        graph.createEdge(1, 3);
        graph.createEdge(1, 4);
        graph.createEdge(2, 3);
        graph.createEdge(3, 4);

        graph.printGraph();
        System.out.println();
        graph.bfsOfGraph();
        System.out.println();
        graph.dfsOfGraph();

    }
}

class Graph {
    private ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
    private int vertices = 0;

    Graph(int size) {
        this.vertices = size;
        for (int i = 0; i < size; i++) {
            adj.add(new ArrayList<Integer>());
        }
    }

    boolean createEdge(int u, int v) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
            return false;
        else {
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        return true;
    }

    void printGraph() {
        for (int i = 0; i < adj.size(); i++) {
            System.out.print(i + " : ");
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.print(adj.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    ////////////////////////////// BFS ///////////////////////
    /**
     * Time complexity : O(v+e) because we are visiting each edge and node only once
     * Space Complexity : O(V) for visited array
     */
    public void bfsOfGraph() {
        boolean visited[] = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            if (visited[i] != true)
                bfs(visited, i);
        }

    }

    private void bfs(boolean visited[], int start) {
        LinkedList<Integer> q = new LinkedList<Integer>();

        visited[start] = true;
        q.addLast(start);

        while (q.size() != 0) {
            int node = q.poll(); // pull the element from queue and delete from the queue (LinkedList)
            System.out.print(node + " ");
            for (int next : adj.get(node)) {
                if (visited[next] != true) {
                    q.add(next);
                    visited[next] = true;
                }
            }
        }
    }

    /////////////////////////// DFS ////////////////////////////////
    /**
     * Time complexity : O(v + e) because we are visiting each edge and node only
     * once Space Complexity : O(V) for visited array
     */
    public void dfsOfGraph() {
        boolean visited[] = new boolean[vertices];

        for (int i = 0; i < vertices; i++) {
            if (visited[i] != true)
                dfs(i, visited);
        }
    }

    private void dfs(int node, boolean visited[]) {
        if (visited[node] == true)
            return;

        visited[node] = true;
        System.out.print(node + " ");
        ListIterator<Integer> itr = adj.get(node).listIterator();

        while (itr.hasNext()) {
            int next = itr.next();
            dfs(next, visited);
        }
    }
}