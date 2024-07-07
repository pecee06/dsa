#include "../Utils/printVector.cpp"
#include <queue>
#define vacant (int)NULL

typedef vector<int> BinaryTree;

inline bool validPos(BinaryTree &t, int pos)
{
    return pos < t.size() && t[pos] != vacant;
}

void zigZagTraversal(BinaryTree &t)
{
    t.insert(t.begin(), vacant);
    vector<int> temp;
    bool leftToRight = true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int size = q.size();
        temp.resize(size);
        for (int i = 0; i < size; i++)
        {
            int nodePos = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            temp[index] = t[nodePos];
            int leftPos = 2 * nodePos;
            int rightPos = leftPos + 1;
            if (validPos(t, leftPos))
                q.push(leftPos);
            if (validPos(t, rightPos))
                q.push(rightPos);
        }
        leftToRight = !leftToRight;
        printVector(temp);
        temp.clear();
    }
}

int main()
{
    BinaryTree t = {1, 2, 3, 4, 5, vacant, 6};
    zigZagTraversal(t);

    return 0;
}