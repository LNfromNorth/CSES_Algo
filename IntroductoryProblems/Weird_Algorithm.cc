#include <iostream>
using namespace std;

int main() {
    long long c;
    cin >> c;
    while(c != 1) {
        cout << c << " ";
        if(c % 2 == 1) {
            c = c * 3 + 1;
        } else {
            c = c / 2;
        }
    }
    cout << "1" << endl;
    return 0;
}