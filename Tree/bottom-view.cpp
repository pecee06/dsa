#include "../Utils/BinaryTree.cpp"
#include <map>

typedef pair<int, int> PII;
typedef map<int, PII> DS;

struct Tuple
{
    Node *node;
    int x, y;
};

void bottomView(Node *root)
{
    DS structure;
    queue<Tuple> q;
    q.push({root, 0, 0});
    while (!q.empty())
    {
        auto elem = q.front();
        q.pop();
        if (structure.find(elem.x) != structure.end())
        {
            if (elem.y >= structure[elem.x].first)
                structure[elem.x] = {elem.y, elem.node->data};
        }
        else
            structure[elem.x] = {elem.y, elem.node->data};
        if (elem.node->leftChild)
            q.push({elem.node->leftChild, elem.x - 1, elem.y + 1});
        if (elem.node->rightChild)
            q.push({elem.node->rightChild, elem.x + 1, elem.y + 1});
    }
    for (auto i : structure)
        cout << i.second.second << " ";
}

int main()
{
    BinaryTree t;
    t.build();
    bottomView(t.getRoot());

    return 0;
}
