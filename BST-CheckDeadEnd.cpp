/*///////////////////// Q 216: Babbar450: Check BST contains Dead End ///////////////////////////////
Given a Binary search Tree that contains positive integer values greater then 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Examples:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : Yes
Explanation : Node "1" is the dead End because after that 
              we cant insert any element.       

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : Yes
Explanation : We can't insert any element at 
              node 9.  

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

Output:
The output for each test case will be 1 if the BST contains a dead end else 0.
 

Constraints:
1<=T<=100
1<=N<=200
 

Example(To be used only for expected output):
Input:
2
6
8 5 9 7 2 1
6
8 7 10 9 13 2
Output:
1
1
///////////////////////////////////////////////////////////////////////////////////////////////////*/
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

/////////////////////////////////////////// Solution 1 ////////////////////////////////////////
/*
1. Do inorder traversal and get inorder vector and leaves.
2. search for leaves in inorder vector and check its nearby nodes for DeadEnd, if they have difference of 1, then its a dead end. return true (deadend found).
*/
void traverse(Node *root, vector<int> &inorder, vector<int> &leaves)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        leaves.push_back(root->data);

    traverse(root->left, inorder, leaves);
    inorder.push_back(root->data);
    traverse(root->right, inorder, leaves);
}
int binarySearch(vector<int> input, int num, int start, int end)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (input[mid] == num)
            return mid;
        if (input[mid] < num)
            return binarySearch(input, num, mid + 1, end);
        else
            return binarySearch(input, num, start, mid - 1);
    }
    return -1;
}
bool checkDeadEnds(vector<int> inorder, vector<int> leaves)
{
    int size = inorder.size();
    for (int leaf : leaves)
    {
        int index = binarySearch(inorder, leaf, 0, size - 1);
        if (index == 0 && size > 1)
        {
            if (inorder[index + 1] == leaf + 1)
                return false;
        }
        else if (index == size - 1 && index > 0)
        {
            if (inorder[index - 1] == leaf - 1)
                return false;
        }
        else if (size >= 3)
        {
            if ((inorder[index - 1] == leaf - 1) && (inorder[index + 1] == leaf + 1))
                return false;
        }
    }
    return true;
}
bool isDeadEnd(Node *root)
{
    vector<int> inorder;
    vector<int> leaves;

    traverse(root, inorder, leaves);
    return !checkDeadEnds(inorder, leaves);
}

////////////////////////////////////////////// Solution 2 ///////////////////////////////////////////////
/*
we can do range based traversal to find deadend. following are the cases for Dead Ends.
1. for any node if left range is equals to right range, then only one value will be allowd at that node, and after that no node can be inserted as a child node of that. for example if range for a node is [9,9], then only 9 can be the value of that node, and left and right limits for childs will be [9, 8] and [10, 9]. both are not valid ranges hence no node can be inserted after current node as child. its a dead end.
2. for any node if left or right range is less than 1, its a dead end because problem statement says that numbers will be greater or equal to 1. [-infinite, 0] is invalid range.
*/
void checkDeadEnd(Node *root, bool &flag, int lLim, int rLim)
{
    if (root == NULL)
        return;
    if (flag == true)
        return;

    if (lLim < 1 || rLim < 1 || lLim == rLim)
    {
        flag = true;
        return;
    }

    checkDeadEnd(root->left, flag, lLim, root->data - 1);
    checkDeadEnd(root->right, flag, root->data + 1, rLim);
}
bool isDeadEnd1(Node *root)
{
    bool flag = false;
    checkDeadEnd(root, flag, 1, INT_MAX);
    return flag;
}
int main()
{
    Node *root = buildTree();
    cout << isDeadEnd(root);
    cout << isDeadEnd1(root);
    return 0;
}