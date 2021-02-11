/*///////////////////// Q 177: Babbar450: Boundary Traversal of binary tree ///////////////////
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^5
//////////////////////////////////////////////////////////////////////////////////////*/
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

////////////////////////////////////////////// Solution ///////////////////////////////////////////
/*
We break the problem in 3 parts:
1. Print the left boundary in top-down manner. (Note that it is  not the left view, it is path to left most leaf)
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
    2.1 Print all leaf nodes of left sub-tree from left to right.
    2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner. (Note that it is  not the right view, it is the path to right most leaf)

We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.
*/
void printLeftBoundry(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        result.push_back(root->data);
        printLeftBoundry(root->left, result);
    }
    else if (root->right != NULL)
    {
        result.push_back(root->data);
        printLeftBoundry(root->right, result);
    }
    // don't do anything for else, which is for leaf node
}

void printRightBoundry(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    if (root->right != NULL)
    { // push elements in bottom-up manner
        printRightBoundry(root->right, result);
        result.push_back(root->data);
    }
    else if (root->left != NULL)
    {
        printRightBoundry(root->left, result);
        result.push_back(root->data);
    }
    // don't do anything for else, which is for leaf node
}

void printLeafNodes(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    if ((root->left == NULL) && (root->right == NULL))
    {
        result.push_back(root->data);
        return;
    }
    printLeafNodes(root->left, result);
    printLeafNodes(root->right, result);
}

vector<int> printBoundary(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    result.push_back(root->data);
    printLeftBoundry(root->left, result);
    printLeafNodes(root->left, result);
    printLeafNodes(root->right, result);
    printRightBoundry(root->right, result);
    return result;
}
int main()
{
    Node *root = buildTree();
    vector<int> result = printBoundary(root);

    for (int num : result)
        cout << num << " ";
    return 0;
}