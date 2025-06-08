#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int calc(long position) {
    int length = 1;
    long stage = 9;
    long base = 1;
    while (position > (stage * length)) {
        position -= stage * length;
        stage *= 10;
        base *= 10;
        length++;
    }
    long number = base + (position - 1) / length;
    long remainder =
        length - ((position % length == 0) ? length : position % length);
    while (remainder > 0) {
        number /= 10;
        remainder--;
    }
    long result = number % 10;
    return result;
}

int main() {
    int num;
    cin >> num;
    vector<long> array(num);
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < num; i++) {
        cout << calc(array[i]) << endl;
    }
}
