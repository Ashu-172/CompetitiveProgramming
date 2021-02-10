/*///////////////////// Q 174: Babbar450: ZigZag Tree Traversal ///////////////////
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
/////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <deque>
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
/////////////////////////////// Solution ///////////////////////
/*
For zigzag traversal we have to do level order traversal and in that first we have to traverse left to right for first level and then for second level we have to traverse right to left and repeat this for all the levels.

So there will be to cases
1. When traversing from left to right:
    In this case we’ll pop nodes from the front of the queue and while pushing childrens to the queue 
    we’ll first push left and then right child to the back of the queue. (This we’ll do for level 1,3,5…)
2. When traversing right to left:
    In this case we’ll pop nodes from the back of the queue and while pushing childrens to the queue 
    we’ll first push right and then left child to the front of the queue. (This we’ll do for level 2,4,6...)
    
For this we’ll use Double Ended Queue (deque).
Time complexity and space complexity for this solution will be O(n) and O(n).

*/
vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    deque<Node *> q;
    if (root != NULL)
        q.push_front(root);

    while (q.empty() != true)
    {
        int size = q.size();
        Node *temp;
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop_front();

            if (temp->left != NULL)
                q.push_back(temp->left);

            if (temp->right != NULL)
                q.push_back(temp->right);

            result.push_back(temp->data);
        }

        if (q.empty() != true)
        {
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                temp = q.back();
                q.pop_back();

                if (temp->right != NULL)
                    q.push_front(temp->right);

                if (temp->left != NULL)
                    q.push_front(temp->left);

                result.push_back(temp->data);
            }
        }
    }
    return result;
}

int main()
{
    Node *root = buildTree();
    vector<int> res = zigZagTraversal(root);
    for (int n : res)
        cout << n << " ";
    inOrder(root);
    return 0;
}