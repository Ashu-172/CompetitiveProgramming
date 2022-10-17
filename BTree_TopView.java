import java.util.ArrayList;
import java.util.TreeMap;

public class BTree_TopView {
    //////////////// Solution 1 ///////////////////
    static int leftIndex = 0;
    static int rightIndex = 0;

    static ArrayList<Integer> topView(BTree_Node root) {
        getDistance(root, 0);
        int count = rightIndex - leftIndex + 1;

        int resArr[] = new int[count];

        getTopView(root, resArr, 0 - leftIndex);

        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int num : resArr)
            res.add(num);

        return res;
    }

    static void getDistance(BTree_Node root, int axis) { // get Horizontal distance from left most to right most node
        if (axis < leftIndex)
            leftIndex = axis;

        if (axis > rightIndex)
            rightIndex = axis;

        if (root.left != null)
            getDistance(root.left, axis - 1);

        if (root.right != null)
            getDistance(root.right, axis + 1);

    }

    static void getTopView(BTree_Node root, int res[], int index) {
        if (root == null)
            return;

        if (res[index] == 0)
            res[index] = root.data;

        getTopView(root.left, res, index - 1);
        getTopView(root.right, res, index + 1);
    }

    ///////////// Solution 2 /////////////
    static ArrayList<Integer> topView2(BTree_Node root) {
        TreeMap<Integer, NodePair> map = new TreeMap<Integer, NodePair>();
        getTopView(root, map, 0, 0);
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (NodePair entry : map.values())
            res.add(entry.data);
        return res;
    }

    static void getTopView(BTree_Node root, TreeMap<Integer, NodePair> map, int index, int level) {
        if (map.get(index) == null || map.get(index).level > level)
            map.put(index, new NodePair(root.data, level));
        if (root.left != null)
            getTopView(root.left, map, index - 1, level + 1);
        if (root.right != null)
            getTopView(root.right, map, index + 1, level + 1);

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
        // root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        // root.left.left = new BTree_Node(40);
        // root.left.right = new BTree_Node(60);
        // root.right.left = new BTree_Node(80);

        ArrayList<Integer> res = topView(root);

        System.out.println(res);
    }
}
