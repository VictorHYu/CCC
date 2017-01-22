#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void check(bool* mark[], int* grid[], int& c, int x, int y, int row, int col)
{
    c++;

    mark[x][y] = true;
    //L
    if (x - 1 >= 0)
        if (mark[x-1][y] == false && grid[x-1][y] == 1)
            check(mark, grid, c, x-1, y, row, col);
    //R
    if (x + 1 < row)
        if (mark[x+1][y] == false && grid[x+1][y] == 1)
            check(mark, grid, c, x+1, y, row, col);
    //U
    if (y + 1 < col)
        if (mark[x][y+1] == false && grid[x][y+1] == 1)
            check(mark, grid, c, x, y+1, row, col);
    //D
    if (y - 1 > 0)
        if (mark[x][y-1] == false && grid[x][y-1] == 1)
            check(mark, grid, c, x, y-1, row, col);
}

int main()
{
    int flooring, row, col, filled = 0;
    int counter;

    string in;

    vector < int > sizes;

    scanf ("%d%d%d", &flooring, &row, &col);

    int** grid;
    grid = new int*[row];
    bool** mark;
    mark = new bool*[row];

    for (int i = 0; i < row; i++)
    {
        grid[i] = new int [col];
        mark[i] = new bool [row];
    }

    cin.ignore();

    for (int i = 0; i < row; i++)
    {
        getline (cin, in);
        for (int j = 0; j < col; j++)
        {
            mark[i][j] = false;
            if (in[j] == '.')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }

    //scan through whole floor plan
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1 && mark[i][j] == false)
            {
                counter = 0;
                check(mark,grid,counter,i,j,row,col);
                sizes.push_back(counter);
            }
        }
    }

    sort (sizes.begin(), sizes.end());
    for (int i = sizes.size() - 1; i >= 0; i--)
    {
        if (flooring - sizes[i] >= 0)
        {
            flooring -= sizes[i];
            filled++;
        }

        else
        {
            if (filled == 1)
                printf("%d%s%d%s", 1, " room, ", flooring, " square metre(s) left over" );
            else
                printf("%d%s%d%s", filled, " rooms, ", flooring, " square metre(s) left over" );
            return 0;
        }
    }
    if (filled == 1)
        printf("%d%s%d%s", 1, " room, ", flooring, " square metre(s) left over" );
    else
        printf("%d%s%d%s", filled, " rooms, ", flooring, " square metre(s) left over" );

    return 0;
}
