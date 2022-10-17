import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BTree_LeftViewRightView {
    private static ArrayList<Integer> leftView(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();
        if (root != null)
            q.add(root);

        while (q.isEmpty() != true) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                BTree_Node temp = q.remove();
                if (i == 0)
                    res.add(temp.data);

                if (temp.left != null)
                    q.add(temp.left);

                if (temp.right != null)
                    q.add(temp.right);
            }
        }
        return res;
    }

    private static ArrayList<Integer> rightView(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();
        if (root != null)
            q.add(root);

        while (q.isEmpty() != true) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                BTree_Node temp = q.remove();
                if (i == n - 1)
                    res.add(temp.data);

                if (temp.left != null)
                    q.add(temp.left);

                if (temp.right != null)
                    q.add(temp.right);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        ArrayList<Integer> resLeft = leftView(root);
        ArrayList<Integer> resRight = rightView(root);

        System.out.println(resLeft);
        System.out.println(resRight);
    }
}
