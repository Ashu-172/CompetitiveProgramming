import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*///////////////////////////////////// Google Foobar Question 2 //////////////////////////////////
Bunny Worker Locations
======================

Keeping track of Commander Lambda's many bunny workers is starting to get tricky. You've been tasked with writing a program to match bunny 
worker IDs to cell locations.

The LAMBCHOP doomsday device takes up much of the interior of Commander Lambda's space station, and as a result the work areas have an unusual 
layout. They are stacked in a triangular shape, and the bunny workers are given numerical IDs starting from the corner, as follows:

| 7
| 4 8
| 2 5 9
| 1 3 6 10

Each cell can be represented as points (x, y), with x being the distance from the vertical wall, and y being the height from the ground. 

For example, the bunny worker at (1, 1) has ID 1, the bunny worker at (3, 2) has ID 9, and the bunny worker at (2,3) has ID 8. This pattern of 
numbering continues indefinitely (Commander Lambda has been adding a LOT of workers). 

Write a function solution(x, y) which returns the worker ID of the bunny at location (x, y). Each value of x and y will be at least 1 and no greater 
than 100,000. Since the worker ID can be very large, return your solution as a string representation of the number.

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases -- 
Input:
Solution.solution(3, 2)
Output:
    9

Input:
Solution.solution(5, 10)
Output:
    96

/////////////////////////////////////////////////////////////////////////////////////////////////*/
public class Google_FooBarQ2 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input[] = reader.readLine().trim().split(" ");
        long x = Long.parseLong(input[0]);
        long y = Long.parseLong(input[1]);

        System.out.println("Id : " + findId(x, y));
    }

    private static String findId(long col, long row) {
        // finding starting id of bunny for the row
        // start = 1 + sum of AP (1, 2, 3,..., (row-1))
        long start = 1 + ((row - 1) * row) / 2;

        // finding id of the given bunny
        // id = start + sum of AP (row+1, row+2, row+3,...., row+(col-1))

        long a = row + 1;
        long n = col - 1;
        // result = start + ((n/2) * (2*a + (n-1))

        long result = start + (n * (n - 1) / 2) + n * a;
        return String.valueOf(result);
    }
}
