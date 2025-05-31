#include <iostream>
#include <math.h>
using namespace std;

void find_min(long *list, int idx, int size, long half, long current,
              long *min) {
    for (int i = idx; i < size; i++) {
        long c = abs(current + list[i] - half);
        long cmin = abs(*min - half);
        if (c < cmin) {
            *min = current + list[i];
        }
        if (current + list[i] < half)
            find_min(list, i + 1, size, half, current + list[i], min);
    }
    return;
}

int main() {
    int nums;
    cin >> nums;
    long weights[nums];
    long total = 0;
    for (int i = 0; i < nums; i++) {
        cin >> weights[i];
        total += weights[i];
    }
    long half = total / 2;
    // sort
    for (int i = nums - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (weights[j] < weights[j + 1]) {
                long tmp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tmp;
            }
        }
    }
    long result = total;
    find_min(weights, 0, nums, half, 0, &result);
    long out = abs((total - result) - result);
    cout << out << endl;
    return 0;
}
