#include <iostream>
using namespace std;

int is_integer(double num) { return num == (double)(long long)num; }

int main() {
    long num;
    cin >> num;
    long a[num], b[num];
    for (long i = 0; i < num; i++) {
        cin >> a[i];
        cin >> b[i];
    }
    for (long i = 0; i < num; i++) {
        double x = (double)(2 * a[i] - b[i]) / 3;
        double y = (double)(2 * b[i] - a[i]) / 3;
        if ((a[i] + b[i]) % 3 == 0 && x >= 0 && y >= 0 && is_integer(x) &&
            is_integer(y))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
