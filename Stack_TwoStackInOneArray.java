///////////////////////////////////////// Q 276: Babbar450: Implement 2 stack in an array ////////////////////////////
/*
The approach is to use both ends of the array as the bottom of the stack (not the top of the stack).
if we are pushing to first stack, we'll increment the top1 and if we are pushing in the second stack, we'll decrement the top2.
similarly if we are popping from the first stack we'll decrement the top1 and if we are popping from the second stack we'll increment the top2.
*/
public class Stack_TwoStackInOneArray {
    int size;
    int top1, top2;
    int arr[] = new int[100];

    Stack_TwoStackInOneArray() {
        int n = 100;
        size = n;
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (top1 <= -1)
            return -1;
        int temp = arr[top1];
        top1--;
        return temp;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (top2 >= size)
            return -1;
        int temp = arr[top2];
        top2++;
        return temp;
    }
}
