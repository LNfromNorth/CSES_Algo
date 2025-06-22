#include <iostream>
#include <set>
#include <vector>
using namespace std;

int get_round(vector<int> &pos, vector<int> &input, pair<int, int> sw, int &breaks) {
    int a = input[sw.first - 1];
    int b = input[sw.second - 1];

    set<int> check_set;

    if (a > b)
        swap(a, b);

    check_set.insert(a - 1);
    check_set.insert(a);
    check_set.insert(a + 1);
    check_set.insert(b - 1);
    check_set.insert(b);
    check_set.insert(b + 1);

    for (int i : check_set) {
        if (i >= 1 && i < (int)pos.size() - 1) {
            breaks -= (pos[i] > pos[i + 1]);
        }
    }

    swap(input[sw.first - 1], input[sw.second - 1]);
    swap(pos[a], pos[b]);

    for (int i : check_set) {
        if (i >= 1 && i < (int)pos.size() - 1) {
            breaks += (pos[i] > pos[i + 1]);
        }
    }

    return breaks + 1;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> input(n);
    vector<int> pos(n + 1);
    vector<pair<int, int>> sw(m);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        pos[input[i]] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> sw[i].first;
        cin >> sw[i].second;
    }
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) {
            count++;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << get_round(pos, input, sw[i], count) << endl;
    }
    return 0;
}
