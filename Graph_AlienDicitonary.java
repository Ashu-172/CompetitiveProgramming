
/*//////////////////////////////// Q 346 : Babbar450: Find order of character in Alpha bets using Alien Dictonary ////////////////////////
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output. Similarly we can find other orders.

Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N + K)
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*///////////////////////////////////////////////// Solution : Using Toposort //////////////////////////////////////////////////////////
here we have a dictonary and we have to find the order of characters in the Alien language alphabets. So bacically if we can create a graph of alphabets and find the topological sort for it, we will have the alphabets in proper order.

To create the graph we'll prepare the adjacency list using the given dictonary.
1. create an adjacency list for n nodes.
2. iterate over the dictonary and compare two contigious words i.e. a and b, character by character, when we find different characters in two words we'll know that the char from word a will come before char from word b in the alphabet since word a is present before word b in the dictonary. for example in words 'abcd' and 'abca' in the example 1, only 4th character is different which indicates char 'd' comes before char 'a' in alphabets of the language. 
3. create an edge between these characters by adding character from second word to adjacency list of the character from first word.
4. once adjacency list is prepared, perdorm Toposort on the graph and convert the result in a string and return.

There are total k characters meaning k nodes in the graph and N words can make N-1 edges or K^2 edges (which ever is lesser). so the time complexity will be O(N+K) for topo sort and O(N*K) for creating the Adjacency list in worst case.
So final time complexity will be O(N*K).

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Graph_AlienDicitonary {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.next());
        while (t-- > 0) {
            int n = Integer.parseInt(sc.next());
            int k = Integer.parseInt(sc.next());

            String[] words = new String[n];

            for (int i = 0; i < n; i++) {
                words[i] = sc.next();
            }

            // System.out.println(T.findOrder(words,k));
            String order = findOrder(words, n, k);

            String temp[] = new String[n];
            for (int i = 0; i < n; i++)
                temp[i] = words[i];

            Arrays.sort(temp, new Comparator<String>() {
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for (int i = 0; i < Math.min(a.length(), b.length()) && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }

                    if (index1 == index2 && a.length() != b.length()) {
                        if (a.length() < b.length())
                            return 1;
                        else
                            return 0;
                    }

                    if (index1 < index2)
                        return 1;
                    else
                        return 0;

                }
            });

            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (!words[i].equals(temp[i])) {
                    flag = 0;
                    break;
                }
            }

            System.out.println(flag);
            sc.close();
        }
    }

    private static String findOrder(String[] dict, int n, int k) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < k; i++) {
            adj.add(new ArrayList<Integer>());
        }

        for (int i = 0; i < n - 1; i++) {
            int len = Math.min(dict[i].length(), dict[i + 1].length());
            for (int j = 0; j < len; j++) {
                int u = dict[i].charAt(j) - 97;
                int v = dict[i + 1].charAt(j) - 97;

                if (u != v) {
                    adj.get(u).add(v);
                    break;
                }
            }
        }
        String result = topoSort(k, adj);
        return result;
    }

    private static String topoSort(int n, ArrayList<ArrayList<Integer>> adj) {
        int indegree[] = new int[n];
        for (int i = 0; i < n; i++)
            for (int node : adj.get(i)) {
                indegree[node]++;
            }

        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }
        StringBuilder sb = new StringBuilder();
        while (q.isEmpty() != true) {
            int node = q.poll();
            sb.append((char) (node + 97));
            for (int ad : adj.get(node)) {
                indegree[ad]--;
                if (indegree[ad] == 0)
                    q.add(ad);
            }
        }
        return sb.toString();
    }
}
