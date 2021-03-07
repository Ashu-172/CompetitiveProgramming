/*///////////////////// Q 210: Babbar450: Count Pairs from Two BSTs for Sum X (Brothers From Different Roots) //////////////////
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

Examples:

Input : BST 1:    5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:    10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        x = 16
    
Output : 3
The pairs are:
(5, 11), (6, 10) and (8, 8)
Input:
The function takes three arguments as input, first the reference pointer to the root(root1) of the BST1, then reference pointer to the root(root2) of the BST2 and last the element X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test cases print the required number of pairs on new line.

Constraints:
1<=T<=100
1<=N<=103

Example:
Input:
7
5 3 7 2 4 6 8
7
10 6 15 3 8 11 18
16
Output:
3

Input:
6
10 20 30 40 5 1
5
25 35 10 15 5
30
Output:
2
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
////////////////////////////////// Solution ///////////////////////////
/*
1. do inorder traversal for Tree1
2. for each node, substract value from X, and search result in tree2, if it is found in tree2 then increase the count.
*/
bool find(Node *root, int num)
{
    if (root == NULL)
        return false;
    if (find(root->left, num))
        return true;
    if (root->data == num)
        return true;
    if (find(root->right, num))
        return true;
    return false;
}
void countPairsForX(Node *root1, Node *root2, int x, int &count)
{
    if (root1 == NULL || root2 == NULL)
        return;

    countPairsForX(root1->left, root2, x, count);
    if (find(root2, x - root1->data))
        count++;
    countPairsForX(root1->right, root2, x, count);
}
int countPairs(Node *root1, Node *root2, int x)
{
    int count = 0;
    countPairsForX(root1, root2, x, count);
    return count;
}

int main()
{
    Node *root1 = buildTree();
    Node *root2 = buildTree();
    int x;
    cin >> x;
    cout << countPairs(root1, root2, x) << endl;
    return 0;
}