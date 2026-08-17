#include <iostream>
using namespace std;
int main() {
    int n, i, j, count;

    cout<<"Enter number of borrow records: ";
    cin>>n;

    int books[n];

   cout<<"Enter books ID's:-";
    for (i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    cout<<"books borrowed more than once are:-";

    for (i = 0; i < n; i++) {
        count = 1;

           for (j = 0; j < i; j++) {
            if (books[i] == books[j]) {
                break;
            }
        }

        if (j != i)
            continue;
        for (j = i + 1; j < n; j++) {
            if (books[i] == books[j]) {
                count++;
            }
        }

        if (count > 1) {
             cout<<books[i]<<" ";
        }
    }

    return 0;
}
