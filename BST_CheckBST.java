public class BST_CheckBST {
    static int prev = 0;

    // Based on Inorder Traversal becaus ethe inorder traversal of a BST always
    // gives sorted result.
    static boolean isBST(BTree_Node root) {
        if (root == null)
            return true;

        if (isBST(root.left) != true)
            return false;

        if (root.data <= prev)
            return false;

        prev = root.data;

        if (isBST(root.right) != true)
            return false;

        return true;

    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        System.out.println(isBST(root));
        prev = 0;
        BTree_Node root2 = new BTree_Node(40);
        root2.left = new BTree_Node(20);
        root2.right = new BTree_Node(60);
        root2.left.left = new BTree_Node(10);
        root2.left.right = new BTree_Node(30);
        root2.right.left = new BTree_Node(50);
        root2.right.right = new BTree_Node(80);
        System.out.println(isBST(root2));
    }
}