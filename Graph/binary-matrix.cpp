#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency Matrix
struct Triplet
{
    // Structures are already typedefed in c++
    int row, col, generation;
};

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

void bfs(Graph &g, queue<Triplet> &q, int delRow[4], int delCol[4])
{
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = node.row + delRow[i];
            int newCol = node.col + delCol[i];
            if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && !g[newRow][newCol])
            {
                g[newRow][newCol] = node.generation + 1;
                q.push({newRow, newCol, g[newRow][newCol]});
            }
        }
    }
}

Graph distances(Graph g)
{ // T = O(n*m); S = O(n*m)
    queue<Triplet> q;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j])
                q.push({i, j, 0});
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    bfs(g, q, delRow, delCol);
    return g;
}

int main()
{
    Graph g = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 1}};

    Graph dist = distances(g);
    for (auto row : dist)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}