#include <bits/stdc++.h>

using namespace std;


vector<int> val;

vector<int> wt;

int knapsack(int cap) {

    vector<int> dp(cap + 1, 0);

    for (int i = 1; i <= wt.size(); i++) {

        for (int j = cap; j >= wt[i - 1]; j--) {

            dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[cap];
}
int main() {

    int n, capacity;cin >> n >> capacity;

    val.resize(n);

    wt.resize(n);

    for (int i = 0; i < n; i++) {

    cin >> val[i] >> wt[i];
    }

    cout << knapsack(capacity) << endl;

    return 0;
}
