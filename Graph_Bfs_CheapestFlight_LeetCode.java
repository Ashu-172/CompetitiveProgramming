
/*//////////////////////// Q Leetcode: Total Number of Spanning Tree //////////////////////////
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
/////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph_Bfs_CheapestFlight_LeetCode {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String st[] = read.readLine().trim().split(" ");
        int n = Integer.parseInt(st[0]);
        int edg = Integer.parseInt(st[1]);

        int flights[][] = new int[n][n];

        for (int i = 1; i <= edg; i++) {
            String s[] = read.readLine().trim().split(" ");
            flights[i][0] = Integer.parseInt(s[0]);
            flights[i][1] = Integer.parseInt(s[1]);
            flights[i][2] = Integer.parseInt(s[2]);
        }

        String s[] = read.readLine().trim().split(" ");
        int src = Integer.parseInt(s[0]);
        int dst = Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);

        FlightDistCalculate obj = new FlightDistCalculate();
        int dist = obj.findCheapestPrice(n, flights, src, dst, k);
        System.out.println("Minimum Distance from src to dst in k Steps: " + dist);
    }
}

class FlightDistCalculate {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<Edge>> adj = new ArrayList<ArrayList<Edge>>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Edge>());
        }
        for (int i = 0; i < flights.length; i++) {
            adj.get(flights[i][0]).add(new Edge(flights[i][1], flights[i][2]));
        }
        int dist[] = findShortestPath(n, adj, src, dst, k);
        return (dist[dst] == Integer.MAX_VALUE) ? -1 : dist[dst];

    }

    int[] findShortestPath(int n, ArrayList<ArrayList<Edge>> adj, int src, int dst, int k) {
        int distance[] = new int[n];
        for (int i = 0; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[src] = 0;
        Queue<Edge> q = new LinkedList<Edge>();
        q.add(new Edge(src, 0));
        int level = 0;
        while (q.isEmpty() != true) {
            int size = q.size();
            level++;
            if (level > k + 1)
                break;
            for (int i = 0; i < size; i++) {
                Edge p = q.remove();
                for (Edge e : adj.get(p.node)) {
                    int totalDist = p.dist + e.dist;
                    if (totalDist < distance[e.node]) {
                        q.add(new Edge(e.node, totalDist));
                        distance[e.node] = totalDist;
                    }
                }
            }
        }
        return distance;
    }
}