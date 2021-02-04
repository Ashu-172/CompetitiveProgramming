/*///////////////////// Q 172: Babbar450: Vertical Traversal of Binary Tree ///////////////////
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
     2
      \
       3
      /
     4
Output: 2 4 3

Example 2:

Input:
       1
    /    \
   2      3
 /   \      \
4     5      6
Output: 4 2 1 5 3 6

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 5000
////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

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
/////////////////////////////////// Solution 1 ///////////////////////////
/*
The idea is to traverse the tree once and get the minimum and maximum horizontal distance with respect to root. For the tree shown above, minimum distance is -2 (for node with value 4) and maximum distance is 3 (For node with value 9).
Once we have maximum and minimum distances from root, we iterate for each vertical line at distance minimum to maximum from root, and for each vertical line traverse the tree and print the nodes which lie on that vertical line.

Time complexity of above algorithm is O(w*n) where w is width of Binary Tree and n is number of nodes in Binary Tree. In worst case, the value of w can be O(n) (consider a complete tree for example) and time complexity can become O(n2).

Note: This solution is not efficient since we are not doing level order traversal, it will just print nodes coming on same vertical index togather but do not take care of the order.
*/
void findMinMax(Node *root, int &min, int &max, int current)
{
    if (root == NULL)
        return;
    if (current < min)
        min = current;
    if (current > max)
        max = current;

    findMinMax(root->left, min, max, current - 1);
    findMinMax(root->right, min, max, current + 1);
}
void fillResult(Node *root, int vIndex, vector<int> &result, int current)
{
    if (root == NULL)
        return;
    if (current == vIndex)
        result.push_back(root->data);

    fillResult(root->left, vIndex, result, current - 1);
    fillResult(root->right, vIndex, result, current + 1);
}
vector<int> verticalOrder(Node *root)
{
    int min = 0, max = 0;
    findMinMax(root, min, max, 0);
    vector<int> result;
    for (int i = min; i <= max; i++)
    {
        fillResult(root, i, result, 0);
    }
    return result;
}

/////////////////////////////////////////////// Solution 2 ////////////////////////////////////
/*
we can use a map to reduce the work. instead of calculating min and max we can maintain vertical 
index.whenever we move left we'll decrement it and whenever we move right we'll increment it.
we'll create a map of <int, vector<int>> where vertical index will be used as athe key. for any 
vertival index there can be any number of nodes present in the tree. for this we'll use vector 
of data (int) as value in the map.

we'll do level order traversal and fill the map, since we are doing level order traversal, data 
will be already in the correct order in the vector for any vertical index.

after filling the map, we'll iterate over the map and get the data in result vector and return.
*/
vector<int> verticalOrder(Node *root)
{
    queue<pair<Node *, int>> q;
    map<int, vector<int>> resMap;
    vector<int> result;
    if (root == NULL)
        return result;

    q.push(make_pair(root, 0));
    while (q.empty() != true)
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        resMap[temp.second].push_back(temp.first->data);
        if (temp.first->left != NULL)
            q.push(make_pair(temp.first->left, temp.second - 1));

        if (temp.first->right != NULL)
            q.push(make_pair(temp.first->right, temp.second + 1));
    }

    for (auto itr = resMap.begin(); itr != resMap.end(); itr++)
    {
        for (int data : itr->second)
            result.push_back(data);
    }
    return result;
}

int main()
{
    Node *root = buildTree();
    vector<int> res = verticalOrder(root);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    inOrder(root);
    return 0;
}