
class ListNode {
    int data;
    ListNode next;

    public ListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    private ListNode head;
    private int size;

    LinkedList() {
        this.head = null;
        this.size = 0;
    }

    int size() {
        return size;
    }

    ListNode getHead() {
        return head;
    }

    void insert(int data) {
        ListNode temp = new ListNode(data);
        if (head == null)
            head = temp;
        else {
            ListNode p = head;
            while (p.next != null)
                p = p.next;
            p.next = temp;
        }
        size++;
    }

    void insertAt(int index, int data) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("index " + index + " not present in Linked List.!");
        }
        ListNode temp = new ListNode(data);
        if (index == 0) {
            temp.next = head;
            head = temp;
        } else {
            ListNode p = head;
            for (int i = 1; i < index; i++) {
                p = p.next;
            }
            temp.next = p.next;
            p.next = temp;
        }
        size++;
    }

    int remove() {
        if (size == 0)
            return Integer.MIN_VALUE;

        ListNode p = head;
        if (size == 1) {
            head = null;
            return p.data;
        }

        while (p.next.next != null) {
            p = p.next;
        }
        ListNode temp = p.next;
        p.next = null;
        size--;
        return temp.data;
    }

    int removeFrom(int index) {
        if (index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index " + index + " not present in Linked List.!");

        ListNode temp;
        if (index == 0) {
            temp = head;
            head = head.next;
        } else {
            ListNode p = head;
            for (int i = 1; i < index; i++) {
                p = p.next;
            }
            temp = p.next;
            p.next = temp.next;
        }
        size--;
        return temp.data;
    }

    void reverseIterative() {
        if (head == null || size == 1)
            return;

        ListNode p = null;
        ListNode q = head;
        ListNode r;

        while (q.next != null) {
            r = q.next;
            q.next = p;
            p = q;
            q = r;
        }
        q.next = p;
        head = q;
    }

    ListNode reverseRec(ListNode p) {
        if (p.next == null) {
            head = p;
            return p;
        }
        ListNode q = reverseRec(p.next);
        q.next = p;
        return p;
    }

    void reverse() {
        ListNode end = reverseRec(head);
        end.next = null;
    }

    void printLList() {
        if (head == null)
            return;

        ListNode p = head;
        while (p != null) {
            System.out.print(p.data + " ");
            p = p.next;
        }
        System.out.println();
    }

    void printLList(ListNode node) {
        if (node == null)
            return;

        ListNode p = node;
        while (p != null) {
            System.out.print(p.data + " ");
            p = p.next;
        }
        System.out.println();
    }
}

public class LList_ImplementationWithReverse {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(5);
        list.printLList();
        list.insertAt(3, 4);
        list.printLList();
        list.reverseIterative();
        list.printLList();
        System.out.println(list.remove());
        list.printLList();
        System.out.println(list.removeFrom(2));
        list.printLList();
        list.reverse();
        list.printLList();
    }
}
