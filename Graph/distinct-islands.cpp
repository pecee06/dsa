#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;
typedef pair<int, int> PII;
typedef set<vector<PII>> Shape;
typedef vector<vector<bool>> visitRecord;

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

PII operator-(const PII &lhs, const PII &rhs)
{
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

void bfs(Graph &g, queue<PII> &q, visitRecord &v, int delRow[4], int delCol[4], Shape &s)
{
    vector<PII> temp;
    PII base = {q.front().first, q.front().second};
    temp.push_back({0, 0});
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
                PII p = {newRow, newCol};
                temp.push_back(p - base);
                q.push(p);
                v[newRow][newCol] = true;
            }
        }
    }
    s.insert(temp);
}

int distinctIslands(Graph &g)
{
    queue<PII> q;
    Shape s;
    visitRecord v(g.size(), vector<bool>(g[0].size(), false));
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] && !v[i][j])
            {
                q.push({i, j});
                bfs(g, q, v, delRow, delCol, s);
            }
        }
    }
    return s.size();
}

int main()
{
    Graph g = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
    cout << distinctIslands(g);

    return 0;
}