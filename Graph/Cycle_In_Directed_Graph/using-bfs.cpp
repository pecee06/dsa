#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph;

void bfs(Graph &g, queue<int> &q, vector<int> &inDegree, int &count)
{
    while (!q.empty())
    {
        int node = q.front();
        count++;
        q.pop();
        for (auto it : g[node])
        {
            inDegree[it]--;
            if (!inDegree[it])
                q.push(it);
        }
    }
}

bool hasCycle(Graph &g)
{
    // Kahn's Algorithm
    // Since topo sort in only possible for DAGs, if the graph is cyclic we won'e get all the nodes in the topo sort
    vector<int> inDegree(g.size(), 0);
    for (auto row : g)
    {
        for (auto adj : row)
        {
            inDegree[adj]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < g.size(); i++)
    {
        if (!inDegree[i])
            q.push(i);
    }
    int count = 0;
    bfs(g, q, inDegree, count);
    if (count < g.size())
        return true;
    return false;
}

int main()
{
    Graph g = {
        {1},
        {2},
        {3, 4},
        {1},
        {}};
    cout << hasCycle(g);

    return 0;
}