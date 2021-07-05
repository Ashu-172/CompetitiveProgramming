/*///////////////////// Q 339: Babbar450: Making Connected Graph/////////////////////
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
///////////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Graph_MakeNetworkConnected {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] S1 = br.readLine().trim().split(" ");
        int n = Integer.parseInt(S1[0]);
        int e = Integer.parseInt(S1[1]);
        int[][] edges = new int[e][2];
        for (int i = 0; i < e; i++) {
            String[] S2 = br.readLine().trim().split(" ");
            for (int j = 0; j < 2; j++)
                edges[i][j] = Integer.parseInt(S2[j]);
        }

        ConnectGraph obj = new ConnectGraph();
        System.out.println(obj.makeConnected(n, edges));
    }
}

/*
 * ////////////////////// Algorithm //////////////////////////////////////
 * 
 * 1. Total Number of the edges required to connect all the nodes will be total
 * number of components -1, because if there are 2 disconnected components
 * present in the graph, then we need 1 edge to connect them.
 * 
 * 2. while traversing the graph if we reached to a node which is already
 * visited then we can remove that edge because that edge is not needed, since
 * we have already visited that node it means there is some other edge which is
 * connecting it. so even if we remove current edge, graph will still remain
 * conected. so if we count all the edges which are leading to a node which is
 * already visited, we'll get the count of removable edges which we can use to
 * connect the graph.
 * 
 * This count should be divided by 2 to get the actual removable edge count
 * because for both the nodes same edge will get counted.
 * 
 * 3. if number of required edges are greater than the removable edges then we
 * can not make the graph connected, hence we'll return -1. else we'll return
 * required edge count.
 * 
 * Here we are doing simple Dfs so the time and space complexity will be O(n+e).
 * /////////////////////////////////////////////////////////////////////
 */
class ConnectGraph {
    int removableEdges = 0;

    public int makeConnected(int n, int[][] connections) {
        boolean visited[] = new boolean[n];
        int components = 0;

        ArrayList<ArrayList<Integer>> adj = findAdjList(n, connections);
        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                components++;
                countRemovableEdges(i, -1, adj, visited);
            }
        }

        // 1 edge is required to connect two components
        int requiredEdges = components - 1;

        // each edge will get counted twice
        removableEdges = removableEdges / 2;

        if (requiredEdges > removableEdges)
            return -1;
        else
            return requiredEdges;
    }

    void countRemovableEdges(int node, int prev, ArrayList<ArrayList<Integer>> adj, boolean visited[]) {
        // node is already visited through some other path, current edge can be removed
        if (visited[node] == true) {
            removableEdges++;
            return;
        }
        visited[node] = true;
        for (int n : adj.get(node)) {
            if (n != prev)
                countRemovableEdges(n, node, adj, visited);
        }
    }

    // Function to create the Adjacency List
    ArrayList<ArrayList<Integer>> findAdjList(int n, int connections[][]) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(n);

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<Integer>());

        for (int i = 0; i < connections.length; i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        return adj;
    }
}