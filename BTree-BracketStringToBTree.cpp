/*///////////////////// Q 178: Babbar450: BTree from String of brackets ///////////////////
Construct a binary tree from a string consisting of parenthesis and integers. The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root’s value and a pair of parenthesis contains a child binary tree with the same structure. Always start to construct the left child node of the parent first if it exists.

Examples: 

Input : "1(2)(3)" 
Output : 1 2 3
Explanation :
           1
          / \
         2   3
Explanation: first pair of parenthesis contains 
left subtree and second one contains the right 
subtree. Preorder of above tree is "1 2 3".  

Input : "4(2(3)(1))(6(5))"
Output : 4 2 3 1 6 5
Explanation :
           4
         /   \
        2     6
       / \   / 
      3   1 5  
/////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
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
//////////////////////////////////////////// Solution /////////////////////////////
/*
as we know first character in string is root. Substring inside the first adjacent 
pair of parenthesis is for left subtree and substring inside second pair of parenthesis 
is for right subtree. 
We need to find the substring corresponding to left subtree and substring corresponding to right subtree and then recursively call on both of the substrings. 
*/
int findLeftEndIndex(string input, int start, int end)
{
    int size = input.size();
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        if (input[i] == '(')
            sum++;
        else if (input[i] == ')')
            sum--;

        if (sum == 0)
            return i;
    }
    return -1;
}
// Function to Build Tree

Node *buildTree(string input, int start, int end)
{
    Node *root = NULL;

    if (start > end)
        return root;

    root = new Node(input[start] - '0');
    int leftEndIndex = findLeftEndIndex(input, start + 1, end);
    if (leftEndIndex != -1)
    {
        root->left = buildTree(input, start + 2, leftEndIndex - 1);
        root->right = buildTree(input, leftEndIndex + 2, end - 1);
    }
    return root;
}

int main()
{
    string input = "4(2(3)(1))(6(5))";
    if (input.size() != 0)
    {
        Node *root = buildTree(input, 0, input.size() - 1);
        inOrder(root);
    }
    return 0;
}