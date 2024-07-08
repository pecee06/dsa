#include "../Utils/printVector.cpp"
#include <algorithm>

struct Tuple
{
    int id, profit, deadline;

    bool operator<(const Tuple &t2)
    {
        if (this->profit == t2.profit)
            return this->deadline < t2.deadline;
        return this->profit > t2.profit;
    }
};

typedef vector<Tuple> VP;

vector<int> jobSchedule(VP &jobs)
{
    int maxDeadline = 0;
    for (auto it : jobs)
        maxDeadline = max(maxDeadline, it.deadline);
    vector<int> schedule(maxDeadline + 1, -1);
    sort(jobs.begin(), jobs.end());
    for (auto it : jobs)
    {
        for (int i = it.deadline; i > 0; i--)
        {
            if (schedule[i] == -1)
            {
                schedule[i] = it.id;
                break;
            }
        }
    }
    schedule.erase(schedule.begin());
    return schedule;
}

int main()
{
    VP jobs = {
        {6, 80, 2},
        {3, 70, 6},
        {4, 65, 6},
        {2, 60, 5},
        {5, 23, 4},
        {8, 23, 2},
        {1, 20, 4},
        {7, 10, 2}};
    auto s = jobSchedule(jobs);
    printVector(s);

    return 0;
}