#include <iostream>

using namespace std;

typedef long long int lld;

int main()
{
    lld n;
    cout << "Enter array size : ";

    cin >> n;
    lld arr[n];

    cout << "Enter array elements : ";
    for (lld i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting : ";

    for (auto val : arr)
    {
        cout << val << " ";
    }

    cout << endl;

    // sorting algo
    for (lld i = 0; i < n; i++)
    {
        for (lld j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "After sorting : ";

    for (auto val : arr)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}