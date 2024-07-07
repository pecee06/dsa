// MST can only be found out for weighted undirected graphs

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;
typedef priority_queue<PII, vector<PII>, greater<PII>> MinHeap;

int mstWeight(Graph &g)
{
    int weight = 0;
    vector<bool> visited(g.size(), false);
    MinHeap h;
    h.push({0, 0});
    while (!h.empty())
    {
        int cost = h.top().first, node = h.top().second;
        h.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        weight += cost;
        for (auto it : g[node])
        {
            int adjNode = it.first, edgeWeight = it.second;
            if (!visited[adjNode])
                h.push({edgeWeight, adjNode});
        }
    }
    return weight;
}

int main()
{
    Graph g = {
        {{1, 2}, {2, 1}},
        {{0, 2}, {2, 1}},
        {{0, 1}, {1, 1}, {3, 2}, {4, 2}},
        {{2, 2}, {4, 1}},
        {{2, 2}, {3, 1}}};
    cout << mstWeight(g);

    return 0;
}