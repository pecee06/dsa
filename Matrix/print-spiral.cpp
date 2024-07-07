#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void printSpiral(Matrix &m)
{ // O(n^2)
    int left = 0, top = 0;
    int bottom = m.size() - 1;
    int right = m[0].size() - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            cout << m[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << m[i][right] << " ";
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << m[bottom][i] << " ";
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << m[i][left] << " ";
            left++;
        }
    }
}

int main()
{
    Matrix m = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10}};
    printSpiral(m);

    return 0;
}