public class BST_DeleteKeyFromTree {
    public static BTree_Node deleteNode(BTree_Node root, int key) {
        if (root == null)
            return root;

        if (key < root.data)
            root.left = deleteNode(root.left, key);
        else if (key > root.data)
            root.right = deleteNode(root.right, key);
        else {
            BTree_Node newNode;

            if (root.right != null)
                newNode = removeJustBiggerNode(root);
            else if (root.left != null)
                newNode = removeJustSmallerNode(root);
            else
                return null; // key is found at leaf node

            root.data = newNode.data;
        }
        return root;
    }

    private static BTree_Node removeJustSmallerNode(BTree_Node root) {
        BTree_Node parent = root;
        BTree_Node temp = root.left;
        if (temp.right == null) {
            parent.left = temp.left;
        } else {
            while (temp.right != null) {
                parent = temp;
                temp = temp.right;
            }
            parent.right = temp.left;
        }
        return temp;
    }

    private static BTree_Node removeJustBiggerNode(BTree_Node root) {
        BTree_Node parent = root;
        BTree_Node temp = root.right;
        if (temp.left == null) {
            parent.right = temp.right;
        } else {
            while (temp.left != null) {
                parent = temp;
                temp = temp.left;
            }
            parent.left = temp.right;
        }
        return temp;
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

        root = deleteNode(root, 60);
        inorder(root);
    }
}
