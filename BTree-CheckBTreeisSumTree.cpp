/*///////////////////// Q 183: Babbar450: Check if BTree is a Sum Tree ///////////////////
Given a Binary Tree. Check whether it is a Sum Tree or not.

A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree . An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. A leaf node is also considered as a Sum Tree.

Example 1:
Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum
tree. For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)

Constraints:
1 ≤ number of nodes ≤ 10^4

////////////////////////////////////////////////////////////////////////////////////////*/
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
///////////////////////////////////// Solution ////////////////////////////////////
int getSum(Node *root, bool &flag)
{
    if (root == NULL)
    {
        flag = true;
        return 0;
    }

    int left = 0;
    int right = 0;

    bool lFlag = true;
    bool rFlag = true;

    left = getSum(root->left, lFlag);
    right = getSum(root->right, rFlag);

    // if left or right sub tree is not a SUM tree, return false
    if (rFlag != true || lFlag != true)
    {
        flag = false;
        return root->data;
    }
    // if root is a leaf node, return true and its data
    if (left == 0 && right == 0)
    {
        flag = true;
        return root->data;
    }
    // if sum of left and right sub tree is not equal to root, return false
    if ((left + right) != root->data)
    {
        flag = false;
        return root->data;
    }
    // return sum of left sub tree, right sub tree and the root data
    flag = true;
    return root->data + left + right;
}

bool isSumTree(Node *root)
{
    bool flag;
    getSum(root, flag);

    return flag;
}

int main()
{
    Node *root = buildTree();

    cout << isSumTree(root);

    return 0;
}