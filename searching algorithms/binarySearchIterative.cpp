#include <iostream>

using namespace std;

typedef long long lld;

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

    lld mid, left, right;
    left = 0;
    right = arrSz - 1;

    bool numberFound = false;

    while (right >= left)
    {
        mid = left + ((right - left) / 2);
        if (arr[mid] == theNum)
        {
            numberFound = true;
            cout << "Number found at " << mid + 1 << " no. index (1 based indexing.)" << endl;
            break;
        }
        else if (arr[mid] < theNum)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!numberFound)
    {
        cout << "Number is't present in the array." << endl;
    }

    return 0;
}