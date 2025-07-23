#include <iostream>
#include <vector>

using namespace std;

vector<int> coins;
//Tahmid
int coinRowRecursive(int n)
{
    if (n <= 0) return 0;

    if (n == 1)return coins[0];

    return max(coins[n - 1] + coinRowRecursive(n - 2), coinRowRecursive(n - 1));
}
int main()
{
    int n; cin >> n;

    coins.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int maxValue = coinRowRecursive(n);

    cout << "Maximum value collected: " << maxValue << endl;

    return 0;
}

