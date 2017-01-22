#include <iostream>
#include <list>
#include <vector>
#include <cstdio>

using namespace std;

//holds all vertices and edges with adjacency list
class Graph
{
    int n;
    list<int> *adj;

public:
    //constructor to make graph
    Graph(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }
    //adds an edge
    void add(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int BFS(int source, int dest)
    {
        int current, counter = 0;
        current = source;
        //track visited nodes
        vector <bool> visited (n, false);
        //queue to track which nodes to visit next
        list<int> queue;
        //add starting node to queue and mark it as visited
        visited[current] = true;
        queue.push_back(-2);
        queue.push_back(current);
        //used to go through adjacency list
        list<int>::iterator i;
        //loop until all nodes visited or destination is reached
        while(!queue.empty() && !visited[dest])
        {
            current = queue.front();
            if (current == -2)
            {
                queue.pop_front();
                counter++;
                queue.push_back(-2);
            }
            else if (current != -2)
            {
                queue.pop_front();
                //find connected nodes that have not been visited
                for(i = adj[current].begin(); i != adj[current].end(); i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }
        if (visited[dest])
            return counter;
        else
            return -1;
    }
};

int main()
{
    int start = 0, fin = 0;
    int a,b,c,d;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    start = (a-1) + (b-1)*8;
    fin = (c-1) + (d-1)*8;

    // create graph
    Graph g(64);

    //add edges
    for (int a = 0; a < 64; a++)
    {
        if (a < 54 && a % 8 < 6)
            g.add(a,a+10);

        if (a < 47 && a % 8 < 5)
            g.add(a,a+17);

        if (a > 8 && a % 8 < 6)
            g.add(a,a-6);

        if (a > 16 && a % 8 < 5)
            g.add(a,a-15);
    }

    //call bfs
    printf("%d", g.BFS(start,fin));

    return 0;
}
