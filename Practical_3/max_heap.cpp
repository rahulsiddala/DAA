#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && a[l] > a[largest])
        largest = l;

    if(r < n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    auto start = high_resolution_clock::now();

    buildMaxHeap(a, n);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nMax Heap: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n\nExecution Time: "
         << duration.count() << " nanoseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(n)";
    cout << "\nAverage Case : O(n)";
    cout << "\nWorst Case   : O(n)";

    return 0;
}