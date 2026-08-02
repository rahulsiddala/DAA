#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    int n, key, pos = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;

    auto start = high_resolution_clock::now();

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    if(pos != -1)
        cout << "\nElement found at position " << pos + 1;
    else
        cout << "\nElement not found.";

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(1)";
    cout << "\nAverage Case : O(log n)";
    cout << "\nWorst Case   : O(log n)";

    return 0;
}