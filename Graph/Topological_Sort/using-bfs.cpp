// Kahn's Algorithm

#include "../../Utils/printvector.cpp"
#include <queue>

typedef vector<vector<int>> Graph;

void bfs(Graph &g, queue<int> &q, vector<int> &inDegree, vector<int> &ans)
{
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto it : g[node])
        {
            inDegree[it]--;
            if (!inDegree[it])
                q.push(it);
        }
    }
}

vector<int> topologicalSort(Graph &g)
{
    vector<int> inDegree(g.size(), 0);
    for (auto node : g)
    {
        for (auto adj : node)
            inDegree[adj]++;
    }
    queue<int> q;
    for (int i = 0; i < g.size(); i++)
    {
        if (!inDegree[i])
            q.push(i);
    }
    vector<int> ans;
    bfs(g, q, inDegree, ans);
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