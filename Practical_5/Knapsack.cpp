#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> weight(n), value(n);
    cout << "Enter weights: ";
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter values: ";
    for(int i = 0; i < n; i++)
        cin >> value[i];
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    auto start = high_resolution_clock::now();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= capacity; w++)
        {
            if(weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    auto stop = high_resolution_clock::now();
    double time = duration<double, milli>(stop - start).count();
    cout << "\nMaximum Value: " << dp[n][capacity];
    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";
    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(n * capacity)";
    cout << "\nAverage Case : O(n * capacity)";
    cout << "\nWorst Case   : O(n * capacity)";
    return 0;
}