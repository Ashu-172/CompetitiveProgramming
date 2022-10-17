public class BST_SuccessorAndPredecessor {
    public static void findPreSucItr(BTree_Node root, BTree_Node p, BTree_Node s, int key) {
        BTree_Node pre = new BTree_Node(-1);
        BTree_Node suc = new BTree_Node(-1);
        BTree_Node curr = root;
        while (curr != null) {
            if (key < curr.data) {
                suc = curr;
                curr = curr.left;
            } else if (key > curr.data) {
                pre = curr;
                curr = curr.right;
            } else {
                if (curr.right != null)
                    suc = findSmallest(curr.right);
                if (curr.left != null)
                    pre = findGreatest(curr.left);

                break;
            }
        }
        p = pre;
        s = suc;

    }

    private static BTree_Node findGreatest(BTree_Node root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    private static BTree_Node findSmallest(BTree_Node root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

    /////////////////////////////////////////////////////////////////////////

    public static void findPreSucRec(BTree_Node root, BTree_Node pre, BTree_Node suc, int key) {
        if (root == null)
            return;

        if (key == root.data) {
            if (root.right != null)
                suc = findSmallest(root.right);

            if (root.left != null)
                pre = findGreatest(root.left);

        } else if (key < root.data) {
            suc = root;
            findPreSucRec(root.left, pre, suc, key);
        } else if (key > root.data) {
            pre = root;
            findPreSucRec(root.right, pre, suc, key);
        }
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(40);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(60);
        root.left.left = new BTree_Node(10);
        root.left.right = new BTree_Node(30);
        root.right.right = new BTree_Node(80);

        int key = 65;
        BTree_Node pre = new BTree_Node(-1);
        BTree_Node succ = new BTree_Node(-1);
        findPreSucItr(root, pre, succ, key);
        System.out.println("pre: " + pre.data + " succ: " + succ.data);
        findPreSucRec(root, pre, succ, key);
        System.out.println("pre: " + pre.data + " succ: " + succ.data);

    }
}
