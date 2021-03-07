/*///////////////////// Q 206: Babbar450: Convert BST to Balanced BST ///////////////////
Given a BST (Binary Search Tree) that may be unbalanced, convert it into a balanced BST that has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30


Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

Input:
          4
        /   \
       3     5
      /       \
     2         6 
    /           \
   1             7
Output:
       4
    /    \
   2      6
 /  \    /  \
1    3  5    7 
//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>

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
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
////////////////////////////////////// Solution //////////////////////////////////
/*
1. Traverse given BST in inorder and store result in an array. This step takes O(n) time. Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
2. Build a balanced BST from the above created sorted array using the Following approach recursively
    1) Get the Middle of the array and make it root.
    2) Recursively do same for left half and right half.
      a) Get the middle of left half and make it left child of the root
          created in step 1.
      b) Get the middle of right half and make it right child of the
          root created in step 1.
*/

void getInorder(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    getInorder(root->left, result);
    result.push_back(root->data);
    getInorder(root->right, result);
}
Node *createBST(vector<int> inorder, int start, int end)
{
    Node *temp = NULL;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        temp = new Node(inorder[mid]);
        temp->left = createBST(inorder, start, mid - 1);
        temp->right = createBST(inorder, mid + 1, end);
    }
    return temp;
}
Node *balanceBST(Node *root)
{
    vector<int> inorder;
    getInorder(root, inorder);
    int size = inorder.size();
    Node *result = createBST(inorder, 0, size - 1);
    return result;
}

int main()
{
    Node *root = buildTree();
    preorder(root);
    cout << endl;
    root = balanceBST(root);
    inOrder(root);
    cout << endl;
    preorder(root);
    return 0;
}
