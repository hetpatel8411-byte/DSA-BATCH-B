#include <iostream>
using namespace std;

void sortColors(int arr[], int n)
{
    int zero = 0, one = 0, two = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            zero++;
        else if(arr[i] == 1)
            one++;
        else if(arr[i] == 2)
            two++;
    }

    int index = 0;

    for(int i = 0; i < zero; i++)
        arr[index++] = 0;

    for(int i = 0; i < one; i++)
        arr[index++] = 1;

    for(int i = 0; i < two; i++)
        arr[index++] = 2;
}

int main()
{
    int n;

    cout << "Enter number of buckets: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0, 1, 2):" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sortColors(arr, n);

    cout << "Sorted colour codes: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
