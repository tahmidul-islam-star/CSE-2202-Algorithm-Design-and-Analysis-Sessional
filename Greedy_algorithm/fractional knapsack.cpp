#include<iostream>

using namespace std;

float value[100],weight[100],ratio[100];

void sort_By_Ratio(int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(ratio[i],ratio[j]);

                swap(value[i],value[j]);

                swap(weight[i],weight[j]);
             }}}}
float fractional_knapsack(int n,int capacity)
{
    float total_val = 0;

    for(int i = 0;i<n;i++)
    {
        if(capacity >= weight[i])
        {
            capacity -= weight[i];

            total_val += value[i];
        }
        else{

            total_val += ratio[i]*capacity;

            break;
        }
    }
}
signed main()
{
    int n,capacity;

    cin>>n>>capacity;

    for(int i=0;i<n;i++)
    {
        cin>>value[i]>>weight[i];

        ratio[i] = value[i]/weight[i];
    }

    sort_By_Ratio(n);

    float max_val = fractional_knapsack(n,capacity);

    cout<<max_val<<endl;

}
