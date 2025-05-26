#include <iostream>
using namespace std;

int main() {
    int nums;
    cin >> nums;
    int x[nums];
    int y[nums];
    for (int i = 0; i < nums; i++) {
        cin >> y[i];
        cin >> x[i];
    }
    long result;
    for (int i = 0; i < nums; i++) {
        long cx = x[i];
        long cy = y[i];
        long cycles = (cx > cy) ? cx : cy;
        long start = (cycles - 1) * (cycles - 1);
        if (cycles % 2 == 0) {
            if (cx >= cy)
                result = start + cy;
            if (cx < cy)
                result = start + (2 * cycles) - cx;
        } else {
            if (cx >= cy)
                result = start + (2 * cycles) - cy;
            if (cx < cy)
                result = start + cx;
        }
        cout << result << endl;
    }
}
