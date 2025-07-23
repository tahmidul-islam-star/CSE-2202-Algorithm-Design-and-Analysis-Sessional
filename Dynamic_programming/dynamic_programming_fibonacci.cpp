#include <iostream>
using namespace std;

int fib_dp(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int dp[n + 1];

    dp[0] = 0;

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int main()
{
    int n;

    cout << "Enter value of n: ";

    cin >> n;

    int result = fib_dp(n);

    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}

