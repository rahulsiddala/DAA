#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    long long fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;

    auto stop = high_resolution_clock::now();

    double time = duration<double, milli>(stop - start).count();

    cout << "\nFactorial: " << fact;

    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";

    cout << "\nTime Complexity: O(n)";
    cout << "\nSpace Complexity: O(1)";

    return 0;
}