#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int n;
    string lines [4];
    cin >> n;
    cin.ignore();

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            getline(cin, lines[i]);
            lines [i] = " " + lines[i];
            lines [i] = lines[i].substr(lines[i].rfind(" ") + 1, lines[i].length());
            int a, b, c, d, e;
            for (int k = 0; k < lines[i].length(); k++)
                lines[i][k] = tolower(lines[i][k]);
            a = lines[i].rfind("a");
            b = lines[i].rfind("e");
            c = lines[i].rfind("i");
            d = lines[i].rfind("o");
            e = lines[i].rfind("u");
            if (max( max( max(a, b) , max(c, d)) , e) != -1)
            lines [i] = lines[i].substr(max( max( max(a, b) , max(c, d)) , e), lines[i].length());
        }
        //output type
        if (!lines[0].compare(lines[1]) && !lines[1].compare(lines[2]) && !lines[2].compare(lines[3]))
            cout << "perfect" << endl;
        else if (!lines[0].compare(lines[1]) && !lines[2].compare(lines[3]))
            cout << "even" << endl;
        else if (!lines[0].compare(lines[2]) && !lines[1].compare(lines[3]))
            cout << "cross" << endl;
        else if (!lines[0].compare(lines[3]) && !lines[1].compare(lines[2]))
            cout << "shell" << endl;
        else
            cout << "free" << endl;
    }
}
