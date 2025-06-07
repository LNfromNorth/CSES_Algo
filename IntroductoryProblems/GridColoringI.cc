#include <iostream>
#include <set>
#include <vector>
using namespace std;

int m = 0;
int n = 0;

int ox[4] = {-1, 0};
int oy[4] = {0, -1};

const vector<char> allChars = {'A', 'B', 'C', 'D'};

#define IDX(y, x, len) ((y - 1) * len + (x - 1))

char check(vector<char> &grid, int y, int x) {
    // set<char> sall;
    set<char> sbefore;
    // sall.insert(grid[IDX(y, x, n)]);
    sbefore.insert(grid[IDX(y, x, n)]);
    for (int i = 0; i < 2; i++) {
        int yy = y + oy[i];
        int xx = x + ox[i];
        if (xx > 0 && xx <= n && yy > 0 && yy <= m) {
            sbefore.insert(grid[IDX(yy, xx, n)]);
        }
    }
    for (char c : allChars) {
        if (sbefore.find(c) == sbefore.end()) {
            return c;
        }
    }
    return '\0';
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
            grid[IDX(i, j, n)] = check(grid, i, j);
            cout << grid[IDX(i, j, n)];
        }
        cout << endl;
    }
    return 0;
}
