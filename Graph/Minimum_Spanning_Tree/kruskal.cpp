#include "../../Utils/DisjointSet.cpp"
#include <array>
#include <algorithm>

typedef array<int, 3> Edge;
typedef vector<Edge> Graph;
typedef pair<int, int> PII;

int mstWeight(Graph &g, int v, vector<PII> &mst)
{
    DisjointSet ds(v);
    sort(g.begin(), g.end());
    int weight = 0;
    for (auto it : g)
    {
        int edgeWeight = it[0], node1 = it[1], node2 = it[2];
        if (ds.findParent(node1) == ds.findParent(node2))
            continue;
        ds.Union(node1, node2);
        weight += edgeWeight;
        mst.push_back({node1, node2});
    }
    return weight;
}

int main()
{
    Graph g = {
        {9, 3, 4},
        {4, 0, 4},
        {1, 0, 3},
        {3, 1, 3},
        {2, 0, 1},
        {5, 2, 3},
        {3, 1, 2},
        {7, 1, 5},
        {8, 2, 5}};

    vector<PII> mst;
    cout << mstWeight(g, 6, mst) << endl;
    for (auto it : mst)
        cout << it.first << "," << it.second << endl;

    return 0;
}
