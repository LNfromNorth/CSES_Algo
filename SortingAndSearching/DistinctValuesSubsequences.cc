#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

void distSubs(vector<int> v, int n) {
    long long ans = 1;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[v[i]]++;
    }

    for (auto it : m) {
        ans = (ans % mod * (it.second + 1) % mod) % mod;
    }

    ans = (ans - 1 + mod) % mod;

    cout << ans << endl;
}

int main() {
    long n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];

    distSubs(input, n);
    return 0;
}
