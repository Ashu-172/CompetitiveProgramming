/*///////////////////// Insert into Binary Tree and Delete from Binary Tree ///////////////////
/////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
    Node(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template <typename T>
class BinaryTree
{
public:
    Node<T> *root;

    BinaryTree(T root)
    {
        this->root = new Node<T>(root);
    }
    /*
    To implement insert method we'll use a queue, since we'll insert at the 
    end of the tree, we'll do level order traversal till the last node using 
    queue and insert the new node.
    */
    void insert(T data)
    {
        Node<T> *node = new Node<T>(data);
        queue<Node<T> *> que;
        que.push(root);
        while (que.empty() == false)
        {
            Node<T> *temp = que.front();
            que.pop();
            if (temp->left == NULL)
            {
                temp->left = node;
                break;
            }
            else if (temp->right == NULL)
            {
                temp->right = node;
                break;
            }
            else
            {
                que.push(temp->left);
                que.push(temp->right);
            }
        }
    }
    /*
    to delete a node, we'll do level order traversal and find the node which we want to delete.
    we'll continue to traverse until we reach to the last node, then we'll remove the last node and put its value in the node which we want to delete.
    In this way  we are swapping the node which we want to delete with the last node and deleting the last node, so the Tree will shrink from the end.
    */
    void removeNode(Node<T> *node)
    {
        queue<Node<T> *> que;
        que.push(root);
        Node<T> *temp;
        while (que.empty() == false)
        {
            temp = que.front();
            que.pop();
            if (temp->left == node)
            {
                temp->left = NULL;
                break;
            }
            else if (temp->right == node)
            {
                temp->right = NULL;
                break;
            }
            else
            {
                if (temp->left != NULL)
                    que.push(temp->left);
                if (temp->right != NULL)
                    que.push(temp->right);
            }
        }
        delete (node);
    }
    void deleteNode(T data)
    {
        if (root == NULL)
            return;
        if (root->data == data && root->left == NULL && root->right == NULL)
        {
            delete (root);
            return;
        }

        queue<Node<T> *> q;
        q.push(root);
        Node<T> *temp, *d_node = NULL;
        while (q.empty() != true)
        {
            temp = q.front();
            q.pop();
            if (temp->data == data)
                d_node = temp;

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
        if (d_node != NULL) // putting last node at the place of deleted node
        {
            T newData = temp->data;
            removeNode(temp);
            if (d_node == temp) // when deleting last node, no need to assign
                return;
            else
                d_node->data = newData;
        }
        return;
    }
    void LevelOrder()
    {
        queue<Node<T> *> q;
        q.push(root);
        Node<T> *temp;
        while (q.empty() != true)
        {
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        cout << endl;
    }

    void InOrder(Node<T> *node)
    {
        if (node == NULL)
            return;
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
};

int main()
{
    BinaryTree<int> bTree(5);
    bTree.insert(1);
    bTree.insert(2);
    bTree.insert(3);
    bTree.insert(4);
    bTree.insert(6);
    bTree.insert(7);
    bTree.insert(8);
    bTree.insert(9);
    bTree.LevelOrder();
    bTree.InOrder(bTree.root);
    cout << endl;
    bTree.deleteNode(10);
    bTree.LevelOrder();
    bTree.InOrder(bTree.root);
}
