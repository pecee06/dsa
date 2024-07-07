// Dijkstra's Algorithm

#include "../../Utils/printVector.cpp"
#include <set>
#define INF (int)1e5

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;

void relax(Graph &g, set<PII> &s, vector<int> &dist)
{
    for (auto it = s.begin(); it != s.end(); it = s.erase(it))
    {
        int currentDist = (*it).first;
        int node = (*it).second;
        for (auto itr : g[node])
        {
            int adjNode = itr.first;
            int edgeWeight = itr.second;
            if (currentDist + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = currentDist + edgeWeight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
}

vector<int> shortestDistances(Graph &g)
{
    // source node is 0
    vector<int> dist(g.size(), INF);
    dist[0] = 0;
    set<PII> s;
    // first -> distance, second -> node
    s.insert({0, 0});
    relax(g, s, dist);
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
