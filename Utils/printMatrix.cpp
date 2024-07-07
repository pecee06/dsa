#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void printMatrix(Matrix &m)
{
    for (auto row : m)
    {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }
}