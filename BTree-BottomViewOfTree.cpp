/*///////////////////// Q 173: Babbar450: Bottom View of Binary Tree ///////////////////
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5

//////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

//////////////////////////////////// Solution /////////////////////////////////////
/*
Refer Top View of Binary Tree Solution.
Here we have canged the condiditon for overriding data in Map. if level of current node is greated or equal to the older node present in map for same key, we'll over ride the entry in the map because the only last node present at a vertical index should be present in the answer.
*/
void getBottomView(Node *root, int vIndex, int level, map<int, pair<int, int>> &map)
{
    if (root == NULL)
        return;

    if (map.count(vIndex) == 0)
    {
        map[vIndex] = make_pair(level, root->data);
    }
    else if (map[vIndex].first <= level)
    {
        map[vIndex] = make_pair(level, root->data);
    }

    getBottomView(root->left, vIndex - 1, level + 1, map);
    getBottomView(root->right, vIndex + 1, level + 1, map);
}
void bottomView(Node *root)
{
    if (root == NULL)
        return;
    map<int, pair<int, int>> map;
    getBottomView(root, 0, 1, map);
    for (auto itr = map.begin(); itr != map.end(); itr++)
    {
        cout << itr->second.second << " ";
    }
    return;
}
int main()
{
    Node *root = buildTree();
    bottomView(root);
    cout << endl;
    inOrder(root);
    return 0;
}