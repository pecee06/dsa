#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;
typedef pair<int, int> PII;

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

void bfs(Graph &g, int &count, queue<PII> &q, int delRow[4], int delCol[4])
{
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = node.first + delRow[i];
            int newCol = node.second + delCol[i];
            if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && g[newRow][newCol] == 1)
            {
                g[newRow][newCol] = 2;
                q.push({newRow, newCol});
                count++;
            }
        }
    }
}

int countEnclaves(Graph g)
{
    int count = 0;
    queue<PII> q;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            // boundry condition
            if ((i == 0 || i == g.size() - 1 || j == 0 || j == g[0].size() - 1) && g[i][j])
            {
                g[i][j] = 2;
                count++;
                q.push({i, j});
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    bfs(g, count, q, delRow, delCol);
    return count;
}

int main()
{
    Graph g = {
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}};
    cout << countEnclaves(g);

    return 0;
}