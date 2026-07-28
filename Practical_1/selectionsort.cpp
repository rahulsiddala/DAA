#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = high_resolution_clock::now();

    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(n²)";
    cout << "\nAverage Case : O(n²)";
    cout << "\nWorst Case   : O(n²)";

    return 0;
}