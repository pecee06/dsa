#include "../../Utils/printVector.cpp"
#include <algorithm>

typedef vector<vector<int>> Graph;

bool dfs(Graph &g, vector<bool> &visited, vector<bool> &pathVisited, int node, vector<int> &safeNodes)
{
    visited[node] = true;
    pathVisited[node] = true;
    for (auto it : g[node])
    {
        if ((!visited[it] && dfs(g, visited, pathVisited, it, safeNodes)) || pathVisited[it])
            return true;
    }
    pathVisited[node] = false;
    safeNodes.push_back(node);
    return false;
}

vector<int> safeStates(Graph &g)
{
    vector<int> safeNodes;
    vector<bool> visited(g.size(), false);
    vector<bool> pathVisited(g.size(), false);
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
            dfs(g, visited, pathVisited, i, safeNodes);
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
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
    auto safeNodes = safeStates(g);
    printVector(safeNodes);

    return 0;
}