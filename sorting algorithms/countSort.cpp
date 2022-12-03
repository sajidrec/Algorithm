#include <iostream>
#include <climits>

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

    lld arr[arrSz], maxV = INT_MIN;

    for (lld i = 0; i < arrSz; i++)
    {
        cin >> arr[i];
        maxV = max(maxV, arr[i]);
    }

    lld hashArr[maxV + 1];

    for (lld i = 0; i < maxV + 1; i++)
    {
        hashArr[i] = 0;
    }

    for (lld i = 0; i < arrSz; i++)
    {
        hashArr[arr[i]]++;
    }

    for (lld i = 1; i < maxV + 1; i++)
    {
        hashArr[i] = hashArr[i - 1] + hashArr[i];
    }

    lld sortedArr[arrSz];

    for (lld i = arrSz - 1; i >= 0; i--)
    {
        sortedArr[hashArr[arr[i]] - 1] = arr[i];
        hashArr[arr[i]]--;
    }

    print(sortedArr, arrSz);

    return 0;
}