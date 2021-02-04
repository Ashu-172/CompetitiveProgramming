/*///////////////////// Q 172: Babbar450: Top View of Binary Tree ///////////////////
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^5
1 <= Node Data <= 10^5
////////////////////////////////////////////////////////////////////////////////////*/
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
////////////////////////////////////// Solution ////////////////////////////////////
/*
The idea here is to keep track of vertical (from root) and horizontal (from left 
most node) distance of the nodes.for any Horizontal distance the node whose level 
(vertical distance) is lesser,will be the part of top view. for any vertical distance 
there will be only one value.

1. first we'll get the distance of left most node and right most node in order to 
    count the total number of nodes to be present in top view.
2. we'll create two arrays, one for level and one for the result (top view).
3. we'll keep track of current position vertically and horizontally for the current node.
4. now there are two cases for current node to be considered in top view
    a) if for current node's horizontal distance there is no entry made in result vector, we'll 
        directly insert current node data in result vector and put its vertical distance (level) in levels vector.
    b) if for current node's horizontal distance there is already an entry in result vector, we'll check whether level for that data in levels vector is lower or higher than current node's level. 
    if it is higher then it means in the tree current node comes in upper level than the stored node so in top view it should be considered. so for this we'll update data in result vector with current node's data and in levels vector we'll update the level value also.
    if level in levels vector for the older value is lower than current node we'll not change anything since current node's level is lower than older node in the tree we'll not replace it.

*/
#if 0
void createTopView(Node *root, int current, int &maxLeftIndex, int &maxRightIndex)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
    {
        if (maxLeftIndex > current - 1)
            maxLeftIndex = current - 1;
        createTopView(root->left, current - 1, maxLeftIndex, maxRightIndex);
    }

    if (root->right != NULL)
    {
        if (maxRightIndex < current + 1)
            maxRightIndex = current + 1;
        createTopView(root->right, current + 1, maxLeftIndex, maxRightIndex);
    }
}

void fillResultArr(Node *root, int current, int currlevel, vector<int> &res, vector<int> &levels)
{
    if (root == NULL)
        return;

    if (res[current] == -1)
    {
        res[current] = root->data;
        levels[current] = currlevel;
    }
    else if (levels[current] > currlevel)
    {
        res[current] = root->data;
        levels[current] = currlevel;
    }

    fillResultArr(root->left, current - 1, currlevel + 1, res, levels);
    fillResultArr(root->right, current + 1, currlevel + 1, res, levels);
}
void topView(struct Node *root)
{
    int maxLeftIndex = 0;
    int maxRightIndex = 0;
    createTopView(root, 0, maxLeftIndex, maxRightIndex);
    int n = maxRightIndex - maxLeftIndex + 1;
    int rootIndex = -maxLeftIndex;
    vector<int> result(n, -1);
    vector<int> levels(n, 0);
    fillResultArr(root, rootIndex, 1, result, levels);

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
}
#endif
/*
Time complexity for the above solution is O(n) and space complexity is also O(n).
*/
//////////////////////////////////// Solution 2 ///////////////////////////////////
/*
we can optimise above solution with the help of a map. in the above solution we are doing traversal two times. first time traversal is for counting the number of nodes present in the top view so that we can create vectors of that size.
instead we can use map where key will be the vertical horizontal distance. since there will be only one data for each horizontal distance it can be used as key, in above solution we are using it as index of vectors.
Value for each key in the map will be pair of data and its level (vertical order).

in this dolution there will be only one traversal of the tree.
Time complexity = O(n) space complexity = O(n).
*/
void fillResultArr(Node *root, int HDistance, int currlevel, map<int, pair<int, int>> &res)
{
    if (root == NULL)
        return;

    if (res.count(HDistance) == 0)
    {
        res[HDistance] = make_pair(root->data, currlevel);
    }
    else if (res[HDistance].second > currlevel)
    {
        res[HDistance] = make_pair(root->data, currlevel);
    }

    fillResultArr(root->left, HDistance - 1, currlevel + 1, res);
    fillResultArr(root->right, HDistance + 1, currlevel + 1, res);
}
void topView(struct Node *root)
{
    map<int, pair<int, int>> res;

    fillResultArr(root, 0, 1, res);
    for (auto itr = res.begin(); itr != res.end(); itr++)
    {
        cout << itr->second.first << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = buildTree();
    topView(root);
    cout << endl;
    inOrder(root);
    return 0;
}