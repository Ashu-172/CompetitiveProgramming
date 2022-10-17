////////////////////// Q 128, 129, 130: Babbar450: Detect Loop In a Linked List  ///////////////////

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LList_Detect_Remove_Loop {
    private static boolean detectLoop(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    private static void removeLoop(ListNode head) {
        ListNode slow = head, fast = head, prev = null;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast)
                break;
        }

        if (slow == fast) {
            fast = head;
            while (fast != slow) {
                prev = slow;
                slow = slow.next;
                fast = fast.next;
            }
            prev.next = null;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        ListNode head = new ListNode(Integer.parseInt(reader.readLine()));
        ListNode p = head;
        for (int i = 1; i < n; i++) {
            p.next = new ListNode(Integer.parseInt(reader.readLine()));
            p = p.next;
        }

        int loopNode = Integer.parseInt(reader.readLine());
        ListNode q = head;
        for (int i = 1; i < loopNode; i++) {
            q = q.next;
        }

        if (loopNode != 0)
            p.next = q;

        System.out.println(detectLoop(head) == true ? "true" : "false");
        removeLoop(head);
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
}
