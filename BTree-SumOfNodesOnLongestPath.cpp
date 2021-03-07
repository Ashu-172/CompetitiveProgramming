/*///////////////////// Q 187: Babbar450: Find Sum Of Nodes On the Longest Branch ///////////////////
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Examples:

Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output : 13

        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Input:
The function takes a single argument as input the reference pointer to the root of the binary tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the required sum on a new line.

Constraints:
1<=T<=103
1<=N<=103

/////////////////////////////////////////////////////////////////////////////////*/
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
/////////////////////////////// Solution ///////////////////////////////
void findMaxRootSum(Node *root, int level, int sum, int &maxLevel, int &maxSum)
{
    if (root == NULL)
    {
        if (level >= maxLevel)
        {
            maxSum = max(sum, maxSum);
            maxLevel = level;
        }
        return;
    }
    sum = sum + root->data;
    findMaxRootSum(root->left, level + 1, sum, maxLevel, maxSum);
    findMaxRootSum(root->right, level + 1, sum, maxLevel, maxSum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    if (root == NULL)
        return 0;

    int level = 0;
    int maxSum = 0;
    int maxLevel = 0;
    int sum = 0;

    findMaxRootSum(root, level, sum, maxLevel, maxSum);

    return maxSum;
}
int main()
{
    Node *root = buildTree();
    cout << sumOfLongRootToLeafPath(root) << endl;
    return 0;
}
