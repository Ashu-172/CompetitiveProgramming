/*///////////////////// Q 162: Babbar450: Level Order Traversal In a Binary Tree ///////////////////
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes<= 10^4
1 <= Data of a node <= 10^4
//////////////////////////////////////////////////////////////////////////////////////////////////*/
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

vector<int> levelOrder(Node *node)
{
    queue<Node *> q;
    vector<int> result;
    if (node == NULL)
        return result;

    q.push(node);
    while (q.empty() != true)
    {
        Node *temp = q.front();
        q.pop();
        result.push_back(temp->data);
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return result;
}

int main()
{
    Node *root = buildTree();
    vector<int> res = levelOrder(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    inOrder(root);
    return 0;
}
