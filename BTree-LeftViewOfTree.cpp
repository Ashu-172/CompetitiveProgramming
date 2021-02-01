/*///////////////////// Q 170: Babbar450: Left View of Binary Tree ///////////////////
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /  \      /  \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
///////////////////////////////////////////////////////////////////////////////////*/
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

//////////////////////// Solution 1 : Recursive ////////////////////
/*
The problem can also be solved using simple recursive traversal. We can keep track of the level of a node by passing a parameter to all recursive calls. The idea is to keep track of the maximum level also. Whenever we see a node whose level is more than maximum level so far, we print the node because this is the first node in its level (Note that we traverse the left subtree before right subtree). 
*/
void generateLeftView(Node *root, vector<int> &result, int level, int &maxLevel)
{
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        result.push_back(root->data);
        maxLevel = level;
    }
    generateLeftView(root->left, result, level + 1, maxLevel);
    generateLeftView(root->right, result, level + 1, maxLevel);
}

vector<int> leftView(Node *root)
{
    vector<int> result;
    Node *itr = root;
    int maxLevel = 0;
    if (itr != NULL)
        generateLeftView(itr, result, 1, maxLevel);
    return result;
}

/////////////////////////// Solution 2 (Level Order Traversal) ////////////////////
/*
we will do a level order traversal on the tree and print the leftmost node at every level. We’ll push the childs as we do in level order traversal. While popping we’ll pop using an inner loop so that we can keep track of first node in each level. Only for index 0 we’ll push the node in result vector.
*/
vector<int> getLeftView(Node *root)
{
    queue<Node *> q;
    vector<int> result;
    if (root == NULL)
        return result;

    q.push(root);
    while (q.empty() != true)
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
                result.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return result;
}

int main()
{
    Node *root = buildTree();
    vector<int> res = leftView(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    inOrder(root);
    return 0;
}