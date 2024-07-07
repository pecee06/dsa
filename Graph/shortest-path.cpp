#include "../Utils/printVector.cpp"
#include <queue>
#include <algorithm>
#define INF (int)1e5

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;
typedef priority_queue<PII, vector<PII>, greater<PII>> MinHeap;

void relax(Graph &g, MinHeap &h, vector<int> &dist, vector<int> &parent)
{
    while (!h.empty())
    {
        int currentDist = h.top().first;
        int node = h.top().second;
        h.pop();
        for (auto itr : g[node])
        {
            int adjNode = itr.first;
            int edgeWeight = itr.second;
            if (currentDist + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = currentDist + edgeWeight;
                h.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
}

vector<int> shortestPath(Graph &g)
{
    // source node is 0 & destination node is g.size()-1;
    MinHeap h;
    h.push({0, 0});
    vector<int> dist(g.size(), INF);
    dist[0] = 0;
    vector<int> parent(g.size());
    for (int i = 0; i < g.size(); i++)
        parent[i] = i;
    relax(g, h, dist, parent);
    vector<int> ans;
    int node = g.size() - 1;
    while (node)
    {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    Graph g = {
        {{1, 2}, {3, 1}},
        {{0, 2}, {2, 4}, {4, 5}},
        {{1, 4}, {3, 3}, {4, 1}},
        {{0, 1}, {2, 3}},
        {{1, 5}, {2, 1}}};
    auto path = shortestPath(g);
    printVector(path);

    return 0;
}