#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency Matrix
typedef pair<int, int> PII;
typedef vector<vector<bool>> visitRecord;

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

void bfs(Graph &g, queue<PII> &q, visitRecord &v, int delRow[4], int delCol[4], int &count)
{
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = node.first + delRow[i];
            int newCol = node.second + delCol[i];
            if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && g[newRow][newCol] && !v[newRow][newCol])
            {
                q.push({newRow, newCol});
                v[newRow][newCol] = true;
            }
        }
    }
    count++;
}

int islands(Graph &g)
{ // T = O(v^2); S = O(v)
    int count = 0;
    visitRecord v(g.size(), vector<bool>(g[0].size(), false));
    queue<PII> q;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] && !v[i][j])
            {
                q.push({i, j});
                bfs(g, q, v, delRow, delCol, count);
            }
        }
    }
    return count;
}

int main()
{
    // Graph g = {
    //     {0, 1, 1, 0},
    //     {0, 1, 1, 0},
    //     {0, 0, 1, 0},
    //     {0, 0, 0, 0},
    //     {1, 1, 0, 1},
    // };
    Graph g = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 0}};
    cout << islands(g);

    return 0;
}