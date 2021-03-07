/*///////////////////// Q 204, 215: Babbar450: Construct BST from Preorder Traversal, preorderTo PostOrder ///////////////////
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be the root of the following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

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
void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
//////////////////////////////////// Solution 1 //////////////////////////////////////////
/*
in the array, first node is the root node, we'll create the root node.
1. in the array search for the element which is bigger than root, 
        a) nodes from root(excluding) to that next bigger element(excluding) will be the nodes in left sub tree
        b) nodes from next bigger element(including) to end of the array will be the nodes in the right sub tree
*/
Node *constructBST(int preorder[], int start, int end)
{
    if (start <= end)
    {
        Node *root = new Node(preorder[start]);

        // find next large value
        int i = start + 1;
        while (i <= end)
        {
            if (preorder[i] > root->data)
                break;
            i++;
        }
        root->left = constructBST(preorder, start + 1, i - 1);
        root->right = constructBST(preorder, i, end);
        return root;
    }
    return NULL;
}

////////////////////////////////////// Solution 2 (Using BST property) ////////////////////////
/*
1. first node is the root node of the tree so we'll create the root node.
2. for remaining elements in the arrar, we'll call insert function and insert the nodes based on the BST property.

Time Complexity = O(n^2)
*/
void insertNode(Node *&root, int num)
{
    if (root == NULL)
        root = new Node(num);
    else if (root->data > num)
        insertNode(root->left, num);
    else
        insertNode(root->right, num);
}

Node *createBST(int arr[], int size)
{
    Node *root = new Node(arr[0]);
    for (int i = 1; i < size; i++)
    {
        insertNode(root, arr[i]);
    }
    return root;
}
//////////////////////////////////////////// Solution 3 ///////////////////////////////////////
/*
we can create the BST in O(n) order. we can use ranges for that.
1. the first element i.e. root will be in the range INT_MIN and INT_MAX, so we'll create a new node with this data.
2. increment the index, and call the function for ranges INT_MIN to element-1 and element +1 to INT_MAX for left and right child. the idea here is nodes present in left sub tree will be less than the current node so the range will be INT_MIN to data-1 and similarly nodes present in right nodes will be larger than current node so the range will be data+1 to INT_MAX.
3. if data is not in the range, return NULL without modifying index, because that node is larger and belongs to some other sub tree (right or parent's right).
*/
Node *constructBSTLinear(int preorder[], int &index, int size, int lLimit, int hLimit)
{
    Node *temp = NULL;
    if (index < size)
    {
        if (preorder[index] >= lLimit && preorder[index] <= hLimit)
        {
            temp = new Node(preorder[index]);
            index++;
            temp->left = constructBSTLinear(preorder, index, size, lLimit, temp->data - 1);
            temp->right = constructBSTLinear(preorder, index, size, temp->data + 1, hLimit);
        }
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    int preorder[n];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    Node *root = constructBST(preorder, 0, n - 1);

    Node *root1 = createBST(preorder, n);
    int index = 0;
    Node *root2 = constructBSTLinear(preorder, index, n, INT_MIN, INT_MAX);

    inOrder(root);
    cout << endl;
    inOrder(root1);
    cout << endl;
    inOrder(root2);
    // Post order
    cout << endl;
    postOrder(root2);
    return 0;
}