#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<int>> Image; // Adjacency Matrix

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

void dfs(Image &g, int sr, int sc, int initColor, int newColor, int delRow[4], int delCol[4])
{
    g[sr][sc] = newColor;
    for (int i = 0; i < 4; i++)
    {
        int newRow = sr + delRow[i];
        int newCol = sc + delCol[i];
        if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && g[newRow][newCol] == initColor)
            dfs(g, newRow, newCol, initColor, newColor, delRow, delCol);
    }
}

void floodFill(Image &g, int sr, int sc, int newColor)
{ // T = O(n*m); S = O(n*m)
    int initColor = g[sr][sc];
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(g, sr, sc, initColor, newColor, delRow, delCol);
}

int main()
{
    Image g = {
        {1, 1, 1},
        {2, 2, 0},
        {2, 2, 2}};
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    floodFill(g, sr, sc, newColor);
    for (auto row : g)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}