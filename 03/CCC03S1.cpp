#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s = 1, i = 1;

    while (s != 100 && i != 0)
    {
        cin >> i;
        if ((s + i) < 101)
            s += i;

        if (s == 9)
            s=34;
        else if (s == 40)
            s=64;
        else if (s == 67)
            s=86;
        else if (s == 99)
            s = 77;
        else if (s == 90)
            s = 48;
        else if (s == 54)
            s = 19;

        if (i != 0)
            cout << "You are now on square " << s << endl;
        else
            cout << "You Quit!";
        if (s == 100)
            cout << "You Win!";
    }
}
