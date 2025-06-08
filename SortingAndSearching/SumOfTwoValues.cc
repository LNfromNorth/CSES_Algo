#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    cin >> x;
    vector<pair<long, long>> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i].first;
        array[i].second = i;
    }
    sort(array.begin(), array.end());
    int ptr_a = 0;
    int ptr_b = n - 1;
    while (ptr_a < ptr_b) {
        if (array[ptr_a].first + array[ptr_b].first < x) {
            ptr_a++;
        } else if (array[ptr_a].first + array[ptr_b].first > x) {
            ptr_b--;
        } else {
            cout << (array[ptr_a].second + 1) << " "
                 << (array[ptr_b].second + 1) << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
