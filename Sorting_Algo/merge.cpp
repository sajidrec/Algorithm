#include <iostream>

using namespace std;

typedef long long int lld;

void merge(lld arr[], lld l, lld m, lld r)
{
    lld n1 = m - l + 1;
    lld n2 = r - m;

    lld L[n1], R[n2];

    for (lld i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (lld j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    lld i = 0;

    lld j = 0;

    lld k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(lld arr[], lld l, lld r)
{
    if (l >= r)
    {
        return;
    }
    lld m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void showArray(lld A[], lld sz)
{
    for (lld i = 0; i < sz; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    lld arrSz;
    cout << "Enter array size : ";
    cin >> arrSz;
    lld arr[arrSz];
    cout << "Enter array elements : ";
    for (lld i = 0; i < arrSz; i++)
    {
        lld temp;
        cin >> temp;
        arr[i] = temp;
    }
    cout << "Given array is \n";
    showArray(arr, arrSz);
    mergeSort(arr, 0, arrSz - 1);
    cout << "\nSorted array is \n";
    showArray(arr, arrSz);
    return 0;
}