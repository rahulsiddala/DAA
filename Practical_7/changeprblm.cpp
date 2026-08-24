#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coin(n);

    cout << "Enter coin values:\n";
    for(int i = 0; i < n; i++)
        cin >> coin[i];

    cout << "Enter amount: ";
    cin >> amount;

    vector<int> dp(amount + 1);

    auto start = high_resolution_clock::now();

    for(int r = 0; r < 100000; r++)
    {
        fill(dp.begin(), dp.end(), amount + 1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
            for(int c : coin)
            {
                if(c <= i)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    auto stop = high_resolution_clock::now();

    double time = duration<double, milli>(stop - start).count();

    cout << "\nMinimum coins: " << dp[amount];

    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";

    cout << "\nTime Complexity: O(n * amount)";

    return 0;
}