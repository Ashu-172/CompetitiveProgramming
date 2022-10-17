
/*/////////////////// Q 274: Babbar450: Implement Stack with Array from scratch //////////////////
Implement a Stack from scratch using Array and LinkedList.
////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.util.EmptyStackException;

class stackNode {
    int data;
    stackNode next;

    public stackNode(int data) {
        this.data = data;
        next = null;
    }
}

class Stack {
    private int length;
    private stackNode top;

    public Stack() {
        length = 0;
        top = null;
    }

    boolean isEmpty() {
        return top == null;
    }

    int size() {
        return length;
    }

    int top() {
        if (top != null) {
            return top.data;
        }
        throw new EmptyStackException();
    }

    void push(int data) {
        stackNode temp = new stackNode(data);
        temp.next = top;
        top = temp;
        length++;
    }

    int pop() {
        stackNode temp = top; // will automically get deleted
        top = top.next;
        length--;
        return temp.data;
    }

    void printStack() {
        stackNode t = top;
        while (t != null) {
            System.out.print(t.data + " ");
            t = t.next;
        }
        System.out.println();
    }
}

class ArrStack {
    int arr[];
    int size;
    int top;
    int capacity;

    public ArrStack() {
        this.capacity = 10;
        this.arr = new int[capacity];
        this.top = Integer.MIN_VALUE;
        this.size = 0;
    }

    public ArrStack(int capacity) {
        this.capacity = capacity;
        this.arr = new int[capacity];
        this.top = Integer.MIN_VALUE;
        this.size = 0;
    }

    void push(int num) {
        if (size == capacity) {
            capacity = 2 * capacity;
            int temp[] = new int[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            arr = temp;
        }
        arr[size] = num;
        size++;
        top = arr[size - 1];
    }

    int pop() {
        if (size == 0)
            return -1;

        int temp = top;
        size--;
        if (size <= 0)
            top = Integer.MIN_VALUE;
        else
            top = arr[size - 1];
        return temp;
    }

    void printStack() {
        for (int i = size - 1; i >= 0; i--)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    int size() {
        return size;
    }

    int top() {
        return top;
    }
}

public class Stack_Implementation {
    public static void main(String[] args) {
        // Stack stk = new Stack();
        ArrStack stk = new ArrStack();
        System.out.println(stk.size());
        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.push(4);
        stk.push(5);
        System.out.println(stk.size());
        stk.printStack();
        stk.pop();
        stk.pop();
        System.out.println(stk.top());
        stk.printStack();
        stk.pop();
        stk.pop();
        stk.pop();
        stk.printStack();
        stk.pop();
        System.out.println(stk.top());
    }
}
