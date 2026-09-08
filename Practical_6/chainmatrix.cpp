#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <climits>
using namespace std;
using namespace chrono;
int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions: ";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    auto start = high_resolution_clock::now();

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for(int k = i; k < j; k++)
            {
                long long cost = dp[i][k] + dp[k + 1][j]
                    + 1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    auto stop = high_resolution_clock::now();
    double time = duration<double, milli>(stop - start).count();
    cout << "\nMinimum Multiplications: " << dp[1][n];
    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";
    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(n^3)";
    cout << "\nAverage Case : O(n^3)";
    cout << "\nWorst Case   : O(n^3)";
    return 0;
}