/*///////////////////// Q 338: Babbar450: Clone a Graph ///////////////////////
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

Example:

Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
///////////////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

////////////////////////////////// Algorithm ////////////////////
/**
 * 1. Create a copy of the first node and add it in the map, which is defined to
 * track all the discovered nodes.
 * 
 * 2. Call the createGraph function with original and cloned copy of first node.
 * 
 * 3.1 By iterating over the oldNode's adjacency list create copies of all the
 * adjacent nodes and put in the adjacency list of new node. if the node is
 * already descovered then take it from the map else create a fresh copy of it
 * and then put it in the newNode's adjacency list.
 * 
 * 3.2 Since we have discovered all the adjacent nodes of the current new node,
 * now we have to repeat the same thing for all those nodes so that they'll have
 * their adjacency lists with them. for it we'll use another loop and call the
 * same function for all those nodes present in ond and new node's adjacency
 * list.
 * 
 * 3.3 the Base condition is when the new node already has its adjacency list
 * filled, in this case we don't need to fill it again, so we can return.
 * 
 * Time Complexity = O(n) + O(n*n) because first loop is running maximum n times
 * andsecond loop is running maximum n times and there will be n level of
 * recursion in the dfs. Space Complexity = O(n) for hashmap and O(n) for
 * recursion stack
 */
public class Graph_CloneGraph {
    static HashMap<Integer, Node> nodesFound = new HashMap<Integer, Node>();

    public static Node cloneGraph(Node node) {
        if (node == null)
            return null;
        Node newNode = new Node(node.val);
        nodesFound.put(node.val, newNode);

        createGraph(newNode, node);
        return newNode;
    }

    static void createGraph(Node newNode, Node oldNode) {
        if (newNode.neighbors.size() != 0)
            return;

        for (int i = 0; i < oldNode.neighbors.size(); i++) {
            int val = oldNode.neighbors.get(i).val;
            Node duplicate;
            if (nodesFound.containsKey(val) == false) {
                duplicate = new Node(val);
                nodesFound.put(val, duplicate);
            } else {
                duplicate = nodesFound.get(val);
            }
            newNode.neighbors.add(duplicate);

        }

        for (int i = 0; i < newNode.neighbors.size(); i++) {
            createGraph(newNode.neighbors.get(i), oldNode.neighbors.get(i));
        }
    }

    public static void bfs(Node source) {
        Queue<Node> q = new LinkedList<Node>();
        q.add(source);
        HashMap<Node, Boolean> visit = new HashMap<Node, Boolean>();
        visit.put(source, true);
        while (!q.isEmpty()) {
            Node u = q.poll();
            System.out.println("Value of Node " + u.val);
            System.out.println("Address of Node " + u);
            if (u.neighbors != null) {
                List<Node> v = u.neighbors;
                for (Node g : v) {
                    if (visit.get(g) == null) {
                        q.add(g);
                        visit.put(g, true);
                    }
                }
            }
        }
        System.out.println();
    }

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
        ArrayList<Node> nodes = new ArrayList<Node>();
        for (int i = 0; i < n; i++) {
            Node node = new Node(i);
            nodes.add(node);
        }
        for (int i = 0; i < e; i++) {
            nodes.get(edges[i][0]).neighbors.add(nodes.get(edges[i][1]));
        }

        Node clone = cloneGraph(nodes.get(0));
        bfs(nodes.get(0));
        bfs(clone);
    }
}

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
