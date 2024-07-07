// A bipartite graph can't be colored with just 2 colors
// A bipartite graph must have at least 1 cycle of odd length

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List

bool isBipartite(Graph &g)
{
    vector<int> color(g.size(), -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : g[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

int main()
{
    Graph g = {
        {1},
        {0, 2, 5},
        {1, 3},
        {2, 4, 6},
        {3, 5},
        {1, 4},
        {3, 7},
        {6},
    };
    // Graph g = {
    //     {1},
    //     {0, 2},
    //     {1, 3, 8},
    //     {2, 4},
    //     {3, 5},
    //     {4, 6, 9},
    //     {5, 7},
    //     {6},
    //     {2, 9},
    //     {5, 8},
    // };
    cout << isBipartite(g);

    return 0;
}