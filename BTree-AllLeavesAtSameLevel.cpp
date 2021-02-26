/*///////////////////// Q 184: Babbar450: Check if  All Leaves Present at Same Level ///////////////////
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 
Constraints:
1 ≤ N ≤ 10^3
//////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

//////////////////////////////////////// Solution /////////////////////////////////////////
/*
1. Calculate the max Level of the tree by traversing left most branch.
2. traverse  left and right sub trees and compare the level of leaf node with max level calculated in first step.
*/
int getMaxLevel(Node *root)
{
    Node *p = root;
    int height = 1;

    while (true)
    {
        if (p->left != NULL)
        {
            height++;
            p = p->left;
        }
        else if (p->right != NULL)
        {
            height++;
            p = p->right;
        }
        else
            break;
    }
    return height;
}
bool validateTree(Node *root, int max, int level)
{
    if (root->left == NULL && root->right == NULL)
    {
        if (level == max)
            return true;
        return false;
    }

    if (root->left != NULL)
        if (validateTree(root->left, max, level + 1) == false)
            return false;

    if (root->right != NULL)
        if (validateTree(root->right, max, level + 1) == false)
            return false;

    return true;
}

int main()
{
    Node *root = buildTree();

    int max = getMaxLevel(root);
    int level = 1;
    cout << validateTree(root, max, level);
    return 0;
}