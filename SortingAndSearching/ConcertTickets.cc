#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> tickets(n);
    vector<int> customers(m);
    for (int i = 0; i < n; i++)
        cin >> tickets[i];
    for (int i = 0; i < m; i++)
        cin >> customers[i];
    multiset<int> maxPrice;
    for (int i = 0; i < n; i++)
        maxPrice.insert(tickets[i]);
    for (int i = 0; i < m; i++) {
        int current_customer = customers[i];
        auto it = maxPrice.upper_bound(current_customer);
        if (it != maxPrice.begin()) {
            it--;
            cout << *it << endl;
            maxPrice.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
