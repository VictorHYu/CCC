#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int bfs (int links[100][100], vector <string> urls, int urlCount, string start, string finish) {
    if (start.compare(finish)==0) return 1;
    vector<string>::iterator it = find(urls.begin(),urls.end(), finish);
    int fin = distance(urls.begin(),it);
    it = find(urls.begin(),urls.end(), start);
    int st = distance(urls.begin(),it);

    bool visited [100]= {false};
    visited[st] = 1;
    vector <int> queue;
    queue.push_back(st);

    while(!queue.empty()) {
        int curr = queue[0];
        if (links[curr][fin] == 1)
            return 1;

        for(int i = 0; i < urlCount; i++) {
            if (links[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
        queue.erase(queue.begin());
    }
    return 0;
}

int main (void) {
    int m;
    int p1, p2, pos;
    int am[100][100];

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            am[i][j] = 0;

    int urlCount = 0;
    vector <string> urls;

    string in, current, url1, url2;
    vector <pair<string,string> > links;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        getline(cin,current);
        in = "";
        while (in.compare("</HTML>")!= 0) {
            getline(cin,in);
            pos = 0;
            do {
                p1 = in.find("<A HREF=\"", pos);
                p2 = in.find("\">", pos);
                if (p1 != -1 && p2 != -1) {
                    string sub = in.substr(p1+9,p2-p1-9);
                    if (find(urls.begin(), urls.end(), current) == urls.end()){
                        urls.push_back(current);
                        urlCount++;
                    }
                    if (find(urls.begin(), urls.end(), sub) == urls.end()){
                        urls.push_back(sub);
                        urlCount++;
                    }
                    vector<string>::iterator it = find(urls.begin(),urls.end(), current);
                    int from = distance(urls.begin(),it);
                    it = find(urls.begin(),urls.end(), sub);
                    int to = distance(urls.begin(),it);

                    am[from][to] = 1;
                    cout << "Link from " << urls[from] << " to " << urls[to] << endl;
                }
                pos = p2+2;
            } while (p1 != -1 && p2 != -1);
        }
    }

    while (true) {
        getline(cin, url1);
            if (url1.compare("The End") == 0) break;
        getline(cin, url2);
        if (bfs(am, urls, urlCount, url1, url2))
            cout << "Can surf from " << url1 << " to " << url2 << "." << endl;
        else
            cout << "Can't surf from " << url1 << " to " << url2 << "." << endl;
    }
    return 0;
}
