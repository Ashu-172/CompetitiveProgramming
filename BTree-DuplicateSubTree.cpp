/*//////////////// Q 185: Babbar450: Check if a Binary Tree contains duplicate subtrees of size 2 or more ///////////////
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
 

Example 2 :

Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

Constraints:
1<=length of string<=100
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

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

//////////////////////////////////////// Solution /////////////////////////////////////////
/*

*/
unordered_set<string> subtrees;

string getSubTree(Node *root, bool &flag)
{
    if (flag == true)
        return "";

    if (root == NULL)
        return "";

    string left = getSubTree(root->left, flag);

    string right = getSubTree(root->right, flag);

    //string tree = left + root->data + right;
    string tree;
    tree.append(left);
    tree.append("" + root->data);
    tree.append(right);

    if (subtrees.find(tree) != subtrees.end() && tree.length() >= 3)
    {
        flag = true;
    }
    else
    {
        subtrees.insert(tree);
    }
    return tree;
}
int main()
{
    Node *root = buildTree();
    bool flag = false;
    string inorder = getSubTree(root, flag);

    cout << flag;
    return 0;
}
