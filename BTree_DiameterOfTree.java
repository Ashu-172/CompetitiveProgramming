public class BTree_DiameterOfTree {
    static int diameter(BTree_Node root) {
        if (root == null)
            return 0;

        int hL = height(root.left);
        int hR = height(root.right);

        int dia = hL + hR + 1;

        int diaL = diameter(root.left);
        int diaR = diameter(root.right);

        return Math.max(dia, Math.max(diaL, diaR));
    }

    static int height(BTree_Node root) {
        if (root == null)
            return 0;

        int lH = height(root.left);
        int rH = height(root.right);

        return Math.max(lH, rH) + 1;
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        int res = diameter(root);

        System.out.println(res);
    }
}
