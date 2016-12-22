#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main (void) {
    int m, in, num, perc;
    cin >> m;
    vector <double> s;
    for (int i = 0; i < m; i++) {
        cin >> in;
        s.push_back(in);
    }
    while (in != 77) {
        cin >> in;
        if (in == 99) {
            cin >> num >> perc;
            s.insert(s.begin() + num-1,perc/100.0*s[num-1]);
            s[num] *= (1-perc/100.0);
        }
        else if (in == 88) {
            cin >> num;
            s[num-1] += s[num];
            s.erase(s.begin() + num);
        }
    }
    for (unsigned int i = 0; i < s.size(); i++)
        cout << floor(s[i]+0.5) << " ";

    return 0;
}
