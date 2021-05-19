/*//////////////////////////////// Q 326: Babbar450: convert BST to Min Heap ////////////////////////////////////
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Min Heap. 

Examples: 
 

Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a Min Heap.
All the nodes in the Min Heap satisfies the given condition, that is, values in the left subtree of
a node should be less than the values in the right subtree of the node. 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int num)
    {
        this->data = num;
        this->left = this->right = NULL;
    }
};
////////////////////////////////////////////////////// Solution ///////////////////////////////////////////////////
/*
Example:
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

    If we see the above example, as we already know inorder traversal of the BST is always sorted. when we convert the BST to min Heap with condition where nodes in left subtree will be smaller than the right sub tree, the resulting tree will be in the state where preorder order traversal of this tree will be in sorted order.

    SO the idea here is to convert the tree in such a way that the preorder of the tree will be in sorted order. To do this we can do an inorder traversal of the input tree and store the values in an array. then we can do a preorder traversal and put the values in the tree from the array by replacing the older values. Here we are directly replacing old values with the new values from the array, links of the tree will remain same.

    Algorithm:
    1. Create an array arr[] of size n, where n is the number of nodes in the given BST.
    2. Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
    3. Now perform the preorder traversal of the tree.
    4. While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes.


    Time Complexity: O(n) 
    Auxiliary Space: O(n) 
*/
void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void makeMinHeapPreOrder(Node *root, vector<int> inorderArr, int &index)
{
    if (root == NULL)
        return;

    root->data = inorderArr[index++];
    makeMinHeapPreOrder(root->left, inorderArr, index);
    makeMinHeapPreOrder(root->right, inorderArr, index);
}

void convertBstToMinHeap(Node *root)
{
    vector<int> inorderArr;
    inorderTraversal(root, inorderArr);

    // Here the inorderArr is following the minHeap property, for printing we can directly use this. if we want to convert the tree itself in the minHeap than we need to do a preorder traversal and put the values from the array in to the tree (changing old values with the new values, links will remain as it is)
    int index = 0;
    makeMinHeapPreOrder(root, inorderArr, index);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

////////////////////////////////////////////////// Solution 2 ///////////////////////////////////////////////
/*
We can modify the minHeapify method for the tree structure and convert the BST to min Heap without using additional space.
time complexity for this solution will be O(n log n) order ( or O(n) as we get for array when process fron n/2 th node) and space complexity will be O(1).
*/
void minHeapify(Node *root)
{
    if (root == NULL)
        return;

    Node *l = root->left;
    Node *r = root->right;
    Node *min = root;

    if (l != NULL && l->data < min->data)
        min = l;
    if (r != NULL && r->data < min->data)
        min = r;

    if (min != root)
    {
        int temp = root->data;
        root->data = min->data;
        min->data = temp;
    }

    if (l != NULL && r != NULL && l->data > r->data)
    {
        int temp = l->data;
        l->data = r->data;
        r->data = temp;

        // l and r both changed, need to heapify both
        minHeapify(l);
        minHeapify(r);
    }
    else if (min != root)
    {
        // only l or r changed (pointed by min), so heapify min
        minHeapify(min);
    }
}

void convertToMinHeap(Node *root)
{
    if (root == NULL)
        return;

    convertToMinHeap(root->right);
    convertToMinHeap(root->left);
    minHeapify(root);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    preorderTraversal(root);
    cout << endl;
    //convertBstToMinHeap(root);
    convertToMinHeap(root);
    preorderTraversal(root);
}