#include "../../Utils/DisjointSet.cpp"
#include <unordered_set>

typedef vector<vector<int>> Graph; // Lower Triangular Shaped Matrix

int provinces(Graph &lowerTriangle)
{
    int n = lowerTriangle.size();
    DisjointSet ds(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (lowerTriangle[i][j])
                ds.Union(i, j + i + 1);
        }
    }
    unordered_set<int> componentHeads;
    for (int i = 0; i <= n; i++)
        componentHeads.insert(ds.findParent(i));
    return componentHeads.size();
}

int main()
{
    Graph lowerTriangle = {
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0},
        {0, 0},
        {1}};
    cout << provinces(lowerTriangle);

    return 0;
}
