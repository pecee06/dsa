#include "../Utils/List.cpp"

typedef pair<Node *, Node *> Tuple;

inline void fillTuple(Tuple &t, Node *n)
{
    if (!t.first)
        t = {n, n};
    else
    {
        t.second->next = n;
        t.second = n;
    }
}

Node *sortList(Node *head)
{
    vector<Tuple> v(3, {nullptr, nullptr});
    // first -> start, second -> end
    while (head)
    {
        if (head->data == 0)
            fillTuple(v[0], head);
        else if (head->data == 1)
            fillTuple(v[1], head);
        else
            fillTuple(v[2], head);
        head = head->next;
    }
    v[0].second->next = v[1].first;
    v[1].second->next = v[2].first;
    v[2].second->next = nullptr;
    return v[0].first;
}

int main()
{
    vector<int> v = {1, 0, 1, 2, 0, 2, 1};
    List l(v);
    l.setHead(sortList(l.getHead()));
    l.print();

    return 0;
}
