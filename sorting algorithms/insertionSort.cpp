#include <iostream>

using namespace std;

typedef long long int lld;

void print(lld arr[], lld arrSz)
{
    for (lld i = 0; i < arrSz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    lld n;
    cin >> n;
    lld arr[n];
    for (lld i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (lld i = 1; i < n; i++)
    {
        lld temp = arr[i];
        lld j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    print(arr, n);
    return 0;
}