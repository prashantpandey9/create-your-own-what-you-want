#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void display(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}
int solve(vector<int> arr)
{
    int sum = 0, end = 0;
    int n = arr.size(), max_sum = INT_MIN;
    while (end < n)
    {
        sum += arr[end];
        if (sum <= arr[end])
        {
            sum = arr[end];
        }
        if (sum < 0)
            sum = 0;
        max_sum = max(max_sum, sum);
        ++end;
    }
    return max_sum;
}
int main()
{
    vector<int> arr = {-2, -3, -4};
    int res = solve(arr);
    cout << res;
    return 0;
}
