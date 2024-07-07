#include "../../Utils/printMatrix.cpp"

void setMatrixZeroes(Matrix &m)
{ // O(n^2)
    int n = m.size();
    // Using 1st row as container to store cols which are to be made 0
    // Using 1st col as container to store rows which are to be made 0
    bool row0 = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!m[i][j])
            {
                if (i == 0)
                    row0 = true;
                else
                    m[i][0] = 0;
                m[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (!m[0][i])
        {
            for (int j = 1; j < n; j++)
                m[j][i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (!m[i][0])
        {
            for (int j = 1; j < n; j++)
                m[i][j] = 0;
        }
    }

    if (!m[0][0])
    {
        for (int i = 1; i < n; i++)
            m[i][0] = 0;
    }
    if (row0)
    {
        for (int i = 0; i < n; i++)
            m[0][i] = 0;
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
