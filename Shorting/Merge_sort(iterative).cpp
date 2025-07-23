#include<iostream>

using namespace std;

int arra2[1000];

//Tahmidul Islam
void print(int arra[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arra[i] << " ";
    }
    cout << endl;
}
void Merge(int arra[], int low, int mid, int high)
{
    int i = low;

    int j = mid + 1;

    int k = low;

    while(i <= mid && j <= high)
    {
        if(arra[i] < arra[j])
        {
            arra2[k++] = arra[i++];
        }
        else
        {
            arra2[k++] = arra[j++];
        }
    }
    while(i <= mid)
    {
        arra2[k++] = arra[i++];
    }
    while(j <= high)
    {
        arra2[k++] = arra[j++];
    }

    for(int i = low; i <= high; i++)
    {
        arra[i] = arra2[i];
    }
}
void iterativeMergeSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i *= 2)
    {
        for (int j = 0; j < n - 1; j += 2 * i)
        {
            int mid = min(j + i - 1, n - 1);

            int right_end = min(j + 2 * i - 1, n - 1);

            Merge(arr, j, mid, right_end);
        }
    }
}
int main()
{
    int n;cin >> n;

    int arra[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arra[i];
    }
    iterativeMergeSort(arra, n);

    cout << "Sorted array:\n";

    print(arra, n);

    return 0;
}
