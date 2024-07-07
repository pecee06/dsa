#include "../Utils/List.cpp"

void remove(List &l, int k)
{
    Node *leader, *follower;
    leader = follower = l.getHead();
    for (int i = 0; i < k; i++)
    {
        if (leader)
            leader = leader->next;
    }
    while (leader && leader->next)
    {
        follower = follower->next;
        leader = leader->next;
    }
    if (!leader)
        l.pop(nullptr);
    else
        l.pop(follower);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    List l(v);
    int k;
    cin >> k;
    remove(l, k);
    l.print();

    return 0;
}
