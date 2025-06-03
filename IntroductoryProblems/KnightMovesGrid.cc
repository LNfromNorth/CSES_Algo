#include <iostream>
#include <string.h>
using namespace std;

int xi[4] = {-1, -2, -2, -1};
int yi[4] = {-2, -1, 1, 2};
int init[6] = {0, 3, 4, 2, 1, 4};

#define IDX(x, y) ((x) * ((x) - 1) / 2 + (y) - 1)

int find(int *output, int x, int y) {
    int max = 0;
    int count = 0;
    int dcount = 0;
    for (int i = 0; i < 4; i++) {
        int xx = x + xi[i];
        int yy = y + yi[i];
        if (xx > 0 && yy > 0 && yy <= xx) {
            count++;
            if (output[IDX(xx, yy) != max])
                dcount++;

            if (output[IDX(xx, yy)] > max) {
                max = output[IDX(xx, yy)];
            }
        }
    }
    if (x == y || (count > 1 && dcount == 1))
        return max + 1;
    else
        return max - 1;
}

int main() {
    int num;
    cin >> num;
    int total = num * (num + 1) / 2;
    int *output = (int *)malloc(total * sizeof(int));
    memset(output, 0, (1 + num) / 2 * num * sizeof(int));
    memcpy(output, init, 6 * sizeof(int));
    if (num > 3) {
        for (int x = 4; x <= num; x++) {
            for (int y = 1; y <= x; y++) {
                output[IDX(x, y)] = find(output, x, y);
            }
        }
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i <= j)
                cout << output[IDX(j + 1, i + 1)];
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
