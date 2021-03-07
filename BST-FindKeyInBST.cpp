/*///////////////////// Q 197: Babbar450: Find and Insert Key in a BST ///////////////////
Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 
Note: If K is already present in the BST, don't modify the BST.


Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).


Constraints:
1 <= Number of nodes <= 105
1 <= K <= 106
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
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
/////////////////////////////// Solution /////////////////////////////////
/*
1. if root data is less than key then, key should be present in right sub-tree, so we'll check if right child is not null then call the function for right child else create a new node with given key and assign it to right child.

2. if root data is greater than key then key should be present in left sub-tree, so we'll check if left child is not null then call the function for left child else create a new node with given key and assign it to left child.

3. if key is matched with root, return the root without any change.
*/
Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        if (root->right == NULL)
            root->right = new Node(key);
        else
            insert(root->right, key);
    }
    else
    {
        if (root->left == NULL)
            root->left = new Node(key);
        else
            insert(root->left, key);
    }

    return root;
}
int main()
{
    Node *root = buildTree();

    int key;
    cin >> key;
    root = insert(root, key);
    inOrder(root);
    return 0;
}