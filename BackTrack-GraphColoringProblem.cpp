/*////////////////////////////////// Q 260: Babbar450: Graph Colouring Problem ///////////////////////////////////
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(1,2),(2,3),(3,4),(4,1),(1,3)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(1,2),(2,3),(1,3)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
Note: In the given 2d-array graph[], if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 20
1 <= E <= (N*(N-1))/2
1 <= M <= N

Note: The given inputs are 1-base indexed but you have to consider the graph given in the adjacency matrix/list as 0-base indexed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cstring>

using namespace std;

/*
In this problem we have n colors available for any node,  the idea here is to try out all the colors on the current node and recursively find next node which is not yet colored and fill it. on every function call one not will get filled, so whenever we fill the color in any node, we need to check if the current color is safe to fill in current node. if the color is not matched with the color of any of the directly linked node then it is consodered safe.

Algorithm:
1.  Find the node in the graph for which color is not yet filled.
2.  For every color do following
    a.  check if the color is safe to fill in the current node. if it is not safe then try out next color.
    b.  if the color is safe then mark the current node as colored in the coloredNodes array.
    c.  call the FillColor method recursively to fill color in remaining nodes of the graph.
    d.  return true if the FillColor method return true, which indicates that the color is filled in all the nodes in the graph.
    e.  if it returns false then discard the currently filled color from the current node and backtrack 
        (it means that the color we filled in current node is not leading to a solution, some node in the recursive calls couldn't get filled with color. so here we need to backtrack and try out some other color for the current node).
3.  Return false if non of the color is safe to fill in the current node.
4.  The base condition is when there is no more uncolored nodes left in the graph, here we return true since we have colored all the nodes of the graph.

Complexity Analysis:
Since we have M colors to try for each node and at every level of the recursion we are coloring one node and ther are N nodes in the graph. the time complexity for this solution will be O(M^N)
Space complexity for this solution is O(N) since we are storing info of the colored nodes in an array of size N.
*/
bool findNextUncoleredNode(bool graph[101][101], int cNodes[101], int n, int &node)
{
    for (int i = node; i < n; i++)
    {
        if (cNodes[i] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == 1)
                {
                    node = i;
                    return true;
                }
            }
        }
    }
    return false;
}

bool isSafe(bool graph[101][101], int n, int node, int color, int cNodes[101])
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] != 0)
        {
            if (cNodes[i] == color)
                return false;
        }
    }
    return true;
}

bool fillColors(bool graph[101][101], int colors, int n, int cNodes[101], int node)
{
    if (findNextUncoleredNode(graph, cNodes, n, node) == false)
        return true;

    for (int c = 1; c <= colors; c++) // colors
    {
        if (isSafe(graph, n, node, c, cNodes) == true)
        {
            cNodes[node] = c;
            if (fillColors(graph, colors, n, cNodes, node + 1) == true)
                return true;
            cNodes[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int cNodes[101] = {0};
    return fillColors(graph, m, n, cNodes, 0);
}
int main()
{

    int n, m, e;
    cin >> n >> m >> e;
    int i;
    bool graph[101][101];
    for (i = 0; i < n; i++)
    {
        memset(graph[i], 0, sizeof(graph[i]));
    }
    for (i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    cout << graphColoring(graph, m, n) << endl;
    return 0;
}