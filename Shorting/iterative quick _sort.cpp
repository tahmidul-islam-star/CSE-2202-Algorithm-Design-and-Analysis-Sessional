#include<iostream>
using namespace std;

int arra[7] = {3, 2, 1, 0, 2, 5, 7};

void Traverse()
{
    for(int i = 0; i < 7; i++)
    {
        cout << arra[i] << " ";
    }
    cout << endl;
}
int Partition(int low, int high)
{
    int pivot = arra[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arra[j] < pivot)
        {
            swap(arra[i], arra[j]);

            i++;
        }
    }
    swap(arra[i], arra[high]);

    return i;
}
void quicksort(int low, int high)
{
    int size = high - low + 1;

    int stack[1000];

    int top = -1;

    stack[++top] = low;

    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];

        low = stack[top--];

        int p = Partition(low, high);

        if (p - 1 > low)
        {
            stack[++top] = low;

            stack[++top] = p - 1;
        }
        if (p + 1 < high)
        {
            stack[++top] = p + 1;

            stack[++top] = high;
        }
    }
}
int main()
{
    int low = 0;
    int high = 6;

    quicksort(low, high);

    Traverse();

    return 0;
}

