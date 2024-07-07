#include <iostream>
#include <algorithm>
#include <numeric>
#define INF (int)1e7
using namespace std;

int minPressureOnStudent(int pages[], int n, int students)
{
    // pressure on student is the max pages that one is allocated with, among the group
    int low = *max_element(pages, pages + n);
    int high = accumulate(pages, pages + n, 0);
    int ans = INF;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool studentsExceeded = false;
        int requiredStudents = 1, val = 0;
        for (int i = 0; i < n; i++)
        {
            val += pages[i];
            if (val > mid)
            {
                requiredStudents++;
                val = pages[i];
            }
            if (requiredStudents > students)
            {
                low = mid + 1;
                studentsExceeded = true;
                break;
            }
        }
        if (!studentsExceeded)
        {
            if (requiredStudents == students)
                ans = min(ans, mid);
            high = mid - 1;
        }
    }
    if (ans == INF)
        return -1;
    return ans;
}

int main()
{
    int pages[] = {25, 46, 28, 49, 24};
    int n = sizeof(pages) / sizeof(pages[0]);
    int students;
    cin >> students;
    cout << minPressureOnStudent(pages, n, students);

    return 0;
}