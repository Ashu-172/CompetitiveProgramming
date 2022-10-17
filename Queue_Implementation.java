/*/////////////////// Q 275: Babbar450: Implement Queue using Array from Scratch //////////////////
Implement  Queue using Array.
/////////////////////////////////////////////////////////////////////////////////////////////////*/
class QueueNode {
    int data;
    QueueNode next;

    public QueueNode(int data) {
        this.data = data;
        this.next = null;
    }

}

class Queue {
    private QueueNode front;
    private QueueNode back;
    private int size;

    public Queue() {
        this.size = 0;
        this.front = null;
        this.back = null;
    }

    void enque(int data) {
        QueueNode temp = new QueueNode(data);
        if (size == 0) {
            front = temp;
            back = temp;
        } else {
            back.next = temp;
            back = temp;
        }
        size++;
    }

    QueueNode dequeue() {
        if (front == null)
            return null;

        QueueNode temp = front;
        front = front.next;
        temp.next = null;
        size--;
        return temp;
    }

    void printQueue() {
        QueueNode temp = front;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    int size() {
        return size;
    }
}

class ArrQueue {
    private int arr[];
    private int size;
    private int front;
    private int back;
    private int capacity;

    public ArrQueue(int capacity) {
        this.capacity = capacity;
        arr = new int[capacity];
        size = 0;
        front = -1;
        back = -1;
    }

    public ArrQueue() {
        this.capacity = 10;
        arr = new int[capacity];
        size = 0;
        front = -1;
        back = -1;
    }

    void enque(int data) {
        if (size == capacity) {
            capacity = 2 * capacity;
            int temp[] = new int[capacity];
            for (int i = front, j = 0; j < size; j++, i = (i + 1) % capacity)
                temp[j] = arr[i];
            arr = temp;
        }
        back = (back + 1) % capacity;
        arr[back] = data;
        if (size == 0)
            front = back;
        size++;
    }

    int dequeue() {
        if (front == -1)
            return -1;

        int temp = arr[front];
        size--;
        if (size > 0)
            front = (front + 1) % capacity;
        else
            front = -1;
        return temp;
    }

    void printQueue() {
        for (int i = front, j = 0; j < size && i >= 0; j++, i = (i + 1) % capacity) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    int size() {
        return size;
    }
}

public class Queue_Implementation {
    public static void main(String[] args) {
        // Queue q = new Queue();
        ArrQueue q = new ArrQueue();
        System.out.println(q.size());
        q.enque(1);
        q.enque(2);
        q.enque(3);
        q.enque(4);
        q.enque(5);
        q.printQueue();
        System.out.println(q.size());
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.printQueue();
        System.out.println(q.size());
        q.dequeue();
        q.dequeue();
        q.printQueue();
        System.out.println(q.size());
        q.dequeue();
        q.enque(10);
        q.printQueue();
        System.out.println(q.size());
    }
}
