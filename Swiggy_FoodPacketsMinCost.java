import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Swiggy_FoodPacketsMinCost {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String str[] = reader.readLine().trim().split(" ");
        int n = Integer.parseInt(str[0]);
        int k = Integer.parseInt(str[1]);

        PriorityQueue<foodPacket> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            String st[] = reader.readLine().trim().split(" ");
            int price = Integer.parseInt(st[0]);
            int aLikes = Integer.parseInt(st[1]);
            int bLikes = Integer.parseInt(st[2]);
            float pricePerUnit = (aLikes == bLikes && bLikes == 1) ? (float) price / 2 : price;
            minHeap.add(new foodPacket(pricePerUnit, aLikes, bLikes));
        }

        int aPackets = k;
        int bPackets = k;
        float totalCost = 0;
        while (aPackets != 0 || bPackets != 0) {
            foodPacket temp = minHeap.poll();
            if (temp != null) {
                if (temp.aLikes) {
                    aPackets--;
                    totalCost += temp.pricePerUnit;
                }

                if (temp.bLikes) {
                    bPackets--;
                    totalCost += temp.pricePerUnit;
                }
            } else
                break;
        }

        System.out.println("Total Cost: " + totalCost);
    }
}

class foodPacket implements Comparable<foodPacket> {
    float pricePerUnit;
    boolean aLikes;
    boolean bLikes;

    public foodPacket(float pricePerUnit, int aLikes, int bLikes) {
        this.pricePerUnit = pricePerUnit;
        this.aLikes = (aLikes == 1) ? true : false;
        this.bLikes = (bLikes == 1) ? true : false;
    }

    @Override
    public int compareTo(foodPacket o) {
        if (this.pricePerUnit > o.pricePerUnit)
            return 1;
        else if (this.pricePerUnit < o.pricePerUnit)
            return -1;
        else
            return 0;
    }
}
