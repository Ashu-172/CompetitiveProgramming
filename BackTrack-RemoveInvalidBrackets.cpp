/*////////////////////////////////// Q 258: Babbar450: Remove Invalid Brackets ///////////////////////////////////
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

///////////////////////////////////////////// Solution (BFS + Recursion) ////////////////////////////////////////
/*
                                                      "()())()" 
        
        "" ")())()"    "(" "())()"    "()" "))()"    "()(" ")()"    "()()" "()"    "()())" ")"    "()())(" ""


    Here in the above example we can see that when we remove a character from this string, it gets divided into two parts. here if we combine both the parts it may or may not result in a valid parentheses string. recursively we can remove more characters from the right part which will give us two more parts and combining it with previous prefix will give us a string which may or may not be valid. whenever we encounter a valid string as result of prefix+(left+right) we can put it in result.

    But here in the question the constraint is that we need to remove minimum number of parentheses from the string, for this we need to keep thrack of the level or recursion since at each level one character is being removed from the string. we also need to maintain a global minimum removals count. if current level of recursion is more than the global removal count then moving downward in the recursion will not give us a result so from there we need to return.

    but here one condition can arise that that the actual minimum removals will come in the right most branch of the recursion tree. since this recursion is DFS we may find the result on a upper level later, after processing all the levels in previous recursive calls.
    in the above example we found valid string at level one itself (string 4th and 5th) but before reaching there we had already checked all the possiblities for string 1, 2 and 3 which may have given some valid strings at level 5 or 6. this is a very slow approach.

    when we  need to remove less number of parenthese from the string to find the result this approach will take very long time there BFS will be a better approach.
    in BFS approach first we'll check validity of generated string from prefix and suffix, if we found a valid string then we'll just process that level, we'll also put all the pairs of prefixes and suffixes from the current level in a queue. if we did not find any valid sting in current level we'll repeat the same approach for alll the pairs present in the queue by calling the sae function recursively. 

    This BFS solution is good for the cases when the minimum number of removals required is less. if minimum number of removals required is a large number then the previous approach (DFS) will be faster.

    At each level number of function calls are getting multiplied by n-1. for example if string length is 4 then in the queue at 1st level there will be 4 strings in the quene and do the function calls. In the next level we'll process the suffix part for which the length will be 3. so in the queue there will be 4*3 strings present and so on. Hence we can say that the time complexity will be O(!n).
    Space complexity will also be O(!n) because at the max level we can have !n strings stored in the queue.
*/
class Solution1
{
public:
    bool isValid(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                sum++;
            else if (s[i] == ')')
                sum--;
            // for other characters add (0) or skip

            if (sum < 0)
                return false;
        }
        if (sum != 0)
            return false;
        return true; // when sum is 0 (All Balanced)
    }
    void findValidParentheses(unordered_set<string> &result, queue<pair<string, string>> &q)
    {
        int size = q.size();
        string prefix, suffix;
        for (int i = 0; i < size; i++)
        {
            pair<string, string> s = q.front();
            q.pop();
            prefix = s.first;
            suffix = s.second;
            string left, right;
            for (int j = 0; j < suffix.size(); j++)
            {
                left = suffix.substr(0, j);
                right = suffix.substr(j + 1);

                if (isValid(prefix + left + right))
                {
                    result.insert(prefix + left + right);
                }
                q.push(make_pair(prefix + left, right));
            }
        }
        // if in this level we found any valid string, we'll not go to next level
        if (result.size() > 0)
            return;
        else
            findValidParentheses(result, q);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> result;
        queue<pair<string, string>> q;
        if (isValid(s))
            result.insert(s);
        else
        {
            q.push(make_pair("", s));
            findValidParentheses(result, q);
        }
        vector<string> resultV(result.begin(), result.end());
        return resultV;
    }
};
//////////////////////////////////////////////// Solution 2 (Backtracking / DFS)////////////////////////////////////////
/*
For every bracket we have two choices:

Either it can be considered a part of the final expression OR
It can be ignored i.e. we can delete it from our final expression.
Such kind of problems where we have multiple options and we have no strategy or metric of deciding greedily which option to take, we try out all of the options and see which ones lead to an answer. These type of problems are perfect candidates for the programming paradigm, Recursion.

Algorithm

1. Initialize an array that will store all of our valid expressions finally.
2. Start with the leftmost bracket in the given sequence and proceed right in the recursion.
3. The state of recursion is defined by the index which we are currently processing in the original expression. Let this index be represented by the character i. Also, we have two different variables left_count and right_count that represent the number of left and right parentheses we have added to our expression till now. These are the parentheses that were considered.
4. If the current character i.e. S[i] (considering S is the expression string) is neither a closing or an opening parenthesis, then we simply add this character to our final solution string for the current recursion.
5. However, if the current character is either of the two brackets i.e. S[i] == '(' or S[i] == ')', then we have two options. We can either discard this character by marking it an invalid character or we can consider this bracket to be a part of the final expression.
6. When all of the parentheses in the original expression have been processed, we simply check if the expression represented by expr i.e. the expression formed till now is valid one or not. The way we check if the final expression is valid or not is by looking at the values in left_count and right_count. For an expression to be valid left_count == right_count. If it is indeed valid, then it could be one of our possible solutions.
    a. Even though we have a valid expression, we also need to keep track of the number of removals we did to get this expression. This is done by another variable passed in recursion called rem_count.
    b. Once recursion finishes we check if the current value of rem_count is < the least number of steps we took to form a valid expression till now i.e. the global minima. If this is not the case, we don't record the new expression, else we record it.

For a closing bracket, if we decide to keep it as a part of our final expression and there is no corresponding opening bracket to match it in the expression till now, then it will definitely lead to an invalid expression no matter what we do afterwards. so if we encounter rcount>lcount then it will lead to a invalid expression so we can return back from this condition.

Complexity analysis

Time Complexity : O(2^N) since in the worst case we will have only left parentheses in the expression and for every bracket we will have two options i.e. whether to remove it or consider it. Considering that the expression has NN parentheses, the time complexity will be O(2^N).

Space Complexity : O(N) because we are resorting to a recursive solution and for a recursive solution there is always stack space used as internal function states are saved onto a stack during recursion. The maximum depth of recursion decides the stack space used. Since we process one character at a time and the base case for the recursion is when we have processed all of the characters of the expression string, the size of the stack would be O(N). Note that we are not considering the space required to store the valid expressions. We only count the intermediate space here.
*/

class Solution2
{
public:
    int gRemCount = INT_MAX;
    void findParentheses(unordered_set<string> &result, string &s, string prefix, int lcount, int rcount, int index, int remCount)
    {
        if (index == s.size())
        {
            if (lcount == rcount)
            {
                if (remCount < gRemCount)
                {
                    result.clear(); // found new minimum level, remove old values
                    gRemCount = remCount;
                }
                // insert only for min number of removed parentheses (gRemCount)
                if (remCount == gRemCount)
                    result.insert(prefix);
            }
            return;
        }
        if (rcount > lcount)
            return;
        // 1. Not taking ith parentheses
        // if character is not parentheses, we can not skip it
        if (s[index] == '(' || s[index] == ')')
            if (gRemCount >= remCount + 1)
                findParentheses(result, s, prefix, lcount, rcount, index + 1, remCount + 1);

        // 2. Taking ith parentheses
        if (s[index] == '(')
            lcount++;
        else if (s[index] == ')')
            rcount++;
        findParentheses(result, s, prefix + s[index], lcount, rcount, index + 1, remCount);
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> result;
        findParentheses(result, s, "", 0, 0, 0, 0);
        vector<string> resultV(result.begin(), result.end());
        return resultV;
    }
};

///////////////////////////////////////////// Solution 3 (Limited Backtracking) ///////////////////////////////////////////////
/*
The above solution is a very inefficient solution because we try removing each and every possible parentheses from the expression and in the end we check two things:

if the expression is valid or not
if the total number of removed parentheses removed in the current recursion is less than the global minimum till now or not.
We cannot determine which of the parentheses are misplaced because, as the problem statement puts across, we can remove multiple combinations of parentheses and end up with a valid expression. This means there can be multiple valid expressions from a single invalid expression and we have to find all of them.

The one thing all these valid expressions have in common is that they will all be of the same length i.e. as compared to the original expression, all of these expressions will have the same number of characters removed.

What if we could determine this count?

What if in addition to determining this count of characters to be removed, we could also determine the number of left parentheses and number of right parentheses to be removed from the original expression to get any valid expression?

This would cut down the computations immensely and the runtime would plummet as a result. The reason for this is, if we knew how many left and right parentheses are to be removed from the original expression to get a valid expression, we would cut down on so many unwanted recursive calls.

Imagine the original expression to be 1000 characters with only 3 misplaced ( parentheses and 2 misplaced ) parentheses. In our previous solution we would end up trying to remove each one of left and right parentheses and try to reach a valid expression in the end whereas we should only be trying out removing 3 ( brackets and 2 ) brackets.

This is the exact number of ( and ) that have to be removed to get a valid expression. No more, no less.

we can find out the number of misplaced left and right parentheses in a given expression first and then we will slightly modify our original algorithm to incorporate these counts as well.

1. We process the expression one bracket at a time starting from the left.
2. Suppose we encounter an opening bracket i.e. (, it may or may not lead to an invalid expression because there can be a matching ending bracket somewhere in the remaining part of the expression. Here, we simply increment the counter keeping track of left parentheses till now. left += 1
3. If we encounter a closing bracket, this has two meanings:
    a. Either there was no matching opening bracket for this closing bracket and in that case we have an invalid expression. This is the case when left == 0 i.e. when there are no unmatched left brackets available. In such a case we increment another counter say right += 1 to represent misplaced right parentheses.
    b. Or, we had some unmatched opening bracket available to match this closing bracket. This is the case when left > 0. In this case we simply decrement the left counter we had i.e. left -= 1
4. Continue processing the string until all parentheses have been processed.
5. In the end the values of left and right would tell us the number of unmatched ( and ) parentheses respectively.

Now that we have these two values available that tell us the total number of left i.e. ( and right i.e. ) parentheses that have to be removed to make the invalid expression valid, we will modify our previous algorithm.


Algorithm

The overall algorithm remains exactly the same as before. The changes that we will incorporate are listed below:

1. The state of the recursion is now defined by five different variables:
    a. index which represents the current character that we have to process in the original string.
    b. left_count which represents the number of left parentheses that have been added to the expression we are building.
    c. right_count which represents the number of right parentheses that have been added to the expression we are building.
    d. left_rem is the number of left parentheses that remain to be removed.
    e. right_rem represents the number of right parentheses that remain to be removed. Overall, for the final expression to be valid, left_rem == 0 and right_rem == 0.

2. When we decide to not consider a parenthesis i.e. delete a parenthesis, be it a left or a right parentheses, we have to consider their corresponding remaining counts as well. This means that we can only discard a left parentheses if left_rem > 0 and similarly for the right one we will check for right_rem > 0.

3. There are no changes to checks for considering a parenthesis. Only the conditions change for discarding a parenthesis.

4. Condition for an expression being valid in the base case would now become left_rem == 0 and right_rem == 0. Note that we don't have to check if left_count == right_count anymore because in the case of a valid expression, we would have removed all the misplaced or invalid parenthesis by the time the recursion ends. So, the only check we need if left_rem == 0 and right_rem == 0.

The most important thing here is that we have completely gotten rid of checking if the number of parentheses removed is lesser than the current minimum or not. The reason for this is we always remove the same number of parentheses as defined by left_rem + right_rem at the start of recursion.

Complexity analysis

Time Complexity : The optimization that we have performed is simply a better form of pruning. Pruning here is something that will vary from one test case to another. In the worst case, we can have something like ((((((((( and the left_rem = len(S) and in such a case we can discard all of the characters because all are misplaced. So, in the worst case we still have 2 options per parenthesis and that gives us a complexity of O(2^N).

Space Complexity : The space complexity remains the same i.e. O(N) as previous solution. We have to go to a maximum recursion depth of NN before hitting the base case. Note that we are not considering the space required to store the valid expressions. We only count the intermediate space here.

*/
class Solution3
{
public:
    void findParentheses(unordered_set<string> &result, string &s, string prefix, int lcount, int rcount, int index, int lRem, int rRem)
    {
        if (index == s.size())
        {
            if (lRem == 0 && rRem == 0)
            {
                result.insert(prefix);
            }
            return;
        }

        // 1. Not taking ith parentheses
        // if character is not parentheses, we can not skip it
        if (s[index] == '(' && lRem > 0)
            findParentheses(result, s, prefix, lcount, rcount, index + 1, lRem - 1, rRem);
        else if (s[index] == ')' && rRem > 0)
            findParentheses(result, s, prefix, lcount, rcount, index + 1, lRem, rRem - 1);

        // 2. Taking ith parentheses
        if (s[index] == '(')
            lcount++;
        else if (s[index] == ')')
            rcount++;
        if (lcount >= rcount) // opening brackets should be greater or equal to closing bracket
            findParentheses(result, s, prefix + s[index], lcount, rcount, index + 1, lRem, rRem);
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> result;

        int lRem = 0, rRem = 0;
        // calculating number of ( and ) to be removed
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                lRem++;
            else if (s[i] == ')')
            {
                if (lRem == 0)
                    rRem++;
                else //matching ( is present
                    lRem--;
            }
        }

        findParentheses(result, s, "", 0, 0, 0, lRem, rRem);
        vector<string> resultV(result.begin(), result.end());
        return resultV;
    }
};

void printResult(vector<string> result)
{
    cout << "[";
    for (string str : result)
    {
        cout << str << " ";
    }
    cout << "]";
    cout << endl;
}
int main()
{
    string s;
    cin >> s;

    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    vector<string> result;
    result = s1.removeInvalidParentheses(s);
    printResult(result);
    result = s2.removeInvalidParentheses(s);
    printResult(result);
    result = s3.removeInvalidParentheses(s);
    printResult(result);
}