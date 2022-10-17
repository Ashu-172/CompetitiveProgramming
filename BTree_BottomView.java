import java.util.ArrayList;
import java.util.TreeMap;

public class BTree_BottomView {

    static ArrayList<Integer> bottomView2(BTree_Node root) {
        TreeMap<Integer, NodePair> map = new TreeMap<Integer, NodePair>();
        getBottomView(root, map, 0, 0);
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (NodePair entry : map.values())
            res.add(entry.data);
        return res;
    }

    static void getBottomView(BTree_Node root, TreeMap<Integer, NodePair> map, int index, int level) {
        if (map.get(index) == null || map.get(index).level <= level)
            map.put(index, new NodePair(root.data, level));
        if (root.left != null)
            getBottomView(root.left, map, index - 1, level + 1);
        if (root.right != null)
            getBottomView(root.right, map, index + 1, level + 1);

    }

    static class NodePair {
        int data;
        int level;

        public NodePair(int data, int level) {
            this.data = data;
            this.level = level;
        }
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        ArrayList<Integer> res = bottomView2(root);

        System.out.println(res);
    }
}
