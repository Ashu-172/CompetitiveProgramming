////////////////////// Q 177: Babbar450: Boundary Traversal of binary tree ///////////////////

import java.util.ArrayList;

public class BTree_BoundaryTraversal {
    static void getLeftBoundary(BTree_Node node, ArrayList<Integer> res) {
        if (node.left == null && node.right == null)
            return;

        res.add(node.data);

        if (node.left != null)
            getLeftBoundary(node.left, res);
        else
            getLeftBoundary(node.right, res);
    }

    static void getBottomView(BTree_Node node, ArrayList<Integer> res) {
        if (node.left == null && node.right == null)
            res.add(node.data);
        else {
            if (node.left != null)
                getBottomView(node.left, res);

            if (node.right != null)
                getBottomView(node.right, res);
        }
    }

    static void getRightBoundary(BTree_Node node, ArrayList<Integer> res) {
        if (node.left == null && node.right == null)
            return;

        if (node.right != null)
            getRightBoundary(node.right, res);
        else
            getRightBoundary(node.left, res);

        res.add(node.data);
    }

    static ArrayList<Integer> boundary(BTree_Node node) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (node == null)
            return res;

        res.add(node.data);
        if (node.left != null)
            getLeftBoundary(node.left, res);

        getBottomView(node, res);

        if (node.right != null)
            getRightBoundary(node.right, res);

        return res;
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.right = new BTree_Node(20);
        root.right.right = new BTree_Node(30);
        root.right.right.right = new BTree_Node(40);
        root.right.right.right.right = new BTree_Node(60);
        root.right.right.right.right.right = new BTree_Node(80);

        ArrayList<Integer> res = boundary(root);

        for (int num : res)
            System.out.print(num + " ");
    }
}
