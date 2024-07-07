// Dijkstra's Algorithm fails with graphs having negative edges
// This algorithm works with directed graphs only

#include "../Utils/printVector.cpp"
#define INF (int)1e5

struct Edge
{
    int source, dest, weight;
};

typedef vector<Edge> Graph;

void relax(Graph &g, vector<int> &dist)
{
    for (auto it : g)
    {
        if (dist[it.source] != INF && dist[it.source] + it.weight < dist[it.dest])
            dist[it.dest] = dist[it.source] + it.weight;
    }
}

vector<int> shortestDistances(Graph &g, int v)
{
    // source node is 0
    vector<int> dist(v, INF);
    dist[0] = 0;
    for (int i = 1; i < v; i++)
    {
        // Relax dist for v-1 times
        relax(g, dist);
    }
    return dist;
}

int main()
{
    Graph g = {
        {0, 1, 5},
        {1, 2, -2},
        {2, 4, 3},
        {1, 5, -3},
        {5, 3, 1},
        {3, 2, 6},
        {3, 4, -2},
    };
    auto d = shortestDistances(g, 6);
    printVector(d);

    return 0;
}