/*///////////////////// Q 181: Babbar450: Construct BTree from preorder and inorder traversal ///////////////////
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:
Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000
//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n;
    cin >> n;

    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    Node *root = buildTree(inorder, preorder, n);
    printPostOrder(root);
    cout << endl;
}
///////////////////////////////////// Solution ///////////////////////////////////////////
/*
In a Preorder sequence, leftmost element is the root of the tree. So we know 'A' is root for given sequences. By searching ‘A’ in Inorder sequence, we can find out all elements on left side of 'A' are in left subtree and elements on right are in right subtree. So we know below structure now. 


                 A
               /  \
             /     \
          D B E   F C


We recursively follow above steps and get the following tree.


         A
       /   \
     /      \
    B        C
   / \      /
 /    \   /
D     E  F


Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call. 
2) Create a new tree node tNode with the data as picked element. 
3) Find the picked element's index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode. 
6) return tNode.
*/
int search(int num, int in[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == num)
            return i;
    }
    return -1;
}

Node *createTree(int in[], int pre[], int &index, int start, int end)
{
    if (start > end)
        return NULL;

    int loc = search(pre[index], in, start, end);

    Node *node = new Node(pre[index]);
    index++;
    node->left = createTree(in, pre, index, start, loc - 1);
    node->right = createTree(in, pre, index, loc + 1, end);
    return node;
}
Node *buildTree(int in[], int pre[], int n)
{
    if (n == 0)
        return NULL;
    int index = 0;
    return createTree(in, pre, index, 0, n - 1);
}