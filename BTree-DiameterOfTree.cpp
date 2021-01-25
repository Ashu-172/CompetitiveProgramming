/*///////////////////// Q 165: Babbar450: Diameter of Binary Tree ///////////////////
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
/////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL, *right = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

void inOrder(Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";

    inOrder(node->right);
}

// Function to Build Tree
Node *buildTree()
{
    int size;
    cin >> size;
    string data;
    cin >> data;
    Node *root = new Node(stoi(data));
    size--;

    queue<Node *> q;
    q.push(root);

    while (size > 0)
    {
        Node *temp;
        if (q.empty() != true)
        {
            temp = q.front();
            q.pop();
        }
        else
        {
            break;
        }
        cin >> data;
        if (data != "N")
        {
            Node *node = new Node(stoi(data));
            temp->left = node;
            size--;
            q.push(node);
        }

        if (size > 0)
        {
            cin >> data;
            if (data != "N")
            {
                Node *node = new Node(stoi(data));
                temp->right = node;
                size--;
                q.push(node);
            }
        }
    }
    return root;
}

int height(struct Node *root)
{
    int left = 0, right = 0;
    if (root == NULL)
        return 0;

    left = height(root->left);
    right = height(root->right);

    return max(left, right) + 1;
}
/*///////////////////////////// Solution 1 ///////////////////////////////
-> calculate the height of left sub tree
-> calculate the height of right sub tree
-> diameter can be any value among following 3 for the current node
        -> distance from root to farest leaf node in left sub tree (dist+left)
        -> distance from root to farest leaf node in right sub tree (dist+rifht)
        -> distance from farest leaf node in left sub tree to farest leaf node in right sub tree (left+right+1)
-> calculate max of above tree values
-> Now it is possible that left sub tree or right sub tree has the max diameter, so we need to find the max of dia of left sub tree, right sub tree and dia for current node(calculated in above step).

*/
int diaUtil(int dist, Node *root)
{
    if (root == NULL)
        return 0;
    int left = 0, right = 0;
    left = height(root->left);
    right = height(root->right);
    int maxSoFar = max(max(dist + left, dist + right), left + right + 1);

    return max(maxSoFar, max(diaUtil(dist + 1, root->left), diaUtil(dist + 1, root->right)));
}

int diameter(Node *root)
{
    return diaUtil(1, root);
}

int main()
{
    Node *root = buildTree();
    cout << height(root) << endl;
    return 0;
}
//////////////////////////// Solution 2 //////////////////////////////////
/*
if in the tree each node have info about its parent node also, then we can 
find the diameter in two steps
1. find the farest node from root.
2. for the node found in prev step, again find the farest node
////////////////////////////////////////////////////////////////////////*/