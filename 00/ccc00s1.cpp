#include <iostream>

using namespace std;

int main (void) {
    int q, curr = -1, counter = 0;
    int m[3];
    cin >> q >> m[0] >> m[1] >> m[2];
    while (q != 0) {
        q--;
        counter++;
        curr = (curr+1) % 3;
        m[curr]++;
        if (m[0] == 35) {
            q += 30;
            m[0] = 0;
        }
        else if (m[1] == 100) {
            q += 60;
            m[1] = 0;
        }
        else if (m[2] == 10) {
            q += 9;
            m[2] = 0;
        }
    }

    cout << "Martha plays " << counter << " times before going broke.";

    return 0;
}

