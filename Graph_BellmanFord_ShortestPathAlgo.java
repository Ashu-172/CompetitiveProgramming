import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Graph_BellmanFord_ShortestPathAlgo {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] S1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(S1[0]);
            int m = Integer.parseInt(S1[1]);
            int[][] edges = new int[m][3];
            for (int i = 0; i < m; i++) {
                String S2[] = br.readLine().trim().split(" ");
                for (int j = 0; j < 3; j++)
                    edges[i][j] = Integer.parseInt(S2[j]);
            }
            int ans[] = shortestPathBellmanFord(n, edges);
            for (int dist : ans)
                System.out.println(dist);
        }
    }

    static int[] shortestPathBellmanFord(int n, int[][] edges) {
        int distance[] = new int[n];
        for (int i = 0; i < n; i++) {
            distance[i] = 100000000;
        }
        distance[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int[] edge : edges) {
                if (distance[edge[0]] + edge[2] < distance[edge[1]]) {
                    distance[edge[1]] = distance[edge[0]] + edge[2];
                }
            }
        }
        return distance;
    }
}
