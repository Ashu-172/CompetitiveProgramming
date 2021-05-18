/*//////////////////////////////// Q 324: Babbar450: Check if a Binary Tree is Heap ////////////////////////////////////
Given a binary tree you need to check if it follows max heap property or not.

Output:
The function should return true if property holds else false.
 

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0
Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

//////////////////////////////////////////////////// Solution /////////////////////////////////////////////////
/*
for a binary tree to be a heap, following conditions should met
    1. tree should be a complete Binary tree.
    2. parent value should be greater than the children.
    3. both the children should also be a binary heap.

we can check above conditions recursively to validate binary heap.
*/

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    bool isHeap(struct Node *root)
    {
        if (root == NULL)
            return true;
        // tree should be complete binary tree
        if (root->left == NULL)
        {
            if (root->right == NULL)
                return true;
            else
                return false;
        }

        if (root->left != NULL && root->data < root->left->data)
            return false;
        if (root->right != NULL && root->data < root->right->data)
            return false;

        // recursively checking heap properties for left and right child
        return isHeap(root->left) && isHeap(root->right);
    }
};

int main()
{

    string treeString;
    getline(cin, treeString);
    Solution ob;
    Node *root = buildTree(treeString);
    if (ob.isHeap(root))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}