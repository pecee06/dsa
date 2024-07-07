#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List

void dfs(Graph &g)
{ // T = O(v+e); S = O(v)
    unordered_set<int> visitedNodes;
    visitedNodes.insert(0);
    stack<int> s;
    s.push(0);
    while (!s.empty())
    {
        int node = s.top();
        cout << node << " ";
        s.pop();
        for (auto it : g[node])
        {
            if (!visitedNodes.count(it))
            {
                s.push(it);
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
    dfs(g);

    return 0;
}