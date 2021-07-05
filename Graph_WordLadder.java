import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import java.io.InputStreamReader;

/*///////////////////// Q 340: Babbar450: Word Ladder ///////////////////
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
////////////////////////////////////////////////////////////////////////////////////////////////*/
public class Graph_WordLadder {
    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (wordList.contains(endWord) == false)
            return 0;
        HashMap<String, ArrayList<String>> adjList = getAdjList(beginWord, wordList);

        int moves = findSmallestPathLength(beginWord, endWord, adjList);
        return moves;
    }

    static int findSmallestPathLength(String start, String end, HashMap<String, ArrayList<String>> adjList) {
        Queue<String> q = new LinkedList<String>();
        HashMap<String, Boolean> visited = new HashMap<String, Boolean>();
        for (String s : adjList.keySet())
            visited.put(s, false);

        q.add(start);
        visited.put(start, true);

        int steps = 1;
        while (q.isEmpty() != true) {
            int adjCount = q.size();
            String parent;
            steps++;
            for (int i = 0; i < adjCount; i++) {
                parent = q.remove();
                for (String child : adjList.get(parent)) {
                    if (visited.get(child) == false) {
                        if (child.equals(end))
                            return steps;
                        q.add(child);
                        visited.put(child, true);
                    }
                }

            }
        }
        return 0;
    }

    static HashMap<String, ArrayList<String>> getAdjList(String beginWord, List<String> wordList) {
        HashMap<String, ArrayList<String>> adjList = new HashMap<String, ArrayList<String>>();

        adjList.put(beginWord, new ArrayList<String>());
        for (int i = 0; i < wordList.size(); i++)
            adjList.put(wordList.get(i), new ArrayList<String>());

        for (String wordStr : adjList.keySet()) {
            char word[] = wordStr.toCharArray();
            for (int j = 0; j < word.length; j++) {
                char temp = word[j];
                for (int k = 97; k <= 122; k++) {
                    word[j] = (char) k;
                    String adjWord = String.valueOf(word);
                    if (adjList.containsKey(adjWord) && true != wordStr.equals(adjWord)) {
                        adjList.get(wordStr).add(adjWord);
                    }
                }
                word[j] = temp;
            }
        }
        return adjList;
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String start = reader.readLine();
        String end = reader.readLine();
        int n = Integer.parseInt(reader.readLine());
        List<String> dict = new ArrayList<String>();
        for (int i = 0; i < n; i++)
            dict.add(reader.readLine());

        System.out.println("Leader Length: " + ladderLength(start, end, dict));
    }
}
