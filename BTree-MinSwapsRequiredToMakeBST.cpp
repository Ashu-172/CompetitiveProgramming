/*///////////////////// Q 182: Babbar450: Count Minimum Swaps required for converting BTree to BST ///////////////////
Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Examples:  

Input : arr[] = { 5, 6, 7, 8, 9, 10, 11 }
Output : 3
Binary tree of the given array:
             5
          /    \
         6      7
       /   \   /  \  
     8     9  10   11

Swap 1: Swap node 8 with node 5.
Swap 2: Swap node 9 with node 10.
Swap 3: Swap node 10 with node 7.

             8
          /    \
         6      10
       /   \   /  \  
     5     7  9   11

So, minimum 3 swaps are required.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
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

//////////////////////////////////// Solution ////////////////////////////////////
/*
we can use the fact that inorder traversal of the binary search tree gives the 
values of the tree in accending sorted order.
so we can sort the inorder traversal of the binay tree, and count the number of swaps
required to convert the inorder traversal of Binary tree to sorted array.

1. create array A from inorder traversal of the binary tree.
2. sort this array A and store in another array B.
3. count the number of swaps required for converting array A to B.
*/

void inorder(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;

    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int search(vector<int> arr, int num, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            return search(arr, num, start, mid - 1);
        else
            return search(arr, num, mid + 1, end);
    }
    return -1;
}
int countSwaps(Node *root)
{
    vector<int> inorderBTree;
    inorder(root, inorderBTree);

    vector<int> inorderBST(inorderBTree);
    sort(inorderBST.begin(), inorderBST.end());
    int size = inorderBTree.size();
    int count = 0;
    for (int i = 0; i < size;)
    {
        if (inorderBTree[i] != inorderBST[i])
        {
            int loc = search(inorderBST, inorderBTree[i], 0, size - 1);
            swap(inorderBTree[i], inorderBTree[loc]);
            count++;
        }
        else
            i++;
    }
    return count;
}
/*
 Time complexity for this solution is as following
    inorder traversal   = O(N)
    copying array       = O(N)
    sorting array       = O(N log N)
    searching elements  = O(N * (log N))

    final Time Complexity = O(N log N)
*/
int main()
{
    Node *root = buildTree();

    cout << countSwaps(root);

    return 0;
}