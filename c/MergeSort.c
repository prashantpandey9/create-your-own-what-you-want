
// Implementation of Merge_Sort Algorithm

#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;

    int n1 = (mid - beg) + 1;

    int n2 = (end - mid);

    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
    {
        LeftArray[i] = a[beg + i];
    }

    for (int j = 0; j < n2; j++)
    {
        RightArray[j] = a[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = beg;
    // k=0;

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }

        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
}

void mergeSort(int a[], int beg, int end)
{

    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)

        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int m;
    printf("\n \n ************** MERGE_SORT ALGORITHM  *************\n");

    printf("\nEnter the No. of elements : ");
    scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = rand();
    }
    int n = sizeof(a) / sizeof(a[0]);

    printf(" \n\nThe elements before sorting :- \n ");
    display(a,n);

    printf("\n\n The elements after sorting :- \n ");

    mergeSort(a, 0, n - 1);
    display(a, n);

    return 0;
}