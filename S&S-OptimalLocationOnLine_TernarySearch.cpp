/*///////////////// Q 94: Babbar450: Optimum location of point to minimize total distance //////////////////
Given a set of points as and a line as ax+by+c = 0. We need to find a point on given line for which sum of distances from given set of points is minimum.
////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cmath>

using namespace std;

double distance(int points[][2], int a, int b, int c, double x, int size)
{
    /* Calculate y from equation ax+by+c = 0
        y = -(c+ax)/b
    */
    double y = -(c + a * x) / b;
    double dist = 0;
    for (int i = 0; i < size; i++)
    {
        dist += sqrt(pow(x - points[i][0], 2) + pow(y - points[i][1], 2));
    }
    return dist;
}

double findOptimalCost(int points[][2], int a, int b, int c, int size)
{
    //Setting low and high to a very high number 10^6 and -10^6
    double low = -1e6;
    double high = 1e6;

    // loop untill difference between low and high become less than 10^-6 or 0.000001
    while ((high - low) > 1e-6)
    {
        // mid1 and mid2 are representative x co-ordiantes of search space
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        // first calculate y for mid1 (as x), and then calculate total distance
        // from all the points and return.
        double dist1 = distance(points, a, b, c, mid1, size);
        double dist2 = distance(points, a, b, c, mid2, size);

        // if mid2 point gives more total distance, skip third part
        if (dist1 < dist2)
            high = mid2;

        // if mid1 point gives more total distance, skip first part
        else
            low = mid1;
    }
    return distance(points, a, b, c, (low + high) / 2, size);
}

int main()
{
    int a, b, c;
    a = 1, b = -1, c = -3;
    int size = 5;
    int points[5][2] = {{-3, -2}, {-1, 0}, {-1, 2}, {1, 2}, {3, 4}};

    cout << findOptimalCost(points, a, b, c, size);
}