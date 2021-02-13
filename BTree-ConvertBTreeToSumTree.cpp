/*///////////////////// Q 180: Babbar450: BTree To Sum Tree ///////////////////
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0

Explanation:

           (4-2+12+6)
          /           \
      (8-4)          (7+5)
       /   \         /  \
      0     0       0    0
 

Your Task:  
You dont need to read input or print anything. Complete the function toSumTree() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 104
///////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>

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
///////////////////////////////////////////// Solution /////////////////////////////////////////
/*
we can calculate the value for the root node, by adding values of left child and right child 
before and after converting to sum tree.
this sum will be the value of root and also will be returned to parent.
Time complexity for this solution is O(n).
*/
int getSumTree(Node *root)
{
    int sum = 0;
    if (root->left == NULL && root->right == NULL)
    {
        root->data = 0;
        return 0;
    }

    if (root->left != NULL)
    {
        sum += root->left->data;
        sum += getSumTree(root->left);
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
        sum += getSumTree(root->right);
    }
    root->data = sum;
    return sum;
}

////////////////////////////////// Solution 2 (Better solution) ///////////////////////////
int toSumTree(Node *root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Store the old value
    int old_val = root->data;

    // Recursively call for left and
    // right subtrees and store the sum as
    // new value of this node
    root->data = toSumTree(root->left) + toSumTree(root->right);

    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return root->data + old_val;
}

int main()
{
    Node *root = buildTree();

    if (root != NULL)
        getSumTree(root);

    return 0;
}