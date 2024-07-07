#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List

void bfs(Graph &g)
{ // T = O(v+e); S = O(v)
    unordered_set<int> visitedNodes;
    visitedNodes.insert(0);
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto it : g[node])
        {
            if (!visitedNodes.count(it))
            {
                q.push(it);
                visitedNodes.insert(it);
            }
        }
    }
}

int main()
{
    Graph g = {
        {1, 5},
        {0, 2, 3},
        {1},
        {1, 4},
        {3, 6},
        {0, 6, 7},
        {4, 5},
        {5}};
    bfs(g);

    return 0;
}