#include "../Utils/disjointSet.cpp"

typedef pair<int, int> Edge;
typedef vector<Edge> Graph;

int main()
{
    Graph g = {
        {0, 1},
        {1, 2},
        {3, 4},
        {5, 6},
        {4, 5},
        {2, 6},
    };
    DisjointSet ds(7);
    for (auto edge : g)
        ds.Union(edge.first, edge.second);

    cout << ds.findParent(6) << endl;
    cout << ds.findParent(0);

    return 0;
}