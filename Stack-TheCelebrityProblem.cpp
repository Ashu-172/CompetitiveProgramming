/*/////////////////// Q 283: Babbar450: The celebrity Problem ////////////////////
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1
//////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    //////////////////////////////// Solution 1 (intution Based) /////////////////////////////
    /*
example:  
    0 0 1 1
    1 0 1 0
    0 0 0 0
    1 1 1 0

here index 2 (or person 2) is the celebrity since everyone nows him but he doesn't know anyone in the party.

1. we can observe that if a person is a celebrity column for that will have 1s for each ro, since everyone knows him. except 0th column, each column which has 1 for 0th row can be a celebrity. (for 0th person, first row will also have 0 even if he is a celebrity)
2. now for every column which satisfies above condition, will have exactly one occurrence of 0 with condition row == column, this is for the celebrity. if any potential column has 0 at anyother place , that person can not be the celebrity since there is someone in the party who don't know this celebritty candidate.
3. in the above condition if there is exactly one occurrence of 0 in the current column at row==column, then we'll check the complete row for current celebrity candidate, if he is a celebrity then its row shoulkd have 0 at all places since it doesn't know anyone in the party.
*/
    int celebrity(vector<vector<int>> &arr, int n)
    {
        int celebrityIndex = -1;
        bool isceleb = false;

        for (int i = 0; i < n; i++)
        {
            celebrityIndex = -1;
            isceleb = false;
            if (arr[0][i] == 1 || i == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[j][i] == 0 && i == j)
                        celebrityIndex = j; //found 0 for celebrity itself
                    else if (arr[j][i] == 0 && i != j)
                    {
                        celebrityIndex = -1; // jth person dont know i th person, so i can not be a celebrity
                        break;
                    }
                }

                if (celebrityIndex != -1)
                {
                    isceleb = true;
                    for (int j = 0; j < n; j++)
                    {
                        if (arr[celebrityIndex][j] != 0)
                        {
                            isceleb == false; // knows jth person, not a celebrity
                            break;
                        }
                    }
                }
            }
            if (isceleb == true)
                return celebrityIndex;
        }
        return -1;
    }

    ///////////////////////////////////////// Solution 2 (Recursive) ///////////////////////////////////
    /*
    Hypothesis:
        function findCelebrity(n) gives celebrity index among n persons, returned id will be from o to n-1 always.
        similarly findCelebrity(n-1) gives celebrity index among n-1 persons. 

    Induction:
        if there is no celeb among n-1 persons, return current person as celeb (which may or may not be possible)
                => return n-1  // since n-1 is the nth person
    
    NOTE: Since we are assuming  in above case that current person is the celebrity, e separately has to check the final result is actually a celebrity or not.

        if celeb among n-1 persons is also celevrity among n persons, return celeb. i.e.  celeb don't know nth person but nth person knos celeb.
                =>  if (arr[celeb][n - 1] == 0 && arr[n - 1][celeb] == 1)
                        return celeb;

        if nth person is the celebrity among n persons, meaans celebrity among n-1 person knows nth person but nth person don't know celeb among n-1 persons. then nth person is new celeb, return n-1.
                =>  if (arr[n - 1][celeb] == 0 && arr[celeb][n - 1] == 1)
                    return n - 1;
            
        if there is no celeb present then result -1.

    Base condition:
        when there is only one person, he'll be the celebrity
                =>  if (n == 1)
                        return n - 1;
    */
    int findCelebrity(vector<vector<int>> &arr, int n)
    {
        // when there is only one person, he is the celebrity (Base Condition)
        if (n == 1)
            return n - 1; //that person is 0th person

        int celeb = findCelebrity(arr, n - 1);

        // if there is no celebrity among n-1 elements
        if (celeb == -1)
            return n - 1;

        // if celeb is celebrity among n persons also
        if (arr[celeb][n - 1] == 0 && arr[n - 1][celeb] == 1)
            return celeb;

        // if n is the celebrity not the celen, (celeb knows n but n doesn't know celeb)
        if (arr[n - 1][celeb] == 0 && arr[celeb][n - 1] == 1)
            return n - 1;
        return -1; // no one knows each other
    }

    int find(vector<vector<int>> &arr, int n)
    {
        int celeb = findCelebrity(arr, n);

        if (celeb == -1)
            return -1;

        // checking if returned person is actually a celebrity
        for (int i = 0; i < n; i++)
        {
            if (arr[celeb][i] != 0)
                return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i][celeb] == 0 && i != celeb)
                return -1;
        }
        return celeb;
    }

    //////////////////////////////// Solution 3 (Using Stack) /////////////////////////////
    /*
    There are some observations based on elimination technique (Refer Polya’s How to Solve It book). 
        If A knows B, but B doesn't know A then B may be a celebrity, Discard A and Insert B back to the Stack.
        If B knows A, but A doesn't know B then A may be a celebrity, Discard B and Insert A back to the stack.
        if above cases not satisfied then Discard both, since both of them can not be the celebrity.
        Repeat above two steps till there is zero or one person left in the stack.
        if stack is empty after the loop then there is no celebrity in the party, return -1.
        if one person left in the stack then check if he actually is a celebrity or not.
    */
    int findCelebStack(vector<vector<int>> &arr, int n)
    {
        stack<int> stk;
        for (int i = 0; i < n; i++)
            stk.push(i);

        while (stk.size() > 1)
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();

            if (arr[a][b] == 1 && arr[b][a] == 0)
                stk.push(b);
            else if (arr[b][a] == 1 && arr[a][b] == 0)
                stk.push(a);
        }

        if (stk.size() == 1)
        {
            int celeb = stk.top();
            // checking if celeb  is actually a celebrity
            for (int i = 0; i < n; i++)
            {
                if (arr[celeb][i] != 0)
                    return -1;
            }
            for (int i = 0; i < n; i++)
            {
                if (arr[i][celeb] == 0 && i != celeb)
                    return -1;
            }
            return celeb;
        }
        else
            return -1;
    }
};

//////////////////////////////////////// Solution 4 (two pointer Approach) //////////////////////////////////
/*
The idea is to use two pointers, one from start and one from the end. Assume the start person is A, and the end person is B. If A knows B, then A must not be the celebrity. Else, B must not be the celebrity. At the end of the loop, only one index will be left as a celebrity. Go through each person again and check whether this is the celebrity. 
The Two Pointer approach can be used where two pointers can be assigned, one at the start and other at the end and the elements can be compared and the search space can be reduced. 
 
Algorithm : 
    Create two indices a and b, where a = 0 and b = n-1
    Run a loop until a is less than b.
    Check if a knows b, then a can’t be celebrity. so increment a, i.e. a++
            Else b cannot be celebrity, so decrement b, i.e. b–
    Assign a as the celebrity
    verify a is actally a celebrity.
*/

int findCelebrity(vector<vector<int>> &arr, int n)
{
    // Initialize two pointers
    // as two corners
    int a = 0;
    int b = n - 1;

    // Keep moving while
    // the two pointers
    // don't become same.
    while (a < b)
    {
        if (arr[a][b] == 1)
            a++;
        else
            b--;
    }

    // checking if celeb  is actually a celebrity
    for (int i = 0; i < n; i++)
    {
        if (arr[a][i] != 0)
            return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i][a] == 0 && i != a)
            return -1;
    }

    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    Solution ob;
    cout << ob.findCelebrity(M, n) << endl;
}