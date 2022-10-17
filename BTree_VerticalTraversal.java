import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeMap;

public class BTree_VerticalTraversal {
    static ArrayList<Integer> verticalOrder(BTree_Node root) {
        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<Integer, ArrayList<Integer>>();
        traverse(root, map, 0);
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (ArrayList<Integer> list : map.values()) {
            for (int num : list)
                res.add(num);
        }
        return res;
    }

    static void traverse(BTree_Node root, TreeMap<Integer, ArrayList<Integer>> map, int index) {
        Queue<NodeIndex> q = new LinkedList<NodeIndex>();
        if (root != null)
            q.add(new NodeIndex(root, index));

        while (q.isEmpty() != true) {
            NodeIndex t = q.remove();

            if (map.get(t.index) == null) {
                ArrayList<Integer> list = new ArrayList<Integer>();
                list.add(t.node.data);
                map.put(t.index, list);
            } else {
                map.get(t.index).add(t.node.data);
            }

            if (t.node.left != null)
                q.add(new NodeIndex(t.node.left, t.index - 1));

            if (t.node.right != null)
                q.add(new NodeIndex(t.node.right, t.index + 1));
        }

    }

    static class NodeIndex {
        BTree_Node node;
        int index;

        public NodeIndex(BTree_Node node, int index) {
            this.node = node;
            this.index = index;
        }
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        ArrayList<Integer> res = verticalOrder(root);

        System.out.println(res);
    }
}
