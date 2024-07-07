#include "../Utils/printMatrix.cpp"
#include <algorithm>

void transpose(Matrix &m, int n)
{
    for (int row = 0; row < n - 1; row++)
    {
        for (int col = row + 1; col < n; col++)
            swap(m[row][col], m[col][row]);
    }
}

void mirrorVertically(Matrix &m, int n)
{
    for (int i = 0; i < n; i++)
        reverse(m[i].begin(), m[i].end());
}

void rotateBy90Deg(Matrix &m)
{ // O(n^2)
    int n = m.size();
    transpose(m, n);
    mirrorVertically(m, n);
}

int main()
{
    Matrix m = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    rotateBy90Deg(m);
    printMatrix(m);

    return 0;
}