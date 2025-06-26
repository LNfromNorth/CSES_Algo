#include <bits/stdc++.h>
using namespace std;

#define ll long long

int get_max(set<int> array, int *start, int *end) {
    int max = 0;
    for (set<int>::iterator it = array.begin(); it != array.end(); ++it) {
        int diff = *std::next(it) - *it;
        if (diff > max) {
            *start = *it;
            *end = *std::next(it);
            max = diff;
        }
    }
    return max;
}

void solve(ll x, vector<ll> input) {
    set<pair<ll, ll>> ranges;
    ranges.insert({0, x});
    multiset<ll> range_lengths;
    range_lengths.insert(x);

    for (ll i : input) {
        auto it = ranges.upper_bound({i, 0});
        it--;
        ll start = it->first;
        ll end = it->second;
        ranges.erase(it);
        range_lengths.erase(range_lengths.find(end - start));
        ranges.insert({start, i});
        ranges.insert({i, end});
        range_lengths.insert(i - start);
        range_lengths.insert(end - i);
        cout << *range_lengths.rbegin() << " ";
    }
    cout << endl;
}

int main() {
    ll x, n;
    cin >> x;
    cin >> n;
    vector<ll> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    solve(x, input);
    return 0;
}
