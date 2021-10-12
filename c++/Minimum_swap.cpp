//by me
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void display(vector<int> v)
{
    for (auto x : v)
        cout << x << " ";
    cout << "\n";
}
int right_index(vector<int> sorted, int l, int r, int num)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (sorted[mid] == num)
            return mid;
        else if (sorted.at(mid) < num)
            return right_index(sorted, mid + 1, r, num);
        else
            return right_index(sorted, 0, mid - 1, num);
    }
    return -1;
}
int solve(vector<int> a)
{
    vector<int> sorted = a;

    sort(sorted.begin(), sorted.end());
    display(sorted);
    int swap_count = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        int j = right_index(sorted, 0, sorted.size() - 1, a.at(i));
        if (j != i)
        {
            swap(a.at(i), a.at(j));
            swap_count++;
            --i;
        }
    }
    return swap_count;
}
int main()
{
    vector<int> a = {
        10, 11, 5, 4, 3, 2, 1};
    cout << solve(a);
    return 0;
}
