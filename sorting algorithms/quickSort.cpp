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

lld partition(lld arr[], lld strtIndx, lld endIndx)
{
    lld pvt = arr[strtIndx];
    lld smallerThanPvt = 0;

    for (lld i = strtIndx + 1; i <= endIndx; i++)
    {
        if (arr[i] <= pvt)
        {
            smallerThanPvt++;
        }
    }

    lld pvtIndx = strtIndx + smallerThanPvt;
    swap(arr[pvtIndx], arr[strtIndx]);

    lld i = strtIndx, j = endIndx;

    while (i < pvtIndx && j > pvtIndx)
    {
        while (arr[i] < pvt)
        {
            i++;
        }
        while (arr[j] > pvt)
        {
            j--;
        }
        if (i < pvtIndx && j > pvtIndx)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pvtIndx;
}

void quickSort(lld arr[], lld startIndx, lld endIndx)
{
    if (startIndx >= endIndx)
    {
        return;
    }

    lld p = partition(arr, startIndx, endIndx);

    quickSort(arr, startIndx, p - 1);
    quickSort(arr, p + 1, endIndx);
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

    quickSort(arr, 0, arrSz - 1);

    print(arr, arrSz);

    return 0;
}