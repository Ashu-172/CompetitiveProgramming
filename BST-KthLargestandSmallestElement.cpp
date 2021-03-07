/*///////////////////// Q 208, 209: Babbar450: Find Kth Largest and Kth Smallest Element in BST ///////////////////
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 1000
1 <= K <= N
///////////////////////////////////////////////////////////////////////////////////////////*/
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
/////////////////////////////////// Solution ////////////////////////////////////
/* 
we can use inorder traversal to find out Kth largest and smallest element
1. for Kth largest element we'll do inorder traversal in reverse order, and increase the count, when count will become equal to K, we'll set the result and return so that remaining tree will not be traversed.
2. for Kth smallest element we'll use inorder traversal and increase the count, when count will become equal to K, we'll set the result and return so that remaining tree will not be traversed.
*/
void inorderLargest(Node *root, int &count, int k, int &result)
{
    if (root == NULL)
        return;

    inorderLargest(root->right, count, k, result);
    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }
    inorderLargest(root->left, count, k, result);
}

void inorderSmallest(Node *root, int &count, int k, int &result)
{
    if (root == NULL)
        return;

    inorderSmallest(root->left, count, k, result);
    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }
    inorderSmallest(root->right, count, k, result);
}

int main()
{
    Node *root = buildTree();
    int k;
    cin >> k;
    int largest = -1, smallest = -1, count = 0;
    inorderLargest(root, count, k, largest);
    count = 0;
    inorderSmallest(root, count, k, smallest);
    cout << largest << " " << smallest << endl;
    return 0;
}