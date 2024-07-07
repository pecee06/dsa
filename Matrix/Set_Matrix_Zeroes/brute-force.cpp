#include "../../Utils/printMatrix.cpp"
#include <unordered_set>

typedef pair<unordered_set<int>, unordered_set<int>> POS;

void setMatrixZeroes(Matrix &m)
{          // T = O(n^2); S = O(n)
    POS s; // first stores row & second stores column
    int n = m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!m[i][j])
            {
                s.first.insert(i);
                s.second.insert(j);
            }
        }
    }

    for (auto it : s.first)
    {
        for (int i = 0; i < n; i++)
            m[it][i] = 0;
    }

    for (auto it : s.second)
    {
        for (int i = 0; i < n; i++)
            m[i][it] = 0;
    }
}

int main()
{
    Matrix m = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
    };

    setMatrixZeroes(m);
    printMatrix(m);

    return 0;
}