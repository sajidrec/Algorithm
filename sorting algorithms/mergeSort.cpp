#include <iostream>

using namespace std;

typedef int lld;

void print(lld arr[], lld sz)
{
    for (lld i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(lld arr[], lld left, lld mid, lld right)
{
    lld fArrSz = mid - left + 1;
    lld sArrSz = right - mid;
    lld fArr[fArrSz], sArr[sArrSz];

    for (lld i = 0; i < fArrSz; i++)
    {
        fArr[i] = arr[left + i];
    }
    for (lld i = 0; i < sArrSz; i++)
    {
        sArr[i] = arr[mid + i + 1];
    }

    lld i, j, k;
    i = j = 0;
    k = left;

    while (i < fArrSz && j < sArrSz)
    {
        if (fArr[i] >= sArr[j])
        {
            arr[k] = sArr[j];
            j++;
        }
        else
        {
            arr[k] = fArr[i];
            i++;
        }
        k++;
    }

    while (i < fArrSz)
    {
        arr[k] = fArr[i];
        k++;
        i++;
    }
    while (j < sArrSz)
    {
        arr[k] = sArr[j];
        k++;
        j++;
    }
}

void mergeSort(lld arr[], lld left, lld right)
{
    if (left >= right)
    {
        return;
    }
    lld mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{

    lld arrSz;
    cout << "Enter array size : ";
    cin >> arrSz;
    cout << "Enter array elements : ";
    lld arr[arrSz];
    for (lld i = 0; i < arrSz; i++)
    {
        lld temp;
        cin >> temp;
        arr[i] = temp;
    }
    cout << "Before sorting : ";
    print(arr, arrSz);
    mergeSort(arr, 0, arrSz - 1);
    cout << "After sorting  : ";
    print(arr, arrSz);

    return 0;
}