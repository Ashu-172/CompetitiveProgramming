/*///////////////////// Q 205: Babbar450: Convert Binary Tree to BST ///////////////////
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>
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

//////////////////////////////////////// Solution ////////////////////////////////////////
/*
1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
2) Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. In the following implementation, Quick Sort is used which takes (n^2) time. This can be done in O(nLogn) time using Heap Sort or Merge Sort.
3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step takes O(n) time.
*/
void getInorder(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}

void getBST(Node *root, vector<int> inorder, int &index)
{
    if (root == NULL)
        return;
    getBST(root->left, inorder, index);
    root->data = inorder[index++];
    getBST(root->right, inorder, index);
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> inorderArr;
    getInorder(root, inorderArr);
    sort(inorderArr.begin(), inorderArr.end());
    int index = 0;
    getBST(root, inorderArr, index);
    return root;
}

int main()
{
    Node *root = buildTree();
    root = binaryTreeToBST(root);
    inOrder(root);
    return 0;
}