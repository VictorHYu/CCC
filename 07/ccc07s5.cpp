#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, n, k, w;
    int* pins;
    int* sums;

    scanf("%d",&t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d%d%d",&n,&k,&w);
        pins = new int [n+w];
        sums = new int [n+w];

        for (int j = 0; j < n+w; j++)
        {
            sums [j] = 0;
            if (j < w)
                pins [j] = 0;
            else
                scanf("%d",&pins[j]);
        }

        for (int j = w; j < n + w; j++)
            for (int x = 0; x < w; x++)
            {
                sums[j] += pins[j-x];
            }

        vector < vector <int> > points (n+w,vector <int> (k+1, 0));

        for (int z = w; z < n + w; z++)
        {
            points [z][1] = max (points[z-1][1], sums[z]);
         //   printf("%d ", points[z][1]);
        }
        //printf("\n");

        for (int y = 2; y < k+1; y++)
        {
            for (int z = w; z < n + w; z++)
            {
                points [z][y] = max (points[z-1][y], points[z-w][y-1]+sums[z]);
               // printf("%d ", points[z][y]);
            }
        }

        printf ("%d ", points[n+w-1][k]);
    }
}
