// This algorihtm only works with directed graphs

#include "../Utils/printMatrix.cpp"
#define INF (int)1e7

typedef vector<vector<int>> Graph; // Adjacency Matrix

Graph allPairShortestDistance(Graph g)
{
    int v = g.size();
    for (int via = 0; via < v; via++)
    {
        for (int i = 0; i < v; i++)
        {
            if (g[i][i] < 0)
                return {{}};
            if (i == via)
                continue;
            for (int j = 0; j < g[0].size(); j++)
            {
                if (j == via || j == i)
                    continue;
                g[i][j] = min(g[i][j], g[i][via] + g[via][j]);
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            if (g[i][j] == INF)
                g[i][j] = -1;
        }
    }
    return g;
}

int main()
{
    // Graph g = {
    //     {0, 2, INF, INF},
    //     {1, 0, 3, INF},
    //     {INF, INF, 0, INF},
    //     {3, 5, 4, 0}};
    Graph g = {
        {0, 6, 2, 4, INF},
        {INF, 0, INF, INF, INF},
        {INF, 3, 0, INF, 1},
        {INF, 1, INF, 0, INF},
        {INF, 1, INF, INF, 0}};
    auto cost = allPairShortestDistance(g);
    printMatrix(cost);

    return 0;
}