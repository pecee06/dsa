#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List
typedef pair<int, int> PII;

bool hasCycle(Graph &g)
{ // T = O(v+e); S = O(v)
    unordered_set<int> visitedNodes;
    queue<PII> q; // first -> node, second -> parent
    q.push({0, -1});
    while (!q.empty())
    {
        auto elem = q.front();
        q.pop();
        if (visitedNodes.count(elem.first))
            return true;
        visitedNodes.insert(elem.first);
        for (auto it : g[elem.first])
        {
            if (it != elem.second && !visitedNodes.count(it))
                q.push({it, elem.first});
        }
    }
    return false;
}

int main()
{
    Graph g = {
        {1, 2},
        {0, 4},
        {0, 3, 5},
        {2},
        {1, 6},
        {2, 6},
        {4, 5}};

    cout << hasCycle(g);

    return 0;
}