
/*///////////////////// Q 344: Babbar450:Finish All Tasks ///////////////////////
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Graph_FinishAllTasks {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n, e;
        String ne[] = reader.readLine().trim().split(" ");
        n = Integer.parseInt(ne[0]);
        e = Integer.parseInt(ne[1]);

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<Integer>());

        for (int i = 0; i < e; i++) {
            String edge[] = reader.readLine().trim().split(" ");
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);
            adj.get(u).add(v);
        }

        boolean result = allTaskFinishable(n, adj);
        System.out.println(result);
    }

    static boolean allTaskFinishable(int n, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[n];
        boolean visitStack[] = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                // visitStack[i] = true;
                if (true == detectCycleDfs(i, adj, visited, visitStack))
                    return false;
                // visitStack[i] = false;
            }
        }
        return true;
    }

    static boolean detectCycleDfs(int node, ArrayList<ArrayList<Integer>> adj, boolean visited[],
            boolean visitStack[]) {
        if (visitStack[node] == true)
            return true;

        if (visited[node] == true)
            return false;

        visitStack[node] = true;
        visited[node] = true;

        for (int n : adj.get(node)) {
            if (detectCycleDfs(n, adj, visited, visitStack) == true)
                return true;
        }
        visitStack[node] = false;
        return false;
    }
    // Note: Topo sort can also be used for cycle detection
}
