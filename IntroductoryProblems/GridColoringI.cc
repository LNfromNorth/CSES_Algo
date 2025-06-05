#include <iostream>
#include <vector>
using namespace std;

int m = 0;
int n = 0;

int ox[4] = {0, 1, 0, -1};
int oy[4] = {1, 0, -1, 0};

#define IDX(y, x, len) ((y - 1) * len + (x - 1))

int check(vector<char> &grid, int y, int x) {
    for (int i = 0; i < 4; i++) {
        int yy = y + oy[i];
        int xx = x + ox[i];
        char max = 'A';
        if (xx > 0 && xx <= n && yy > 0 && yy <= m) {
            if (grid[IDX(yy, xx, n)] > max) {
                max = grid[IDX(yy, xx, n)];
            }
        }
    }
    return 1;
}

int main() {
    cin >> m;
    cin >> n;
    vector<char> grid(m * n);
    for (int i = 0; i < (n * m); i++) {
        cin >> grid[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
        }
    }
    return 0;
}
