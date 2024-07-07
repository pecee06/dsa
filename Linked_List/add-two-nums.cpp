// Both the nums are already in reversed order

#include "../Utils/List.cpp"

List listSum(Node *h1, Node *h2)
{
    int carry = 0;
    List result;
    while (h1 || h2 || carry)
    {
        int sum = carry;
        if (h1)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        result.pushBack(sum % 10);
        carry = sum / 10;
    }
    return result;
}

int main()
{
    vector<int> v = {3, 5};
    List num1(v);
    v = {4, 5, 9, 9};
    List num2(v);

    auto sum = listSum(num1.getHead(), num2.getHead());
    sum.print();

    return 0;
}
