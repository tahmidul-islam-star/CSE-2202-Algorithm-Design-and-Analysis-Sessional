#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> coins;

int greedyCoinChange(int V) {

    sort(coins.rbegin(), coins.rend());

    int count = 0;

    for (int coin : coins) {

        while (V >= coin) {

            V -= coin;

            count++;
        }
    }
    if (V == 0) return count;

    else return -1;
}
int main() {

    int n, V; cin >> n;

    coins.resize(n);

    for (int i = 0; i < n; i++) cin >> coins[i];

    cin >> V;

    int result = greedyCoinChange(V);

    if (result != -1) cout << result << endl;

    else cout << -1 << endl;

    return 0;
}

