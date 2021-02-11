/*///////////////////// Q 176: Babbar450: Diagonal Traversal Of Tree ///////////////////
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
unnamed
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4
Your Task:
You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Here N is number of nodes.

Constraints:
1 <= Number of nodes<= 105
1 <= Data of a node<= 105
//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <deque>
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

///////////////////////////////////////// Solution ////////////////////////////////////
/*
we can observe some points from the tree.
1. from the root node if we traverse only right pointers we'll get the diagonal walk.
2. for next diagonal walk we need to capture all the nodes we've walked in previous walk 
    and push their left pointers to the queue. then we can pop elements from the queue 
    one by one and print them and their right childs.
3. repeating above two steps until all the nodes are traversed, will give the diagonal traversal result.
*/
vector<int> DiagonalTraversal(Node *root)
{
    queue<Node *> q;
    vector<int> result;
    q.push(root);

    while (q.empty() != true)
    {
        Node *temp;
        temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            result.push_back(temp->data);
            if (temp->left != NULL)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return result;
}
int main()
{
    Node *root = buildTree();
    vector<int> result = DiagonalTraversal(root);

    for (int num : result)
        cout << num << " ";
    return 0;
}
