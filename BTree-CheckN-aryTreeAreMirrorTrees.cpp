/*//////////////// Q 186: Babbar450: Check if two trees are mirror or not ///////////////
Given two n-ary tree's the task is to check if they are mirror of each other or not.

Example

     1                   1
   /  \                /   \
 2      3             3     2

Output: 1

    1                     1
  /  \                  /  \
 2    3                2    3

Output: 0

Note: you may assume that root of both the given tree as 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains two space separated values n and e denoting the no of nodes and edges respectively. Then in the next line two lines are 2*e space separated values u,v denoting an edge from u to v for the both trees .

Output:
For each test case in a new line print 1 if both the trees are mirrors of each other else print 0.

Constraints:
1<=T<=20
1<=n<=15
1<=e<=20

Example:
Input:
2
3 2
1 2 1 3
1 3 1 2
3 2
1 2 1 3
1 2 1 3
Output:
1
0
///////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
If two trees are mirror trees, the order of the childs of any node in tree 1 will be opposite in tree 2.
so we can make a map of <int, vector<int>> where first value will be the node and second value which is 
a vector will contain the childrens of that node in the order they occcurred.

for both the tree we'll create the map and then we can compare the order of childrensof each node in both the maps.
*/
bool compareTrees(unordered_map<int, vector<int>> map1, unordered_map<int, vector<int>> map2)
{
    auto itr1 = map1.begin();
    while (itr1 != map1.end())
    {
        auto itr2 = map2.find(itr1->first);

        if (itr1->second.size() != itr2->second.size())
            return false;

        for (int i = 0, j = itr2->second.size() - 1; i < itr1->second.size() && j >= 0; i++, j--)
        {
            if (itr1->second[i] != itr2->second[j])
                return false;
        }
        itr1++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        int p, c;
        unordered_map<int, vector<int>> map1;
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < e; i++)
        {
            cin >> p;
            cin >> c;
            map1[p].push_back(c);
        }
        for (int i = 0; i < e; i++)
        {
            cin >> p;
            cin >> c;
            map2[p].push_back(c);
        }

        cout << compareTrees(map1, map2) << endl;
    }
    return 0;
}