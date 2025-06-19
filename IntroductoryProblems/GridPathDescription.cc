#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int level;
    uint8_t grid[49];
    int x;
    int y;

    node(int l, const uint8_t *g, int x_, int y_) : level(l), x(x_), y(y_) { std::copy(g, g + 49, grid); }
};

void move(node &nd, char direction) {
    switch (direction) {
    case 'U':
        nd.y -= 1;
        break;
    case 'D':
        nd.y += 1;
        break;
    case 'R':
        nd.x += 1;
        break;
    case 'L':
        nd.x -= 1;
        break;
    default:
        return;
    }
    nd.grid[nd.y * 7 + nd.x] = 1;
    return;
}

int BFSearch(string input) {
    queue<node> q;
    uint8_t grid[49] = {1, 0};
    node first(0, grid, 0, 0);
    q.push(first);
    int count = 0;
    while (!q.empty()) {
        node current = q.front();
        q.pop();
        // get right answer
        if (current.level == (int)input.size() && current.x == 0 && current.y == 6) {
            count++;
        }
        if (input[current.level] != '?') { // if have a default value, set the path to default value
            node next(current.level + 1, current.grid, current.x, current.y);
            move(next, input[current.level]);
            if (next.x >= 0 && next.x <= 6 && next.y >= 0 && next.y <= 6)
                q.push(next);
            continue;
        } else { // if no default value, just try all possiable value
            if (current.x - 1 >= 0 && current.grid[current.y * 7 + current.x - 1] == 0) {
                node next(current.level + 1, current.grid, current.x - 1, current.y);
                next.grid[next.y * 7 + next.x] = 1;
                q.push(next);
            }
            if (current.x + 1 <= 6 && current.grid[current.y * 7 + current.x + 1] == 0) {
                node next(current.level + 1, current.grid, current.x + 1, current.y);
                next.grid[next.y * 7 + next.x] = 1;
                q.push(next);
            }
            if (current.y - 1 >= 0 && current.grid[(current.y - 1) * 7 + current.x] == 0) {
                node next(current.level + 1, current.grid, current.x, current.y - 1);
                next.grid[next.y * 7 + next.x] = 1;
                q.push(next);
            }
            if (current.y + 1 <= 6 && current.grid[(current.y + 1) * 7 + current.x] == 0) {
                node next(current.level + 1, current.grid, current.x, current.y + 1);
                next.grid[next.y * 7 + next.x] = 1;
                q.push(next);
            }
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    int count = BFSearch(input);
    cout << count << endl;
    return 0;
}
