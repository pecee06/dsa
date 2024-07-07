#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph; // Lower Triangular Shaped Matrix

int provinces(Graph &lowerTriangle)
{
    // O(n^2)
    // Works for undirected graphs
    int n = lowerTriangle.size();
    vector<int> parent(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (lowerTriangle[i][j])
                parent[j + i + 1] = i;
        }
    }
    int count = 0;
    for (auto it : parent)
    {
        if (it == -1)
            count++;
    }
    return count;
}

int main()
{
    Graph lowerTriangle = {
        {1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0},
        {0, 0},
        {1}};
    cout << provinces(lowerTriangle);

    return 0;
}