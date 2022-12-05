#include <iostream>

using namespace std;

typedef long long int lld;

lld binarySearch(lld arr[], lld left, lld right, lld target)
{
    if (left > right)
    {
        return -1;
    }
    lld mid = left + ((right - left) / 2);
    if (arr[mid] == target)
    {
        return mid + 1;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, right, target);
    }
    else
    {
        return binarySearch(arr, left, mid - 1, target);
    }
    return -1;
}

int main()
{
    cout << "Enter number of element in array : ";
    lld arrSz;
    cin >> arrSz;
    lld arr[arrSz];

    cout << "Insert elements : ";

    for (lld i = 0; i < arrSz; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number you wanna find : ";
    lld theNum;
    cin >> theNum;

    lld index = binarySearch(arr, 0, arrSz - 1, theNum);

    if (index == -1)
    {
        cout << "Element is't presented in the array." << endl;
    }
    else
    {
        cout << "Element was found at " << index << " no. index. (1 based indexing)" << endl;
    }

    return 0;
}