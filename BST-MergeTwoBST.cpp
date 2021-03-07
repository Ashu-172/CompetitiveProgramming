/*///////////////////// Q 207: Babbar450: Merge Two Balanced Binary Search Trees ///////////////////
You are given two balanced binary search trees e.g., AVL or Red Black Tree. Write a function that merges the two given balanced BSTs into a balanced binary search tree. Let there be m elements in first tree and n elements in the other tree. Your merge function should take O(m+n) time.
//////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>
#include <vector>

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
//////////////////////////////////////// Solution //////////////////////////////////////
/*
1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
4) Construct a balanced tree from the merged array. This step takes O(m+n) time.
Time complexity of this method is O(m+n). This method takes O(m+n) time even if the input BSTs are not balanced. 
*/
void getInorder(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}

vector<int> mergeSortedArrays(vector<int> arr1, vector<int> arr2)
{
    int size1 = arr1.size();
    int size2 = arr2.size();
    vector<int> result;
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            result.push_back(arr1[i++]);
        else
            result.push_back(arr2[j++]);
    }
    while (i < size1)
        result.push_back(arr1[i++]);

    while (j < size2)
        result.push_back(arr2[j++]);
    return result;
}
Node *createBalancedTree(vector<int> inorder, int start, int end)
{
    Node *temp = NULL;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        temp = new Node(inorder[mid]);
        temp->left = createBalancedTree(inorder, start, mid - 1);
        temp->right = createBalancedTree(inorder, mid + 1, end);
    }
    return temp;
}

int main()
{
    Node *root1 = buildTree();
    Node *root2 = buildTree();
    vector<int> inorder1;
    vector<int> inorder2;

    getInorder(root1, inorder1);
    getInorder(root2, inorder2);

    vector<int> result = mergeSortedArrays(inorder1, inorder2);
    Node *root = createBalancedTree(result, 0, result.size() - 1);
    inOrder(root);
    return 0;
}
