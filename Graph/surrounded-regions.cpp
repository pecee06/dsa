#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<char>> Graph; // Adjacency Matrix
typedef pair<int, int> PII;

inline bool inValidRange(int x, int l, int h)
{
    return l <= x && x < h;
}

void dfs(Graph &g, stack<PII> &s, int delRow[4], int delCol[4])
{
    while (!s.empty())
    {
        auto node = s.top();
        g[node.first][node.second] = 'Z';
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int newRow = node.first + delRow[i];
            int newCol = node.second + delCol[i];
            if (inValidRange(newRow, 0, g.size()) && inValidRange(newCol, 0, g[0].size()) && g[newRow][newCol] == 'O')
                s.push({newRow, newCol});
        }
    }
}

void replaceOWithX(Graph &g)
{ // T = O(n*m); S = O(n*m)
    stack<PII> s;
    for (int i = 0; i < g.size(); i++)
    {
        if (i == 0 || i == g.size() - 1)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                if (g[i][j] == 'O')
                    s.push({i, j});
            }
        }
        else
        {
            for (int j = 0; j < g[0].size(); j += g[0].size() - 1)
            {
                if (g[i][j] == 'O')
                    s.push({i, j});
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    dfs(g, s, delRow, delCol);
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] == 'O')
                g[i][j] = 'X';
            else if (g[i][j] == 'Z')
                g[i][j] = 'O';
        }
    }
}

int main()
{
    Graph g = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};
    replaceOWithX(g);
    for (auto row : g)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}