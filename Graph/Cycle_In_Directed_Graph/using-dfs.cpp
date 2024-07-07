#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

bool dfs(Graph &g, vector<bool> &visited, vector<bool> &pathVisited, int node)
{
    visited[node] = true;
    pathVisited[node] = true;
    for (auto it : g[node])
    {
        if ((!visited[it] && dfs(g, visited, pathVisited, it)) || pathVisited[it])
            return true;
    }
    pathVisited[node] = false;
    return false;
}

bool hasCycle(Graph &g)
{
    vector<bool> visited(g.size(), false);
    vector<bool> pathVisited(g.size(), false);
    for (int node = 0; node < g.size(); node++)
    {
        if (!visited[node] && dfs(g, visited, pathVisited, node))
            return true;
    }
    return false;
}

int main()
{
    Graph g = {
        {1},
        {2},
        {3, 6},
        {4},
        {5},
        {},
        {4},
        {1, 8},
        {9},
        {7}};
    cout << hasCycle(g);

    return 0;
}