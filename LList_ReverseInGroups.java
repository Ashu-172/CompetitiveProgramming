
/*///////////////////// Q 127: Babbar450:Reverse a Linked List in group of Given Size ///////////////////
1. store the head in a variable, which will be used to link the next part after reversal.
2. reverse the list partially for k nodes.
3. after reversing q will have the first node of the new reversed partial list, we'll return it so that it can be linked to the last node of the previous recursive call.
4. since r will have the starting node of the next unreversed partial list, we'll call the function recursively with this node as head, which will return the first  node of the reversed partial list.
*/
public class LList_ReverseInGroups {
    private static ListNode reverse(ListNode head, int k) {
        if (head == null || head.next == null)
            return head;

        ListNode prev = head, p = head, q = head, r = head.next;
        for (int i = 0; i < k - 1 && r != null; i++) {
            q = r;
            r = r.next;
            q.next = p;
            p = q;
        }

        prev.next = reverse(r, k);
        return q;
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(2);
        list.insert(4);
        list.insert(5);
        list.insert(6);
        list.insert(7);
        list.insert(8);

        list.printLList();
        int k = 4;
        ListNode newHead = reverse(list.getHead(), k);
        list.printLList(newHead);
    }
}
