public class BTree_HeightOfTree {
    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(2);
        root.right = new BTree_Node(1);
        root.right.left = new BTree_Node(3);

        System.out.println(height(root));
    }

    private static int height(BTree_Node root) {
        if (root == null)
            return 0;

        int l = height(root.left);
        int r = height(root.right);

        return Math.max(l, r) + 1;
    }
}
