#include <iostream>
using namespace std;

int main() {
    long num;
    cin >> num;
    for (long i = 1; i <= num; i++) {
        long size = i * i;
        if (size == 1)
            cout << 0 << endl;
        else if (size == 4)
            cout << 6 << endl;
        else if (size >= 9) {
            long result = size * (size - 1) / 2 - 4 * (i - 2) * (i - 1);
            cout << result << endl;
            ;
        }
    }
}
