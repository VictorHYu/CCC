#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

double distance (double x, pair<double,double> pt) {
    return pow(x-pt.first,2) + pow(pt.second,2);
}

int main (void) {
    vector <pair<double,double> > sheep;
    vector <pair<double,double> > eaten;
    vector <pair<double,double> >::iterator it;
    pair <double,double> minpt;

    int m;
    double x,y,d;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        sheep.push_back(make_pair(x,y));
    }

    for (x = 0; x <= 1000; x += 0.01) {
        d = 10000000;
        for (it = sheep.begin(); it < sheep.end(); it++) {
            if(distance(x, *it) < d) {
                minpt = *it;
                d = distance(x, *it);
            }
        }
        if (find(eaten.begin(),eaten.end(),minpt) == eaten.end())
            eaten.push_back(minpt);
    }

    for (it = eaten.begin(); it < eaten.end(); it++)
        cout << "The sheep at (" << setprecision(2) << fixed << it->first << ", " << it->second << ") might be eaten." << endl;

    return 0;
}
