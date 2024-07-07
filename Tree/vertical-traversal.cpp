#include "../Utils/BinaryTree.cpp"
#include "../Utils/printMatrix.cpp"
#include <map>
#include <set>

typedef map<int, map<int, multiset<int>>> DS;

struct Tuple
{
    Node *node;
    int x, y;
};

Matrix verticalTraversal(Node *root)
{
    DS structure;
    queue<Tuple> q;
    q.push({root, 0, 0});
    while (!q.empty())
    {
        auto elem = q.front();
        q.pop();
        structure[elem.x][elem.y].insert(elem.node->data);
        if (elem.node->leftChild)
            q.push({elem.node->leftChild, elem.x - 1, elem.y + 1});
        if (elem.node->rightChild)
            q.push({elem.node->rightChild, elem.x + 1, elem.y + 1});
    }
    Matrix ans;
    for (auto i : structure)
    {
        vector<int> column;
        for (auto j : i.second)
            column.insert(column.end(), j.second.begin(), j.second.end());
        ans.push_back(column);
    }
    return ans;
}

int main()
{
    BinaryTree t;
    t.build();
    auto m = verticalTraversal(t.getRoot());
    printMatrix(m);

    return 0;
}
