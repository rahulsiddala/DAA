#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

long long factorial(int n)
{
    if(n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    long long fact = factorial(n);

    auto stop = high_resolution_clock::now();

    double time = duration<double, milli>(stop - start).count();

    cout << "\nFactorial: " << fact;

    cout << fixed << setprecision(6);
    cout << "\nExecution Time: " << time << " milliseconds";

    cout << "\nTime Complexity: O(n)";
    cout << "\nSpace Complexity: O(n)";

    return 0;
}