///////////////////// Q 197: Babbar450: Find and Insert Key in a BST ///////////////////

public class BST_FindAndInsertKeyInBST {
    static BTree_Node insert(BTree_Node root, int key) {
        if (root == null)
            return new BTree_Node(key);

        if (key < root.data) {
            if (root.left == null)
                root.left = new BTree_Node(key);
            else
                insert(root.left, key);
        } else if (key > root.data) {
            if (root.right == null)
                root.right = new BTree_Node(key);
            else
                insert(root.right, key);
        }
        return root;
    }

    static BTree_Node insertItr(BTree_Node root, int key) {
        if (root == null)
            return new BTree_Node(key);

        BTree_Node p = root;
        while (p.data != key) {
            if (key < p.data)
                if (p.left != null)
                    p = p.left;
                else {
                    p.left = new BTree_Node(key);
                    break;
                }
            else if (p.right != null)
                p = p.right;
            else {
                p.right = new BTree_Node(key);
                break;
            }
        }
        return root;
    }

    static void inorder(BTree_Node root) {
        if (root == null)
            return;

        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(40);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(60);
        root.left.left = new BTree_Node(10);
        root.left.right = new BTree_Node(30);
        root.right.right = new BTree_Node(80);

        insert(root, 50);
        inorder(root);
        System.out.println();
        insertItr(root, 80);
        inorder(root);
    }
}
