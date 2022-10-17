import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BTree_DiagonalTraversal {
    private static ArrayList<Integer> diagonal(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();
        q.add(root);
        while (q.isEmpty() != true) {
            BTree_Node temp = q.remove();
            res.add(temp.data);
            if (temp.left != null)
                q.add(temp.left);

            while (temp.right != null) {
                temp = temp.right;
                res.add(temp.data);

                if (temp.left != null)
                    q.add(temp.left);
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

        ArrayList<Integer> res = diagonal(root);

        System.out.println(res);
    }
}
