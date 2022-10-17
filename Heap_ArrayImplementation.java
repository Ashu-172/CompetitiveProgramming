////////////////////// Q 312: Babbar450: Implement Min/Max Heap ///////////////////
public class Heap_ArrayImplementation {
    int arr[];
    int capacity;
    int size;

    public Heap_ArrayImplementation(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        arr = new int[capacity];
    }

    void minHeapify(int index) {
        int l = 2 * index + 1;
        int r = 2 * index + 2;
        int min = index;

        if (l < size && arr[l] < arr[min])
            min = l;

        if (r < size && arr[r] < arr[min])
            min = r;

        if (min != index) {
            int temp = arr[min];
            arr[min] = arr[index];
            arr[index] = temp;
            minHeapify(min);
        }
    }

    int getMin() {
        if (size <= 0)
            return Integer.MIN_VALUE;
        return arr[0];
    }

    void insert(int num) {
        if (size >= capacity) {
            System.out.println("Heap is full, item not inserted..!");
        } else {
            int index = size;
            arr[index] = num;
            size++;
            int p = (index - 1) / 2;
            while (index > 0 && arr[p] > arr[index]) {
                int temp = arr[p];
                arr[p] = arr[index];
                arr[index] = temp;

                index = p;
                p = (index - 1) / 2;
            }
        }
    }

    int extractMin() {
        if (size == 0)
            return Integer.MIN_VALUE;

        else if (size == 1) {
            size--;
            return arr[0];
        } else {
            int res = arr[0];
            arr[0] = arr[size - 1];
            arr[size - 1] = res;
            size--;
            minHeapify(0);
            return res;
        }
    }

    boolean decreaseKey(int index, int num) // Decreases value of key at index 'i' to new_val. It is assumed that
    // new_val is smaller than arr[index].
    {
        if (index < 0 || index >= size) {
            System.out.println("Index is greater than size..");
            return false;
        }

        arr[index] = num;
        int p = (index - 1) / 2;
        while (index > 0 && arr[p] > arr[index]) {
            int temp = arr[p];
            arr[p] = arr[index];
            arr[index] = temp;

            index = p;
            p = (index - 1) / 2;
        }
        return true;
    }

    boolean deleteKey(int index) {
        if (decreaseKey(index, Integer.MIN_VALUE) == true) {
            extractMin();
            return true;
        }
        return false;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Heap_ArrayImplementation minHeap = new Heap_ArrayImplementation(10);
        minHeap.insert(10);
        minHeap.insert(7);
        minHeap.insert(3);
        minHeap.insert(9);
        minHeap.insert(1);
        minHeap.insert(8);
        minHeap.insert(2);
        minHeap.insert(6);
        minHeap.insert(4);
        minHeap.insert(5);
        minHeap.printHeap();

        System.out.println(minHeap.getMin());
        System.out.println(minHeap.extractMin());
        minHeap.printHeap();

        minHeap.decreaseKey(5, 0);
        minHeap.printHeap();

        minHeap.deleteKey(2);
        minHeap.printHeap();
    }
}
