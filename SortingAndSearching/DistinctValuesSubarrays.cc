#include <bits/stdc++.h>
using namespace std;

long calc(long input) {
    long ret = input * (input + 1) / 2;
    return ret;
}

void debug(vector<long> array, long start, long end) {
    for (long i = start; i <= end; i++) {
        cout << array[i] << " ";
    }
    // cout << endl;
}

int main() {
    long n;
    cin >> n;
    vector<long> input(n);
    for (long i = 0; i < n; i++) {
        cin >> input[i];
    }
    set<long> checker;
    long hidx = 0;
    long count = 0;
    long pre_len = 0;
    for (long i = 0; i < n; i++) {
        checker.insert(input[i]);
        int aft_len = checker.size();
        if (pre_len == aft_len) {
            long start = hidx;
            while (input[hidx] != input[i]) {
                checker.erase(input[hidx]);
                hidx++;
            }
            long delt = 0;
            delt += calc(i - start) - calc(i - hidx - 1);
            count += delt;
            hidx++;
        }
        pre_len = checker.size();
    }
    count += calc(n - hidx);
    cout << count << endl;
    return 0;
}
