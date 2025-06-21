#include <iostream>
using namespace std;

#define isValid(a) (a >= 0 && a < 7 ? 1 : 0)

#define right 0
#define left 1
#define down 2
#define up 3

string str;
static bool vis[7][7] = {};
int path, step;

void DFSearch(int x, int y) {
    if (step == 48 && x == 6 && y == 0) {
        path++;
        return;
    }
    if (x == 6 && y == 0)
        return;
    if (vis[x][y] ||
        ((y >= 1 && y <= 5 && !vis[x][y + 1] && !vis[x][y - 1]) &&
         ((x == 0 && vis[x + 1][y]) || (x == 6 && vis[x - 1][y]))) ||
        ((x >= 1 && x <= 5 && !vis[x + 1][y] && !vis[x - 1][y]) &&
         ((y == 0 && vis[x][y + 1]) || (y == 6 && vis[x][y - 1]))) ||
        (x >= 1 && x <= 5 && y >= 1 && y <= 5 && vis[x - 1][y] && vis[x + 1][y] && !vis[x][y + 1] && !vis[x][y - 1]) ||
        (x >= 1 && x <= 5 && y >= 1 && y <= 5 && vis[x][y - 1] && vis[x][y + 1] && !vis[x - 1][y] && !vis[x + 1][y]))
        return;

    vis[x][y] = true;
    if (str[step] == '?') {
        if (isValid(x + 1) && !vis[x + 1][y]) { // down
            step++;
            DFSearch(x + 1, y);
            step--;
        }
        if (isValid(x - 1) && !vis[x - 1][y]) { // up
            step++;
            DFSearch(x - 1, y);
            step--;
        }
        if (isValid(y + 1) && !vis[x][y + 1]) { // right
            step++;
            DFSearch(x, y + 1);
            step--;
        }
        if (isValid(y - 1) && !vis[x][y - 1]) { // left
            step++;
            DFSearch(x, y - 1);
            step--;
        }
    } else if (str[step] == 'D' && isValid(x + 1) && !vis[x + 1][y]) { // down
        step++;
        DFSearch(x + 1, y);
        step--;
    } else if (str[step] == 'U' && isValid(x - 1) && !vis[x - 1][y]) { // up
        step++;
        DFSearch(x - 1, y);
        step--;
    } else if (str[step] == 'R' && isValid(y + 1) && !vis[x][y + 1]) { // right
        step++;
        DFSearch(x, y + 1);
        step--;
    } else if (str[step] == 'L' && isValid(y - 1) && !vis[x][y - 1]) { // left
        step++;
        DFSearch(x, y - 1);
        step--;
    }
    vis[x][y] = false;
    return;
}

int main() {
    string input;
    cin >> input;
    path = 0;
    step = 0;
    str = input;
    DFSearch(0, 0);
    cout << path << endl;
    return 0;
}
