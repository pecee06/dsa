#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List

bool isBipartite(Graph &g)
{
    vector<int> color(g.size(), -1);
    color[0] = 0;
    stack<int> s;
    s.push(0);
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        for (auto it : g[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                s.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

int main()
{
    // Graph g = {
    //     {1},
    //     {0, 2, 5},
    //     {1, 3},
    //     {2, 4, 6},
    //     {3, 5},
    //     {1, 4},
    //     {3, 7},
    //     {6},
    // };
    Graph g = {
        {1},
        {0, 2},
        {1, 3, 8},
        {2, 4},
        {3, 5},
        {4, 6, 9},
        {5, 7},
        {6},
        {2, 9},
        {5, 8},
    };
    cout << isBipartite(g);

    return 0;
}