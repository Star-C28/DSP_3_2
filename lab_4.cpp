
/* Problem 04: Amplitude scaling.
 * Logic: y[i] = x[i] * factor.
 */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
    int x_size, i;
    float x[MAX], y[MAX], factor;

    cout << "Enter number of samples of signal: ";
    cin >> x_size;

    if (x_size < 1 || x_size > MAX) {
        return 1;
    }

    cout << "Enter the samples of signal:\n";
    for (i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        cin >> x[i];
    }

    cout << "Enter the amplitude factor: ";
    cin >> factor;

    for (i = 0; i < x_size; i++) {
        y[i] = x[i] * factor;
    }

    cout << fixed << setprecision(2);

    cout << "\nOriginal signal samples: ";
    for (i = 0; i < x_size; i++)
        cout << x[i] << " ";

    cout << "\nResultant signal samples after amplitude scaling: ";
    for (i = 0; i < x_size; i++)
        cout << y[i] << " ";

    cout << endl;

    return 0;
}
