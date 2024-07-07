// Dijkstra's Algorithm

#include "../../Utils/printVector.cpp"
#include <queue>
#define INF (int)1e5

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;
typedef priority_queue<PII, vector<PII>, greater<PII>> MinHeap;

void relax(Graph &g, MinHeap &h, vector<int> &dist)
{
    while (!h.empty())
    {
        int currentDist = h.top().first;
        int node = h.top().second;
        h.pop();
        for (auto it : g[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (currentDist + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = currentDist + edgeWeight;
                h.push({dist[adjNode], adjNode});
            }
        }
    }
}

vector<int> shortestDistances(Graph &g)
{
    // source node is 0
    vector<int> dist(g.size(), INF);
    dist[0] = 0;
    MinHeap h;
    // first -> distance, second -> node
    h.push({0, 0});
    relax(g, h, dist);
    return dist;
}

int main()
{
    Graph g = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{2, 6}, {3, 2}, {4, 3}},
    };
    auto d = shortestDistances(g);
    printVector(d);

    return 0;
}
