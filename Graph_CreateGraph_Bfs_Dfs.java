import java.util.ArrayList;
import java.util.LinkedList;

public class Graph_CreateGraph_Bfs_Dfs {
    ArrayList<ArrayList<Integer>> adj;
    int vertices = 0;

    public Graph_CreateGraph_Bfs_Dfs(int size) {
        vertices = size;
        adj = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < size; i++) {
            adj.add(new ArrayList<Integer>());
        }
    }

    boolean createEdge(int u, int v) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
            return false;

        adj.get(u).add(v);
        adj.get(v).add(u);
        return true;
    }

    void bfs(boolean visited[], int node) {
        visited[node] = true;
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(node);

        while (q.isEmpty() != true) {
            int curr = q.poll();
            System.out.print(curr + " ");

            for (int next : adj.get(curr)) {
                if (visited[next] != true)
                    q.add(next);
                visited[next] = true;
            }
        }
    }

    void bfs_helper() {
        boolean visited[] = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            if (visited[i] == false)
                bfs(visited, i);
        }
        System.out.println();
    }

    void dfs(boolean visited[], int node) {
        visited[node] = true;
        System.out.print(node + " ");
        for (int num : adj.get(node)) {
            if (visited[num] != true)
                dfs(visited, num);
        }
    }

    void dfs_helper() {
        boolean visited[] = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            if (visited[i] != true)
                dfs(visited, i);
        }
        System.out.println();
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

    public static void main(String[] args) {
        Graph_CreateGraph_Bfs_Dfs graph = new Graph_CreateGraph_Bfs_Dfs(8);
        graph.createEdge(0, 1);
        graph.createEdge(0, 4);
        graph.createEdge(1, 2);
        graph.createEdge(1, 3);
        graph.createEdge(1, 4);
        graph.createEdge(2, 3);
        graph.createEdge(3, 4);

        graph.createEdge(5, 6);
        graph.createEdge(7, 5);

        graph.printGraph();
        graph.bfs_helper();
        graph.dfs_helper();
    }
}
