
/* Problem 05: Even and odd components of a discrete-time signal.
 * Logic: xe[n] = (x[n] + x[-n])/2; xo[n] = (x[n] - x[-n])/2.
 */

#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int sample_at(const int x[], int ns, int ne, int n) {
    if (n < ns || n > ne)
        return 0;

    return x[n - ns];
}

int main() {
    int x_size, i, org, ns, ne, L, n;
    int x[MAX];

    double xe[2 * MAX - 1] = {0};
    double xo[2 * MAX - 1] = {0};

    cout << "Enter number of samples of signal: ";
    cin >> x_size;

    if (x_size < 1 || x_size > MAX)
        return 1;

    cout << "Enter the samples of signal:\n";
    for (i = 0; i < x_size; i++) {
        cout << "Enter sample: ";
        cin >> x[i];
    }

    cout << "Enter the sample no. which is the origin (1 to "
         << x_size << "): ";
    cin >> org;

    if (org < 1 || org > x_size)
        return 1;

    ns = -(org - 1);
    ne = ns + x_size - 1;

    L = (-ns > ne) ? -ns : ne;

    for (n = -L; n <= L; n++) {
        xe[n + L] = (sample_at(x, ns, ne, n)
                   + sample_at(x, ns, ne, -n)) / 2.0;

        xo[n + L] = (sample_at(x, ns, ne, n)
                   - sample_at(x, ns, ne, -n)) / 2.0;
    }

    cout << "\nOriginal signal:\n";
    for (i = 0; i < x_size; i++)
        cout << "x[" << ns + i << "] = " << x[i] << endl;

    cout << fixed << setprecision(1);

    cout << "\nEven component:\n";
    for (n = -L; n <= L; n++)
        cout << "xe[" << n << "] = " << xe[n + L] << endl;

    cout << "\nOdd component:\n";
    for (n = -L; n <= L; n++)
        cout << "xo[" << n << "] = " << xo[n + L] << endl;

    cout << "\nVerification (xe + xo = x):\n";
    for (n = -L; n <= L; n++) {
        cout << "n=" << n << " : "
             << xe[n + L] << " + "
             << xo[n + L] << " = "
             << xe[n + L] + xo[n + L] << endl;
    }

    return 0;
}
