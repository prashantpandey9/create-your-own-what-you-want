#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    //base step/condition
    if (n == 1)
        return;

    //Perform the operation for the first pass only
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
        {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }

    //recursive call
    bubble_sort(a, n - 1);
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Unsorted array:";
    display(a, n);
    bubble_sort(a, n);
    cout << "Sorted array:";
    display(a, n);

    return 1;
}