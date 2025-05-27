#include <iostream>
using namespace std;

int main() {
    long long num;
    cin >> num;
    long long result = 1;
    long long mod = 1e9 + 7;
    while (num) {
        result = (result * 2) % (mod);
        num--;
    }
    cout << (result) << endl;
    return 0;
}
