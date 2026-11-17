#include <bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, vector<vector<int>>& cost,
        vector<vector<int>>& dp, int n)
{
    if(mask == (1 << n) - 1)
        return cost[pos][0];

    if(dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for(int city = 0; city < n; city++)
    {
        if((mask & (1 << city)) == 0)
        {
            int newCost = cost[pos][city] +
                tsp(mask | (1 << city), city, cost, dp, n);

            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int minimumCost = tsp(1, 0, cost, dp, n);

    cout << "\nMinimum Travel Cost: " << minimumCost;

    return 0;
}