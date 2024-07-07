#include "../Utils/printVector.cpp"
#include <stack>
#define INF (int)1e5

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;

void dfs(int node, Graph &g, stack<int> &s, vector<bool> &visited)
{
    visited[node] = true;
    for (auto it : g[node])
    {
        if (!visited[it.first])
            dfs(it.first, g, s, visited);
    }
    s.push(node);
}

void relax(Graph &g, stack<int> &s, vector<int> &distances)
{
    while (!s.empty())
    {
        int node = s.top();
        int currentDist = distances[node];
        s.pop();
        for (auto it : g[node])
        {
            if (currentDist + it.second < distances[it.first])
                distances[it.first] = currentDist + it.second;
        }
    }
}

vector<int> shortestPaths(Graph &g)
{
    // Source node is the one with least in-degree
    vector<bool> visited(g.size(), false);
    stack<int> s;
    for (int i = 0; i < g.size(); i++)
    {
        if (!visited[i])
            dfs(i, g, s, visited);
    }
    vector<int> distances(g.size(), INF);
    distances[s.top()] = 0;
    relax(g, s, distances);
    return distances;
}

int main()
{
    Graph g = {
        {{1, 2}},
        {{3, 1}},
        {{3, 3}},
        {{}},
        {{0, 3}, {2, 1}},
        {{4, 1}},
        {{4, 2}, {5, 3}},
    };
    auto shortestDistances = shortestPaths(g);
    printVector(shortestDistances);

    return 0;
}