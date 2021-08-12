
/*///////////////////// Q 349: Babbar450: Total Number of Spanning Tree ///////////////////////
Find Total Number of Spanning Trees in a Given Graph.
/////////////////////////////////////////////////////////////////////////////////////////////*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*////////////////////////////////////////// Solution /////////////////////////////////////
Algorithm :-
STEP 1: Create Adjacency Matrix for the given graph.
STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1, element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
STEP 3: Replace all non-diagonal 1’s with -1.
STEP 4: Calculate co-factor for any element.
STEP 5: The cofactor that you get is the total number of spanning tree for that graph.

Ref: https://www.geeksforgeeks.org/total-number-spanning-trees-graph/
/////////////////////////////////////////////////////////////////////////////////////////*/
public class Graph_TotalNumberOfMST {
    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String st[] = read.readLine().trim().split(" ");
        int n = Integer.parseInt(st[0]);
        int edg = Integer.parseInt(st[1]);

        int matrix[][] = new int[n][n];

        for (int i = 1; i <= edg; i++) {
            String s[] = read.readLine().trim().split(" ");
            int u = Integer.parseInt(s[0]);
            int v = Integer.parseInt(s[1]);
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }

        int result = countMST(n, matrix);
        System.out.println("Total Number of MST: " + result);
    }

    static int countMST(int n, int[][] matrix) {
        if (n == 1)
            return 1;

        for (int i = 0; i < n; i++) {
            int indegree = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    indegree++;
                    matrix[i][j] = -1;
                }
            }
            matrix[i][i] = indegree;
        }

        // choosing first element in matrix and calculating determinant for this
        int temp[][] = new int[n - 1][n - 1];
        fillSubMatrix(matrix, temp, 0, n);

        int result = calculateDeterminant(temp, n - 1);
        return result;
    }

    static int calculateDeterminant(int[][] matrix, int n) {
        if (n == 1)
            return matrix[0][0];

        if (n == 2) {
            return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
        }

        int temp[][] = new int[n - 1][n - 1];
        int sign = 1;
        int result = 0;
        for (int i = 0; i < n; i++) {
            fillSubMatrix(matrix, temp, i, n);
            result += sign * matrix[0][i] * calculateDeterminant(temp, n - 1);
            sign = -sign;
        }
        return result;
    }

    static void fillSubMatrix(int matrix[][], int temp[][], int col, int n) // row is always 0th
    {
        for (int i = 1; i < n; i++) {
            for (int j = 0, k = 0; j < n; j++) {
                if (j != col)
                    temp[i - 1][k++] = matrix[i][j];
            }
        }
    }
}
