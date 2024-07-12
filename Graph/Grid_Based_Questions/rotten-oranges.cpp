#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Tray;

typedef struct Node
{
    int row, col, generation;
} Triplet;

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

int bfs(Tray &g, queue<Triplet> &q, int delRow[4], int delCol[4])
{
    int maxGen = 0;
    while (!q.empty())
    {
        auto node = q.front();
        maxGen = max(maxGen, node.generation);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = node.row + delRow[i];
            int newCol = node.col + delCol[i];
            if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && g[newRow][newCol] == 1)
            {
                g[newRow][newCol] = 2;
                q.push({newRow, newCol, node.generation + 1});
            }
        }
    }
    return maxGen;
}

int timeToRot(Tray &g)
{ // T = O(n*m); S = O(n*m)
    // 0 -> no orange
    // 1 -> fresh orange
    // 2 -> rotten orange
    queue<Triplet> q;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] == 2)
                q.push({i, j, 0});
        }
    }
    return bfs(g, q, delRow, delCol);
}

int main()
{
    Tray g = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}};
    // Tray g = {
    //     {1, 2, 1},
    //     {1, 1, 0},
    //     {0, 0, 1}};

    cout << timeToRot(g);

    return 0;
}