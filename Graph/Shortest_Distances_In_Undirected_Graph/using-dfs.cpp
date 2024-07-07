#include "../../Utils/printVector.cpp"
#include <stack>
#define INF (int)1e5

typedef vector<vector<int>> Graph;

void dfsAndRelax(Graph &g, stack<int> &s, vector<int> &distances)
{
    while (!s.empty())
    {
        int node = s.top();
        int currentDist = distances[node];
        s.pop();
        for (auto it : g[node])
        {
            if (currentDist + 1 < distances[it])
            {
                distances[it] = currentDist + 1;
                s.push(it);
            }
        }
    }
}

vector<int> shortestDistances(Graph &g, int source)
{
    vector<int> distances(g.size(), INF);
    distances[source] = 0;
    stack<int> s;
    s.push(source);
    dfsAndRelax(g, s, distances);
    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] == INF)
            distances[i] = -1;
    }
    return distances;
}

int main()
{
    Graph g = {
        {1, 3},
        {0, 2, 3},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {6, 7},
    };
    for (int i = 0; i < g.size(); i++)
    {
        auto d = shortestDistances(g, i);
        printVector(d);
    }

    return 0;
}
