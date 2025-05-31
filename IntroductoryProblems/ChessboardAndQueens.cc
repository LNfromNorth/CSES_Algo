#include <cstdint>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

int check(int level, int idx, vector<int> current) {
    for (int i = 0; i < (int)current.size(); i++) {
        if (idx == current[i])
            return 0;
        if (idx == current[i] + (level - i))
            return 0;
        if (idx == current[i] - (level - i))
            return 0;
    }
    return 1;
}

void do_algo(uint8_t *chess, vector<int> current, int level, int *count) {
    if (level == 8) {
        (*count)++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if ((chess[level] >> i) & 0x1)
            continue;
        if (check(level, i, current)) {
            current.push_back(i);
            do_algo(chess, current, level + 1, count);
            current.pop_back();
        }
    }
}

int main() {
    uint8_t chess[8] = {'\0'};
    char input;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> input;
            if (input == '*')
                chess[i] |= 1 << (7 - j);
        }
    }
    int count = 0;
    vector<int> current;
    do_algo(chess, current, 0, &count);
    cout << count << endl;
    return 0;
}
