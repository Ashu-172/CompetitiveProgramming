import java.util.LinkedList;
import java.util.Queue;

public class BTree_MirrorTree {
    private static BTree_Node createMirror(BTree_Node root) {
        if (root == null)
            return null;

        BTree_Node node = new BTree_Node(root.data);
        node.left = createMirror(root.right);
        node.right = createMirror(root.left);

        return node;
    }

    private static void levelOrder(BTree_Node node) {
        if (node != null) {
            Queue<BTree_Node> q = new LinkedList<BTree_Node>();
            q.add(node);
            while (q.isEmpty() != true) {
                BTree_Node temp = q.remove();
                System.out.print(temp.data + " ");
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        BTree_Node res = createMirror(root);
        levelOrder(root);
        System.out.println();
        levelOrder(res);
    }
}
