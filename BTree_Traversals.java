import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class BTree_Node {
    int data;
    BTree_Node left, right;

    BTree_Node(int item) {
        data = item;
        left = right = null;
    }
}

public class BTree_Traversals {
    static ArrayList<Integer> levelOrder(BTree_Node node) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if (node != null) {
            Queue<BTree_Node> q = new LinkedList<BTree_Node>();
            q.add(node);
            while (q.isEmpty() != true) {
                BTree_Node temp = q.remove();
                result.add(temp.data);
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
        return result;
    }

    public static ArrayList<Integer> reverseLevelOrder(BTree_Node node) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if (node != null) {
            Queue<BTree_Node> q = new LinkedList<BTree_Node>();
            q.add(node);
            while (q.isEmpty() != true) {
                BTree_Node temp = q.remove();
                result.add(temp.data);
                if (temp.right != null)
                    q.add(temp.right);
                if (temp.left != null)
                    q.add(temp.left);
            }
            // reversing
            for (int i = 0, j = result.size() - 1; i < j; i++, j--) {
                int temp = result.get(i);
                result.set(i, result.get(j));
                result.set(j, temp);
            }
        }
        return result;
    }

    private static ArrayList<Integer> reverseLevelOrder2(BTree_Node node) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();
        q.add(node);
        Stack<Integer> stk = new Stack<Integer>();
        while (q.isEmpty() != true) {
            BTree_Node n = q.remove();
            stk.push(n.data);
            if (n.right != null)
                q.add(n.right);

            if (n.left != null)
                q.add(n.left);
        }

        while (stk.isEmpty() != true) {
            result.add(stk.pop());
        }
        return result;
    }

    // this boundary traversal is different from the c++ solution and other java
    // solution in BTree_BoundaryTraversal.java. the c++ solution
    // will not consider right boundary or left boundary if root node don't have
    // right child or left child. this solution will give the boundary of the entire
    // tree irrespective of the root node having left child or right child.
    private static ArrayList<Integer> boundaryTraversal(BTree_Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        if (root == null)
            return result;

        Stack<Integer> stk = new Stack<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();

        q.add(root);
        while (q.isEmpty() != true) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                BTree_Node temp = q.remove();
                if (temp.left != null || temp.right != null) {
                    if (i == 0)
                        result.add(temp.data);
                    else if (i == n - 1)
                        stk.push(temp.data);
                }
                if (temp.left != null)
                    q.add(temp.left);

                if (temp.right != null)
                    q.add(temp.right);
            }
        }
        getBottomView(root, result);
        while (stk.isEmpty() != true) {
            result.add(stk.peek());
            stk.pop();
        }

        return result;
    }

    private static void getBottomView(BTree_Node root, ArrayList<Integer> res) {
        if (root.left == null && root.right == null) {
            res.add(root.data);
            return;
        }

        if (root.left != null) {
            getBottomView(root.left, res);
        }

        if (root.right != null) {
            getBottomView(root.right, res);
        }
    }

    public static ArrayList<Integer> preOrderTraversal(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        preOrderHelper(root, res);
        return res;
    }

    private static void preOrderHelper(BTree_Node root, ArrayList<Integer> res) {
        if (root == null)
            return;

        res.add(root.data);
        preOrderHelper(root.left, res);
        preOrderHelper(root.right, res);
    }

    public static ArrayList<Integer> postOrderTraversal(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        postOrderHelper(root, res);
        return res;
    }

    private static void postOrderHelper(BTree_Node root, ArrayList<Integer> res) {
        if (root == null)
            return;

        postOrderHelper(root.left, res);
        postOrderHelper(root.right, res);
        res.add(root.data);
    }

    public static ArrayList<Integer> inOrderTrsversal(BTree_Node root) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        inOrderHelper(root, res);
        return res;
    }

    private static void inOrderHelper(BTree_Node root, ArrayList<Integer> res) {
        if (root == null)
            return;

        inOrderHelper(root.left, res);
        res.add(root.data);
        inOrderHelper(root.right, res);
    }

    public static void main(String[] args) {
        BTree_Node root = new BTree_Node(10);
        root.left = new BTree_Node(20);
        root.right = new BTree_Node(30);
        root.left.left = new BTree_Node(40);
        root.left.right = new BTree_Node(60);
        root.right.left = new BTree_Node(80);

        ArrayList<Integer> res = levelOrder(root);
        for (int num : res) {
            System.out.print(num + " ");
        }
        System.out.println();

        ArrayList<Integer> revRes = reverseLevelOrder(root);
        for (int num : revRes) {
            System.out.print(num + " ");
        }
        System.out.println();

        ArrayList<Integer> revRes2 = reverseLevelOrder2(root);
        for (int num : revRes2) {
            System.out.print(num + " ");
        }
        System.out.println();

        ArrayList<Integer> boundary = boundaryTraversal(root);
        for (int num : boundary) {
            System.out.print(num + " ");
        }
        System.out.println();

        // preorder
        ArrayList<Integer> preorder = preOrderTraversal(root);
        for (int num : preorder) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Inorder
        ArrayList<Integer> inOrder = inOrderTrsversal(root);
        for (int num : inOrder) {
            System.out.print(num + " ");
        }
        System.out.println();

        // PostOrder
        ArrayList<Integer> postOrder = postOrderTraversal(root);
        for (int num : postOrder) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
