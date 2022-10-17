import java.util.PriorityQueue;

public class Heap_ReorganizeString {
    public static void main(String[] args) {
        String input = "aab";

        System.out.println(reorganizeString(input));
    }

    public static String reorganizeString(String s) {
        int count[] = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 97]++;
        }

        PriorityQueue<CharCount> maxHeap = new PriorityQueue<CharCount>((a, b) -> b.count - a.count);
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                maxHeap.add(new CharCount((char) (i + 97), count[i]));
        }

        StringBuilder res = new StringBuilder();
        while (maxHeap.size() > 1) {
            CharCount first = maxHeap.poll();
            CharCount second = maxHeap.poll();

            res.append(first.c);
            first.count--;
            if (first.count > 0)
                maxHeap.add(first);

            res.append(second.c);
            second.count--;
            if (second.count > 0)
                maxHeap.add(second);
        }

        if (maxHeap.size() > 0)
            if (maxHeap.peek().count > 1)
                return "";
            else
                res.append(maxHeap.poll().c);
        return res.toString();
    }

}

class CharCount {
    int count;
    char c;

    public CharCount(char c, int count) {
        this.c = c;
        this.count = count;
    }
}
