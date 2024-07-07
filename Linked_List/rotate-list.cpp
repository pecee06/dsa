#include "../Utils/List.cpp"

void rotate(List &l, int k)
{
    if (l.empty())
        return;
    Node *head, *leader;
    head = leader = l.getHead();
    int n = l.size(); // n
    if (n == 1)
        return;
    k = k % n;
    for (int i = 0; i < k; i++) // k
        leader = leader->next;
    if (!leader)
        return;
    auto follower = head;
    while (leader->next) // n-k-1
    {
        follower = follower->next;
        leader = leader->next;
    }
    leader->next = head;
    head = follower->next;
    follower->next = nullptr;
    l.setHead(head);
}

int main()
{
    vector<pair<vector<int>, int>> m = {
        {{1, 2, 3, 4, 5}, 2},
        {{1, 2, 3, 4, 5, 6}, 21967},
        {{}, 5},
        {{1, 2, 3, 4}, 0},
        {{1, 2, 3, 4}, 1},
        {{}, 0}};

    for (auto p : m)
    {
        List l(p.first);
        rotate(l, p.second);
        if (l.empty())
            cout << "NA\n";
        else
            l.print();
    }

    return 0;
}
