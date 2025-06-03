#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    cin >> x;
    vector<int> ws;
    int weight;
    for (int i = 0; i < n; i++) {
        cin >> weight;
        ws.push_back(weight);
    }
    sort(ws.begin(), ws.end());
    int nums = 0;
    int ptra = 0;
    int ptrb = n - 1;
    while (ptra <= ptrb) {
        if (ws[ptra] + ws[ptrb] <= x) {
            ptra++;
            ptrb--;
        } else {
            ptrb--;
        }
        nums++;
    }
    cout << (nums) << endl;
    return 0;
}
