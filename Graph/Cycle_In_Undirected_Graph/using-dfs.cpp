#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Adjacency List
typedef pair<int, int> PII;

bool hasCycle(Graph &g)
{ // T = O(v+e); S = O(v)
    unordered_set<int> visitedNodes;
    stack<PII> s; // first -> node, second -> parent
    s.push({0, -1});
    while (!s.empty())
    {
        auto elem = s.top();
        s.pop();
        visitedNodes.insert(elem.first);
        for (auto it : g[elem.first])
        {
            if (it != elem.second)
            {
                if (visitedNodes.count(it))
                    return true;
                else
                    s.push({it, elem.first});
            }
        }
    }
    return false;
}

int main()
{
    Graph g = {
        {1, 2},
        {0, 4},
        {0, 3},
        {2},
        {1, 6},
        {6},
        {4, 5}};

    cout << hasCycle(g);

    return 0;
}