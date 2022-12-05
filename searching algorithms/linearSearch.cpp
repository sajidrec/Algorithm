#include <iostream>

using namespace std;

typedef long long int lld;

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
    cout << "Enter the number you wanna find : " << endl;
    lld theNum;
    cin >> theNum;
    bool numFound = false;
    lld i;
    for (i = 0; i < arrSz && !numFound; i++)
    {
        if (arr[i] == theNum)
        {
            numFound = true;
        }
    }
    if (numFound)
    {
        cout << "Number first occurred at " << i << " number index(1 based indexing)" << endl;
    }
    else
    {
        cout << "Number is'nt presented in the array" << endl;
    }
    return 0;
}