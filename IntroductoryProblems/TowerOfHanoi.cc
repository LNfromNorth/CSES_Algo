#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int num, int from, int to, int tmp) {
    if (num == 0) {
        return;
    }
    hanoi(num - 1, from, tmp, to);
    cout << from << " " << to << endl;
    hanoi(num - 1, tmp, to, from);
}

int main() {
    int num;
    cin >> num;
    cout << (pow(2, num) - 1) << endl;
    hanoi(num, 1, 3, 2);
    return 0;
}
