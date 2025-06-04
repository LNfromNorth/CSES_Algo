#include <iostream>
#include <string.h>
using namespace std;

int xi[4] = {-1, -2, -2, -1};
int yi[4] = {-2, -1, 1, 2};
int init[21] = {0, 3, 4, 2, 1, 4, 3, 2, 3, 2, 2, 3, 2, 3, 4, 3, 4, 3, 4, 3, 4};

#define IDX(x, y) ((x) * ((x) - 1) / 2 + (y) - 1)

int find(int *output, int x, int y) {
    int min = 9999999;
    for (int i = 0; i < 4; i++) {
        int xx = x + xi[i];
        int yy = y + yi[i];
        if (xx > 0 && yy > 0 && yy <= xx) {
            if (output[IDX(xx, yy)] < min) {
                min = output[IDX(xx, yy)];
            }
        }
    }
    return min + 1;
}

int main() {
    int num;
    cin >> num;
    int total = num * (num + 1) / 2;
    int add = ((total - 21) > 0) ? total - 21 : 0;
    int *output = (int *)malloc((add + 21) * sizeof(int));
    memset(output, 0, (1 + num) / 2 * num * sizeof(int));
    memcpy(output, init, 21 * sizeof(int));
    if (num > 6) {
        for (int x = 7; x <= num; x++) {
            for (int y = 1; y <= x; y++) {
                output[IDX(x, y)] = find(output, x, y);
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i <= j)
                cout << output[IDX(j + 1, i + 1)] << " ";
            else
                cout << output[IDX(i + 1, j + 1)] << " ";
        }
        cout << endl;
    }
    return 0;
}
