#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int calc(long position) {
    if (position <= 9) {
        return position;
    } else if (position <= 189) {
        long num = 10 + (position - 9) / 2 - ((position - 9) % 2 ? 0 : 1);
        long divisor = pow(10, (1 - position % 2));
        long bit = (num / divisor) % 10;
        cout << num << " " << divisor << " " << bit << endl;
        return bit;
    } else {
        long tmp = position - 189;
        int length = 3;
        while (tmp > (pow(10, length) * length)) {
            tmp -= pow(10, length) * length;
            length++;
        }
        long base = pow(10, length - 1);
        long num = base + (tmp - 1) / length;
        long divisor = pow(10, (length - 1 - ((tmp + 1) % length)));
        long bit = (num / divisor) % 10;
        cout << length << " " << base << " " << num << " " << divisor << " "
             << bit << endl;
        return bit;
    }
}

int main() {
    int num;
    cin >> num;
    vector<int> array(num);
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < num; i++) {
        cout << calc(array[i]) << endl;
    }
}
