/*///////////////////// Q 164: Babbar450: Height of Binary Tree ///////////////////
Given a binary tree, find its height.â€‹

Example 1:

Input:
      1
    /  \
   2    3
Output: 2

Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which takes root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5
//////////////////////////////////////////////////////////////////////////////////////////////////*/
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
/*/////////////// Recursion /////////////
Base Condition:
    if root is NULL, height of that subtree will be 0.

-> calculate height of left and right subtrees.
-> find max of height of left and right subtrees.
-> add 1 to max height and return.
*/
int height(struct Node *root)
{
    int left = 0, right = 0;
    if (root == NULL)
        return 0;

    left = height(root->left);
    right = height(root->right);

    return max(left, right) + 1;
}

int main()
{
    Node *root = buildTree();
    cout << height(root) << endl;
    return 0;
}
