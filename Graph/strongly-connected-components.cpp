// Kosaraju's Algorithm
// Only works with directed graphs

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

void dfs(int node, Graph &g, stack<int> &s, vector<bool> &visited)
{
    visited[node] = true;
    for (auto it : g[node])
    {
        if (!visited[it])
            dfs(it, g, s, visited);
    }
    s.push(node);
}

void dfs(int node, Graph &g, vector<bool> &visited, int &scc)
{
    visited[node] = true;
    for (auto it : g[node])
    {
        if (!visited[it])
        {
            dfs(it, g, visited, scc);
            return;
        }
    }
    scc++;
}

int scc(Graph &g)
{
    stack<int> s;
    vector<bool> visited(g.size(), false);
    // sorting nodes as per finishing time
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
            dfs(i, g, s, visited);
    }
    // reversing the graph
    Graph reversed(g.size());
    for (int i = 0; i < g.size(); i++)
    {
        for (auto node : g[i])
            reversed[node].push_back(i);
    }
    visited.clear();
    visited.resize(g.size(), false);
    int ans = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        for (auto it : reversed[node])
        {
            if (!visited[it])
                dfs(it, reversed, visited, ans);
        }
    }
    return ans;
}

int main()
{
    Graph g = {
        {1},
        {2},
        {0, 3},
        {4},
        {5, 7},
        {6},
        {4, 7},
        {}};
    cout << scc(g);

    return 0;
}