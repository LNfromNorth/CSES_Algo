#include <iostream>
using namespace std;

void print_bit(long bit, long total) {
    for (int i = total - 1; i >= 0; i--) {
        char out = (bit & 1 << i) ? '1' : '0';
        cout << out;
    }
    cout << endl;
}

void resursion(long bit, long *current, long total) {
    if (bit == 0) {
        if (*current & 1 << bit) {
            *current = *current - (1 << bit);
        } else {
            *current = *current + (1 << bit);
        }
        print_bit(*current, total);
        return;
    }
    resursion(bit - 1, current, total);
    if (*current & 1 << bit) {
        *current = *current - (1 << bit);
    } else {
        *current = *current + (1 << bit);
    }
    print_bit(*current, total);
    resursion(bit - 1, current, total);
    return;
}

int main() {
    long num;
    cin >> num;
    long number = 0;
    print_bit(number, num);
    resursion(num - 1, &number, num);
}
