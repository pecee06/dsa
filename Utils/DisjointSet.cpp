#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        iota(++(parent.begin()), parent.end(), 1);
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void Union(int node1, int node2)
    {
        int p1 = findParent(node1), p2 = findParent(node2);
        if (p1 == p2)
            return;
        int r1 = rank[p1], r2 = rank[p2];
        if (r1 < r2)
            parent[p1] = p2;
        else if (r2 < r1)
            parent[p2] = p1;
        else
        {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
};