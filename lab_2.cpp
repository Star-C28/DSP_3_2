/* Problem 02: Addition of two discrete-time signals.
 * Logic: pad shorter signal with zeros, then add sample-by-sample.
 */
#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
    int x_size, y_size, z_size, i;
    int x[MAX] = {0}, y[MAX] = {0}, z[MAX] = {0};

    cout << "Enter number of samples of first signal: ";
    cin >> x_size;

    cout << "Enter number of samples of second signal: ";
    cin >> y_size;

    if (x_size < 1 || x_size > MAX ||
        y_size < 1 || y_size > MAX) {
        return 1;
    }

    if (x_size > y_size)
        z_size = x_size;
    else
        z_size = y_size;

    cout << "Enter the samples of first signal:\n";
    for (i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        cin >> x[i];
    }

    cout << "Enter the samples of second signal:\n";
    for (i = 0; i < y_size; i++) {
        cout << "Enter sample: ";
        cin >> y[i];
    }

    for (i = 0; i < z_size; i++) {
        z[i] = x[i] + y[i];
    }

    cout << "\nFirst signal samples: ";
    for (i = 0; i < x_size; i++)
        cout << x[i] << " ";

    cout << "\nSecond signal samples: ";
    for (i = 0; i < y_size; i++)
        cout << y[i] << " ";

    cout << "\nResultant signal samples: ";
    for (i = 0; i < z_size; i++)
        cout << z[i] << " ";

    cout << endl;

    return 0;
}
