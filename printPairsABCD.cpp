///////////////////////////// CtCI P45 Example //////////////////////////
/*////////////////////////// Problem Statement //////////////////////////
Print all positive integer solutions to the equation 
                a^3 + b^3 = c^3 + d^3
where a, b, c, d are integers from 1 to 1000
///////////////////////////////////////////////////////////////////////*/
////////////////////////// Brute force Solution /////////////////////////
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
void printPairs(int n)
{
    for (int a = 1; a <= n; a++)
        for (int b = 0; b <= n; b++)
            for (int c = 0; c <= n; c++)
                for (int d = 0; d <= n; d++)
                {
                    if (pow(a, 3) + pow(b, 3) == pow(c, 3) + pow(d, 3))
                    {
                        cout << "(a, b): (" << a << ", " << b << ")  (c, d): ("
                             << c << ", " << d << ")" << endl;
                    }
                }
#if 0
/*//////////////////////////////////////////////////////////////
in the above codewe are doing unnecessary iterations for d, from 
the equation we can we can directly calculate value of d and it'll
reduce the time complexity from O(n^4) to O(n^3)
                a^3 + b^3 = c^3 + d^3 
            =>  d = pow((a^3 + b^3 -c^3), 1/3)
//////////////////////////////////////////////////////////////*/
//for calculating d cube root will be calculaed using 1.0/3 instead of 1/3 because 1/3 will always be 0 so d will be 1
//This solution is not correct because of floating point precsion. d = pow(64, 1.0/3) = 3 (it should be 4)

    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= a || c <= b; c++)
            {
                int res = (pow(a, 3) + pow(b, 3) - pow(c, 3));
                int d = pow(res, (1.0 / 3)); // roundof value of d

                if (pow(a, 3) + pow(b, 3) == pow(c, 3) + pow(d, 3)) //verifying value of d
                    cout << "(a, b): (" << a << ", " << b << ")  (c, d): ("
                         << c << ", " << d << ")" << endl;
            }
#endif
}

/*////////////////////////////////////// Solution 2 /////////////////////////////////////////
More optimized solution for this probelm is to use Hash Table.
we can calculate c^3 + d^3 and store (c,d) in Hash Table using calculated value as key. 
Then for every value of a^3 + b^3 we can search hash table and get (c,d).
///////////////////////////////////////////////////////////////////////////////////////////*/
void printPairsWithHash(int n)
{
    unordered_multimap<int, pair<int, int>> umap;
    for (int c = 1; c <= n; c++)
        for (int d = 1; d <= n; d++)
        {
            //calculating c^3 + d^3
            int res = pow(c, 3) + pow(d, 3);
            /*total insertion to the Hash Table will be n*n but total size of hash Table will be less
              as (1,2) and (2,1) will have same key, hence there will be a Hash colission and both the 
              pairs will be present on same key.
              for example if n = 4 then total unique keys can be calculated as follows:
                         1  2    3   4       
                                                       Unique Keys
                    1    2  9   28   65      =>      2  9   28   65
                    2    9  16  35   72      =>         16  35   72
                    3   28  35  56   91      =>             56   91
                    4   65  72  91   128     =>                  128

                    Total Unique Keys = n * (n+1) /2  => 4 * 5/2  =>10 (size of the Hash Table)

              */
            umap.insert(make_pair(res, make_pair(c, d)));
        }
//searching  a^3 + b^3 in the Hash Tabls
#if 0
    for (int a = 1; a < n; a++)
        for (int b = 1; b < n; b++)
        {
            int key = pow(a, 3) + pow(b, 3);
            auto itr = umap.equal_range(key);
            for (auto it = itr.first; it != itr.second; it++)
            {
                cout << "(a, b): (" << a << ", " << b << ")  (c, d): ("
                     << it->second.first << ", " << it->second.second << ")" << endl;
            }
        }
#endif
    /*Above code is correct and for this timeComplexity is O(n^2) because insertion and searching in 
    Hash Table gives O(1) time complexity, and we are inserting using 2 loops which gives O(n^2) time 
    complexity. And Same for searching the Key
            total TimeComplexity = O(n^2)O(1) + O(n^2)O(1) => O(n^2)

    We can Optimize it further, since we have calculated all possible values of c^3+d^3, all those values 
    will be same for a^3+b^3, hence we don't need to calculate a^3+b^3 value. we can directly iterate over 
    the Hash Table and print pairs present for all the values of key
    for example: for key = 9 there will be two pairs present (1, 2) and (2, 1)
    Then output will be:        
                        (1, 2) (1, 2)
                        (1, 2) (2, 1)
                        (2, 1) (1, 2)
                        (2, 1) (2, 1)

    for this Time Complexity will be Insertion Time + searching Time
                    insertion = O(n^2) O(1)
                    searching = O(n) 
                    TimeComplexity = O(n^2)O(1) + O(n)   => O(n^2)
*/

    for (auto itr = umap.begin(); itr != umap.end();) //itr++ not required
    {
        cout << "Key: " << itr->first << endl;
        auto range = umap.equal_range(itr->first);
        cout << " Next Key" << range.second->first << endl;
        for (auto local_itr_a = range.first; local_itr_a != range.second; local_itr_a++)
            for (auto local_itr_b = range.first; local_itr_b != range.second; local_itr_b++)
            {
                cout << "(a, b): (" << local_itr_a->second.first << ", " << local_itr_a->second.second << ")  (c, d): ("
                     << local_itr_b->second.first << ", " << local_itr_b->second.second << ")" << endl;
            }

        itr = range.second; //setting itr to the end of the range so that it won't iterate through them again

        /*///////////////////////////////// important points in above solution /////////////////////////////////
        for n = 3 some entries will look like as following, a key can have more than one value
        for example if key is 9 then in Hash Table key 9 will have two entries because of the collission for pairs (1,2) and (2,1). 
                entries in the list will be (2, [(2, (1,1))]), 
                                            (9, [(9, (1, 2)), (9, (2, 1))])
                                            (28, [(28, (1, 3)), (28, (3, 1))])
            
                itr will not point to a range instead it'll point to each entry

        1. following code will iterate through each entry in the HashTable including the Collissioned Values.
                        for (auto itr = umap.begin(); itr != umap.end();itr++)
            
            if  itr is pointing to (9, (1, 2)) then itr++ will point to (9, (2, 1)) and next time it'll point to (28, (1, 3)) and so on.
            
            here iterator will point to each entry one by one. itr-> first will be the key and itr->second will be 
            the pointer to the value.

        2.we need to print the combinations of pairs (a,b) and (c,d)  which has same key. To do that for each key 
            we need to get the range and then we need to use two local iterators on that range.
                        auto range = umap.equal_range(itr->first);
                        for (auto local_itr_a = range.first; local_itr_a != range.second; local_itr_a++)
                            for (auto local_itr_b = range.first; local_itr_b != range.second; local_itr_b++)

            here range.first  will point to the starting of the Value list for the key, and range.second will point
            to the entry which is pointed by the last node of the list i.e. entry for the next key in the Hash Table.
            for example if itr->first is 9 (key) then range.first will point to (9, (1, 2)) and range.second will 
            point to (28, (1, 3)).
            for printing out result we'll increase local iterator till local_itr != range.second;

        3. on every iteration of the loop local iterator local_itr will point to key-value pair, and iterator->first will 
            point to the key and iterator->second will point to the value.
            for example when local_itr is pointing to (9, (1, 2)) then local_itr->first will give key which is 9 and
            local_itr->second will give value which is (1,2).

            Since we are printing values of a,b,c and d, local_itr->second.first will give first value in pair i.e. 1
            and local_itr->second.second will give second value in pair i.e. 2.
        
        4. Now We have already printed All the values in a range for a key, now if we increment our main iterator on the Table, 
            it'll point to the next key-value pair i.e. (9, (2, 1)) which we have already printed using the range. we want the 
            iterator to point to entry for the next key i.e. (28, (1, 3)) instead of the next entry for the same key i.e. (9, (2, 1)).

            To do that we'll remove itr++ from the loop so that it won't perform any increment on itr and we'll make itr to point
            to (28, (1, 3)). As we know range.second will always be pointing to entry for next key, for our case it'll be pointing
            to (28, (1, 3)), so we'll set itr to range.second.

                change in the first step code: for (auto itr = umap.begin(); itr != umap.end();)
                setting itr to correct position: itr = range.second

        */
    }
}

int main()
{
    int n = 5;

    //printPairs(n);

    printPairsWithHash(n);

    return 0;
}
