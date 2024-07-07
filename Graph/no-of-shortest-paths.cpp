#include <iostream>
#include <stack>
#include <vector>
#include <set>
#define INF (int)1e5
using namespace std;

typedef pair<int, int> PII;
typedef vector<vector<PII>> Graph;

int noOfShortestPaths(Graph &g, int source, int destination)
{
    vector<int> dist(g.size(), INF), ways(g.size(), 0);
    dist[source] = 0;
    ways[source] = 1;
    set<PII> s;
    s.insert({0, source});
    for (auto it = s.begin(); it != s.end(); it = s.erase(it))
    {
        int currentDist = (*it).first, node = (*it).second;
        for (auto itr : g[node])
        {
            int adjNode = itr.first, edgeWeight = itr.second;
            if (currentDist + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = currentDist + edgeWeight;
                ways[adjNode] = ways[node];
                s.insert({dist[adjNode], adjNode});
            }
            else if (currentDist + edgeWeight == dist[adjNode])
                ways[adjNode] += ways[node];
        }
    }
    return ways[destination];
}

int main()
{
    // Graph g = {
    //     {{1, 2}, {4, 5}, {6, 7}},
    //     {{0, 2}, {2, 3}, {3, 3}},
    //     {{1, 3}, {5, 1}},
    //     {{1, 3}, {5, 1}, {6, 3}},
    //     {{0, 5}, {6, 2}},
    //     {{2, 1}, {3, 1}, {6, 1}},
    //     {{0, 7}, {3, 3}, {4, 2}}
    // };
    Graph g = {
        {{1, 1}, {3, 1}, {4, 1}},
        {{0, 1}, {2, 1}},
        {{1, 1}, {5, 1}},
        {{0, 1}, {2, 1}, {5, 2}},
        {{0, 1}, {5, 2}},
        {{2, 1}, {3, 2}, {4, 2}}};
    cout << noOfShortestPaths(g, 0, g.size() - 1);

    return 0;
}