/*///////////////////// Q 337: Babbar450: Flood Fill Algorithm ///////////////////////
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.

Example:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
///////////////////////////////////////////////////////////////////////////////////////*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Graph_BfsDfs_FloodFill {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] S1 = br.readLine().trim().split(" ");
        int n = Integer.parseInt(S1[0]);
        int m = Integer.parseInt(S1[1]);
        int[][] image = new int[n][m];
        for (int i = 0; i < n; i++) {
            String[] S2 = br.readLine().trim().split(" ");
            for (int j = 0; j < m; j++)
                image[i][j] = Integer.parseInt(S2[j]);
        }
        String[] S3 = br.readLine().trim().split(" ");
        int sr = Integer.parseInt(S3[0]);
        int sc = Integer.parseInt(S3[1]);
        int newColor = Integer.parseInt(S3[2]);
        FillColor obj = new FillColor();
        // int[][] ans = obj.floodFillBfs(image, sr, sc, newColor);
        int[][] ans = obj.floodFillDfs(image, sr, sc, newColor);
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans[i].length; j++)
                System.out.print(ans[i][j] + " ");
            System.out.println();
        }
    }

}

class FillColor {
    int moves[][] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    public int[][] floodFillDfs(int[][] image, int sr, int sc, int newColor) {
        int m = image.length;
        int n = image[0].length;
        int[][] newImg = new int[m][n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                newImg[i][j] = image[i][j];

        int oldColor = image[sr][sc];
        fillColor(newImg, sr, sc, m, n, oldColor, newColor);
        return newImg;
    }

    private void fillColor(int img[][], int sr, int sc, int m, int n, int oldC, int newC) {
        img[sr][sc] = newC;
        for (int i = 0; i < 4; i++) {
            int r = sr + moves[i][0];
            int c = sc + moves[i][1];

            if (r >= 0 && r < m && c >= 0 && c < n && img[r][c] == oldC && img[r][c] != newC)
                fillColor(img, r, c, m, n, oldC, newC);
        }

    }

    class Location {
        int r;
        int c;

        public Location(int x, int y) {
            this.r = x;
            this.c = y;
        }
    }

    public int[][] floodFillBfs(int[][] image, int sr, int sc, int newColor) {
        int m = image.length;
        int n = image[0].length;

        Queue<Location> q = new LinkedList<Location>();
        int oldColor = image[sr][sc];

        image[sr][sc] = newColor;
        q.add(new Location(sr, sc));

        while (q.isEmpty() != true) {
            Location curr = q.remove();
            for (int i = 0; i < 4; i++) {
                int r = curr.r + moves[i][0];
                int c = curr.c + moves[i][1];

                if (r >= 0 && r < m && c >= 0 && c < n && image[r][c] == oldColor && image[r][c] != newColor) {
                    image[r][c] = newColor;
                    q.add(new Location(r, c));
                }
            }
        }
        return image;
    }

}
