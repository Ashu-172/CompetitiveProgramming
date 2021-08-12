
/*///////////////////// Q 343: Babbar450: Minimum Time Taken By Job ///////////////////////
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

input: n=7, e=7
        {(1,2), (2,3), (2,4), (2,5), (3,6), (4,6), (5,7)}

Output: 1 2 3 3 3 4 4  
Explanation:
Start the Job 1 at the beginning and complete it at 1st unit of time.
The job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on 2nd Job. So, start these jobs at 2nd unit of time and complete these at 3rd unit of time.
The Job 6 can only be done after the 3rd and 4th Job is done. So, start it at 3rd unit of time and complete it at 4th unit of time.
The Job 7 can only be done after the 5th Job is done. So, start it at 3rd hour and complete it at 4th unit of time.
/////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph_MinimumTimeByJob {
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

        int levels[] = new int[nov];
        // for (int i = 0; i < nov; i++)
        // levels[i] = Integer.MAX_VALUE;

        // solution 1
        for (int i = 0; i < nov; i++) {
            if (levels[i] == 0)
                findMinTime(1, i + 1, levels, list);
        }

        // solution 2
        int timer[] = findMinTimeTopoSort(nov, list);

        for (int time : levels)
            System.out.print(time + " ");

        System.out.println();
        for (int time : timer)
            System.out.print(time + " ");

    }

    /*
     * In this problem we need to find the starting time for each job, here edge
     * (u,v) means job v will run after job u. so technically we need to find the
     * level at which the node is present in a dfs traversal tree. here same node
     * can be visited through multiple ways which means the number of nodes in it's
     * path can be different different. since a job should run after all the jobs
     * which are having it as an adjacent node, the maximum value of the length of
     * the path (or level) to reach the node will be considered the correct time
     * when the job can be started because by this time all the jobs which comes
     * before it would have got executed no matter on which path it is present.
     * 
     * so we can do a dfs and find the maximum level at which the node can come
     * (without revisiting a node in a cycle).
     * 
     * Algorithm: 1. initialize the level array with 0, and current level as 1.
     * 
     * 2. for node which has level 0, call dfs based function findMinTime.
     * 
     * ->a. set current level as the level of the current node.
     * 
     * ->b. for all the adjacent nodes, call the function with incremented value of
     * current level.
     * 
     * ->c. The base condition is when the level is already calculated for a node
     * and its value is greter than the current level whih means it has the max
     * possible level value, which is what we are searching for.
     * 
     * Time complexity for this solution is O(N+E) for simple Dfs and space
     * complexity is also O(N+E)
     * 
     * 
     * Note: Another solution using toposort :
     * https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-
     * given-by-a-directed-acyclic-graph/
     */
    static void findMinTime(int currLevel, int node, int levels[], ArrayList<ArrayList<Integer>> adj) {
        if (levels[node - 1] > currLevel) // current level for node is lesser then no need to go further
            return;

        levels[node - 1] = currLevel;

        for (int v : adj.get(node)) {
            findMinTime(currLevel + 1, v, levels, adj);
        }
    }

    //////////////////// Solution 2 (Topo Sort) //////////////////////
    /*
     * Approach: The job can be started only if all the jobs that are prerequisites
     * of the job that are done. Therefore, the idea is to use Topological Sort for
     * the given network. Below are the steps:
     * 
     * 1. Finish the jobs that are not dependent on any other job.
     * 
     * 2. Create an array inDegree[] to store the count of the dependent node for
     * each node in the given network.
     * 
     * 3. Initialize a queue and push all the vertex whose inDegree[] is 0. 4.
     * Initialize the timer to 1 and store the current queue size(say size) and do
     * the following:
     * 
     * -- a. Pop the node from the queue until the size is 0.
     * 
     * -- b. While popping the node(say node U) from the queue decrement the
     * inDegree of every node connected to it.
     * 
     * -- c. If inDegree of any adjacent node is 0 in the above step then insert
     * that node in the queue. also set the value of timer for this node by
     * incrementing the timer of previous node (node removed from queue). This will
     * ensure that in the end the timer value for node will be the minimum time when
     * it can start after all its preceding jobs gets finished.
     * 
     * -- d. Increment the timer after all the above steps.
     * 
     * 4. Print the finishing time of all the nodes after we traverse every node in
     * the above step.
     */
    static int[] findMinTimeTopoSort(int n, ArrayList<ArrayList<Integer>> adjList) {
        int time[] = new int[n];
        int indegree[] = new int[n];
        for (int i = 0; i < n; i++) {
            for (int node : adjList.get(i)) {
                indegree[node - 1]++;
            }
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                time[i] = 1;
                q.add(i + 1);
            }
        }

        while (q.isEmpty() != true) {
            int node = q.poll();
            for (int adj : adjList.get(node)) {
                indegree[adj - 1]--;
                if (indegree[adj - 1] == 0) { // always in a toposort order
                    time[adj - 1] = time[node - 1] + 1;
                    q.add(adj);
                }
            }
        }
        return time;
    }
}
