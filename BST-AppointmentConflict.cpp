/*///////////////////// Q 214: Babbar450: Find Conflicting Appointments ///////////////////
Given n appointments, find all conflicting appointments. 

Examples:

Input: appointments[] = { {1, 5} {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}}
Output: Following are conflicting intervals
[3,7] Conflicts with [1,5]
[2,6] Conflicts with [1,5]
[5,6] Conflicts with [3,7]
[4,100] Conflicts with [1,5]
An appointment is conflicting if it conflicts with any of the previous appointments in the array.
////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data1;
    int data2;
    Node *left = NULL, *right = NULL;
    Node(int data1, int data2)
    {
        this->data1 = data1;
        this->data2 = data2;
    }
};
void insert(Node *&root, pair<int, int> num, bool isConflicted)
{
    if (root == NULL)
        root = new Node(num.first, num.second);
    else if (root->data1 >= num.second)
        insert(root->left, num, isConflicted);
    else if (root->data2 <= num.first)
        insert(root->right, num, isConflicted);
    else // if conflict ocurred
    {
        if (isConflicted == false) // when first conflict, write conflict msg
        {
            cout << "[" << num.first << ", " << num.second << "] conflicted with [" << root->data1 << ", " << root->data2 << "]" << endl;
            isConflicted = true;
        }
        if (num.first < root->data1)
            insert(root->left, num, isConflicted);
        else
            insert(root->right, num, isConflicted);
    }
}
// insear each node in tree and check for conflict
void findConflicts(vector<pair<int, int>> input, int size)
{
    Node *root = new Node(input[0].first, input[0].second);
    for (int i = 1; i < size; i++)
    {
        insert(root, input[i], false);
    }
}
int main()
{
    int n, d1, d2;
    cin >> n;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++)
    {
        cin >> d1 >> d2;
        input.push_back(make_pair(d1, d2));
    }

    findConflicts(input, n);
}