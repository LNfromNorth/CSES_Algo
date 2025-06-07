#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<pair<int, int>> setime(num);
    for (int i = 0; i < num; i++) {
        cin >> setime[i].first;
        cin >> setime[i].second;
    }
    sort(setime.begin(), setime.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second < b.second;
         });
    int ptr = 0;
    int cend = 0;
    int count = 0;
    while (ptr < num) {
        if (setime[ptr].first >= cend) {
            cend = setime[ptr].second;
            count++;
        }
        ptr++;
    }
    cout << count << endl;
    return 0;
}
