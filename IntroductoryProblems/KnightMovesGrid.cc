#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int xi[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int yi[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

#define IDX(x, y, len) ((y - 1) * len + (x - 1))

void find(vector<int> &grid, int x, int y, int len, int level) {
    for (int i = 0; i < 8; i++) {
        int xx = x + xi[i];
        int yy = y + yi[i];
        if (xx == 1 && yy == 1)
            continue;
        if (xx > 0 && xx <= len && yy > 0 && yy <= len) {
            if (grid[IDX(xx, yy, len)] == 0) {
                grid[IDX(xx, yy, len)] = level;
                grid[IDX(yy, xx, len)] = level;
                find(grid, xx, yy, len, level + 1);
            } else if (grid[IDX(xx, yy, len)] > level) {
                grid[IDX(xx, yy, len)] = level;
                grid[IDX(yy, xx, len)] = level;
                find(grid, xx, yy, len, level + 1);
            }
        }
    }
    return;
}

void find_BFS(vector<int> &grid, int len) {
    queue<pair<int, int>> q;
    q.push({1, 1});
    grid[IDX(1, 1, len)] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int level = grid[IDX(x, y, len)];
        for (int i = 0; i < 8; i++) {
            int xx = x + xi[i];
            int yy = y + yi[i];
            if (xx == 1 && yy == 1)
                continue;
            if (xx > 0 && xx <= len && yy > 0 && yy <= len) {
                if (grid[IDX(xx, yy, len)] == 0 ||
                    grid[IDX(xx, yy, len)] > level + 1) {
                    grid[IDX(xx, yy, len)] = level + 1;
                    grid[IDX(yy, xx, len)] = level + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    vector<int> grid(num * num, 0);
    // find(grid, 1, 1, num, 1);
    find_BFS(grid, num);
    for (int i = 0; i < (num * num); i++) {
        if (i % num == 0)
            cout << endl;
        cout << grid[i] << " ";
    }
    cout << endl;
    return 0;
}
