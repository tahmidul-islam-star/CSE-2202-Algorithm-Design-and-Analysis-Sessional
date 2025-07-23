#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int coinRowDP(int n)
{
    if (n == 0) return 0;

    if (n == 1) return arr[0];

    dp.resize(n + 1);

    dp[0] = 0; dp[1] = arr[0];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}
int main()
{
    int n; cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxValue = coinRowDP(n);

    cout << "Maximum value collected: " << maxValue << endl;

    return 0;
}

