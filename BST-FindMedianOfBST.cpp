/*///////////////////// Q 211: Babbar450: Find Median Of BST ///////////////////
Given a Binary Search Tree, find median of it.

If no. of nodes are even: then median = ((n/2th node + (n+1)/2th node) /2
If no. of nodes are odd : then median = (n+1)/2th node.

For example, median of below BST is 12.


More Examples:

 Given BST(with odd no. of nodes) is : 
                    6
                 /    \
                3       8
              /   \    /  \
             1     4  7    9

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8, 9
So, here median will 6.

Given BST(with even no. of nodes) is :  
                    6
                 /    \
                3       8
              /   \    /  
             1     4  7    

Inorder of Given BST will be : 1, 3, 4, 6, 7, 8
So, here median will  (4+6)/2 = 5.
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
we can use inorder traversal to find out median value
1. calculate the size of the tree.
2. if size is even then find size/2 th element in the tree and size/2 + 1 th element in the tree and return their sum / 2 as median.
3. if size is odd then find  (size+1)/2 th element as median.
*/

void inorderSmallest(Node *root, int &k, int &result)
{
    if (root == NULL)
        return;

    inorderSmallest(root->left, k, result);
    k--;
    if (0 == k)
    {
        result = root->data;
        return;
    }
    inorderSmallest(root->right, k, result);
}
void getSize(Node *root, int &size)
{
    if (root == NULL)
        return;
    getSize(root->left, size);
    size++;
    getSize(root->right, size);
}
int main()
{
    Node *root = buildTree();
    int size = 0;
    getSize(root, size);
    int mid = 0;
    if (size % 2 == 0)
    {
        int low, high;
        int lowIndex = size / 2;
        int highIndex = (size / 2) + 1;
        inorderSmallest(root, lowIndex, low);
        inorderSmallest(root, highIndex, high);
        mid = (low + high) / 2;
    }
    else
    {
        int midIndex = (size + 1) / 2;
        inorderSmallest(root, midIndex, mid);
    }
    cout << mid << endl;
    return 0;
}