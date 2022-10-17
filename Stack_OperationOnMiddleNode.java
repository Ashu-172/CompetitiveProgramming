class DListNode {
    int data;
    DListNode prev = null;
    DListNode next = null;

    public DListNode(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

public class Stack_OperationOnMiddleNode {
    DListNode top = null;
    DListNode middle = null;
    int size = 0;

    void push(int data) {
        DListNode node = new DListNode(data);
        if (size == 0) {
            top = node;
            middle = node;
        } else {
            top.next = node;
            node.prev = top;
            top = node;
            if (size % 2 == 0)
                middle = middle.next;
        }
        size++;
    }

    int pop() {
        if (size == 0)
            return Integer.MIN_VALUE;

        DListNode temp = top;
        top = top.prev;
        if (top != null)
            top.prev = null;

        if (size % 2 != 0)
            middle = middle.prev;

        size--;
        return temp.data;
    }

    int findMiddle() {
        if (middle != null)
            return middle.data;

        return Integer.MIN_VALUE;
    }

    void deleteMiddle() {
        if (middle != null) {
            if (size == 1) {
                top = null;
                middle = null;
            } else {
                if (middle.prev != null)
                    middle.prev.next = middle.next;

                middle.next.prev = middle.prev;

                if (size % 2 == 0)
                    middle = middle.next;
                else
                    middle = middle.prev;
            }
            size--;
        }
    }

    void printStack() {
        DListNode p = top;
        while (p != null) {
            System.out.print(p.data + " ");
            p = p.prev;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack_OperationOnMiddleNode stk = new Stack_OperationOnMiddleNode();
        stk.push(11);
        stk.push(22);
        stk.push(33);
        stk.push(44);
        stk.push(55);
        stk.push(66);
        stk.push(77);

        stk.printStack();

        System.out.println("MiddleItem: " + stk.findMiddle());
        System.out.println("PoppedItem: " + stk.pop());
        System.out.println("MiddleItem: " + stk.findMiddle());
        System.out.println("PoppedItem: " + stk.pop());
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.deleteMiddle();
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.deleteMiddle();
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.deleteMiddle();
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.deleteMiddle();
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.deleteMiddle();
        System.out.println("MiddleItem: " + stk.findMiddle());
        stk.push(88);
        System.out.println("MiddleItem: " + stk.findMiddle());
        System.out.println("PoppedItem: " + stk.pop());
        System.out.println("MiddleItem: " + stk.findMiddle());
    }
}
