#include <iostream>
using namespace std;

int main() {
    long num;
    cin >> num;
    long count = 0;
    long ff = 5;
    while ((num / ff) >= 1) {
        count += num / ff;
        ff *= 5;
    }
    cout << count << endl;
    return 0;
}
