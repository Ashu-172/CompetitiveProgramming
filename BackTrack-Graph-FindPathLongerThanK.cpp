/*////////////////////////////////// Q 269: Babbar450: Find Largest Numbe in K Swaps ///////////////////////////////////
Given a graph, a source vertex in the graph and a number k, find if there is a simple path (without any cycle) starting from given source and ending at any other vertex such that the distance from source to that vertex is atleast ‘k’ length.
 
Example:
Input  : Source s = 0, k = 58
Output : True
There exists a simple path 0 -> 7 -> 1 -> 2 -> 8 -> 6 -> 5 -> 3 -> 4
Which has a total distance of 60 km which is more than 58.

Input  : Source s = 0, k = 62
Output : False

In the above graph, the longest simple
path has distance 61 (0 -> 7 -> 1-> 2 -> 3 -> 4 -> 5-> 6 -> 8, so output 
should be false for any input greater than 61.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;

class graph
{
private:
    int size;
    vector<pair<int, int>> *edges;

public:
    graph(int v)
    {
        size = v;
        edges = new vector<pair<int, int>>[size];
    }

    bool addEdge(int u, int v, int w)
    {
        if (u < size && v < size)
        {
            edges[u].push_back(make_pair(v, w));
            edges[v].push_back(make_pair(u, w));
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////// Solution /////////////////////////////////////////////////////////
    /*
To find the path with length k we need to traverse all the paths until we find a path of length greater or equal to k, for this we need to use back tracking.

Algorithm:
1. mark the starting node as visited and set the length of path to 0, since we are at starting node. now call the find path function.
2. for every edge from the current node do following
    a. if the next node is already visited then skip the current edge
    b. if the next node is not visited then mark it as visited and push it in the path.
    c. call the findpath method for this edge  recursively with increased path length, if function returns true then return true from here else back track by undoing the changes.
3. The base condition is when the length of the path is greater or equal to k.

Time complexity : in worst case each node will have an edge with every other node, means there will be n*n edges. in that case from first node we'll have n-1 options to move further, and from the next node we'll have n-2 options since we have marked previously visited nodes and so on. in this way the time complexity will be O(!n)

Space complexity will be O(n).

*/
    bool findPath(vector<int> &result, vector<int> &visited, int node, int k, int len)
    {
        if (len >= k)
            return true;

        for (pair<int, int> edge : edges[node])
        {
            if (visited[edge.first] == 0)
            {
                visited[edge.first] = 1;
                result.push_back(edge.first);
                if (true == findPath(result, visited, edge.first, k, len + edge.second))
                    return true;

                //BackTracking
                visited[edge.first] = 0;
                result.pop_back();
            }
        }
        return false;
    }

    vector<int> findPathLongerThanK(int start, int k)
    {
        vector<int> visited(size, 0);
        vector<int> path;
        int len = 0;

        visited[start] = 1;
        path.push_back(start);
        cout << findPath(path, visited, start, k, len) << endl;
        return path;
    }
};

int main()
{
    graph g(9); // total nodes are 9
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int start = 0;
    int k = 61;

    vector<int> path = g.findPathLongerThanK(start, k);
    for (int node : path)
        cout << node << " -> ";
    cout << "end" << endl;
}