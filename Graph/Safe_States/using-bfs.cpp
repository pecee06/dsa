#include "../../Utils/printVector.cpp"
#include <queue>
#include <algorithm>

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

vector<int> safeStates(Graph &g)
{
    Graph reversed(g.size());
    for (int i = 0; i < g.size(); i++)
    {
        for (auto it : g[i])
            reversed[it].push_back(i);
    }
    vector<int> inDegree(g.size());
    for (int i = 0; i < reversed.size(); i++)
    {
        for (auto it : reversed[i])
            inDegree[it]++;
    }
    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++)
    {
        if (!inDegree[i])
            q.push(i);
    }
    vector<int> ans;
    bfs(reversed, q, inDegree, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Graph g = {
        {1},
        {2},
        {3, 4},
        {4, 5},
        {6},
        {6},
        {7},
        {},
        {1, 9},
        {10},
        {8},
        {9},
    };

    auto safeNodes = safeStates(g);
    printVector(safeNodes);

    return 0;
}