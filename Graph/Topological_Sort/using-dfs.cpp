// Only directed acyclic graphs (DAGs) can be sorted topologically

#include "../../Utils/printvector.cpp"
#include <stack>

typedef vector<vector<int>> Graph;

void dfs(Graph &g, vector<bool> &visited, stack<int> &s, int node)
{
    visited[node] = true;
    for (auto it : g[node])
    {
        if (!visited[it])
            dfs(g, visited, s, it);
    }
    s.push(node);
}

vector<int> topologicalSort(Graph &g)
{
    vector<bool> visited(g.size(), false);
    stack<int> s;
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
            dfs(g, visited, s, i);
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    Graph g = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}};
    auto v = topologicalSort(g);
    printVector(v);

    return 0;
}