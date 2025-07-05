#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<tuple<long, long, int>> input(num);
    vector<int> output1(num, 0), output2(num, 0);

    for (int i = 0; i < num; ++i) {
        long start, end;
        cin >> start >> end;
        input[i] = {start, end, i};
    }

    sort(input.begin(), input.end(), [](const auto &a, const auto &b) {
        if (get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    int minEnd = 2e9;
    for (int i = num - 1; i >= 0; i--) {
        if (get<1>(input[i]) >= minEnd) {
            output1[get<2>(input[i])] = 1;
        }
        minEnd = min<int>(minEnd, get<1>(input[i]));
    }

    int maxEnd = 0;
    for (int i = 0; i < num; i++) {
        if (get<1>(input[i]) <= maxEnd) {
            output2[get<2>(input[i])] = 1;
        }
        maxEnd = max<int>(maxEnd, get<1>(input[i]));
    }

    for (auto i : output1)
        cout << i << " ";
    cout << endl;
    for (auto i : output2)
        cout << i << " ";
    cout << endl;

    return 0;
}
