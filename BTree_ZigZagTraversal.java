import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BTree_ZigZagTraversal {
    // follow same level order traversal, just process two levels in same run of
    // while loop. for the second level instead of puting data in result array, put
    // data in stack and in the end pop data from stack to result. it'll reverse the
    // order of data in every even level
    static ArrayList<Integer> zigZagTraversal(BTree_Node root) {
        Stack<Integer> stk = new Stack<Integer>();
        Queue<BTree_Node> q = new LinkedList<BTree_Node>();
        ArrayList<Integer> res = new ArrayList<Integer>();
        q.add(root);

        while (q.isEmpty() != true) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                BTree_Node temp = q.remove();
                res.add(temp.data);
                if (temp.left != null)
                    q.add(temp.left);

                if (temp.right != null)
                    q.add(temp.right);

            }

            int size2 = q.size();
            for (int i = 0; i < size2; i++) {
                BTree_Node temp = q.remove();

                if (temp.left != null)
                    q.add(temp.left);

                if (temp.right != null)
                    q.add(temp.right);

                stk.push(temp.data);
            }
            while (stk.isEmpty() != true)
                res.add(stk.pop());
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

        ArrayList<Integer> res = zigZagTraversal(root);

        System.out.println(res);
    }
}
