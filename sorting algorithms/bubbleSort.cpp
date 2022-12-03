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
    lld arrSz;
    cin >> arrSz;
    lld arr[arrSz];

    for (lld i = 0; i < arrSz; i++)
    {
        cin >> arr[i];
    }

    for (lld i = 0; i < arrSz - 1; i++)
    {
        for (lld j = 0; j < arrSz - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }

    print(arr, arrSz);

    return 0;
}