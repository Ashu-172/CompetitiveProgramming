public class BTree_CheckBalancedTree {
    private static boolean isBalanced(BTree_Node root) {
        if (height(root) == -1)
            return false;

        return true;
    }

    private static int height(BTree_Node node) {
        if (node == null)
            return 0;

        int l = height(node.left);
        if (l == -1)
            return -1;

        int r = height(node.right);
        if (r == -1)
            return -1;

        if (Math.abs(l - r) > 1)
            return -1;

        return Math.max(l, r) + 1;
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        boolean res = isBalanced(root);

        System.out.println(res);
    }
}
