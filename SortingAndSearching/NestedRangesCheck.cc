#include <bits/stdc++.h>
using namespace std;

struct node {
    long length;
    vector<int> idx;

    node(long _length) : length(_length) {}
    bool operator<(const node &other) const { return length < other.length; }
};

int main() {
    int num;
    cin >> num;
    vector<pair<long, long>> input(num);
    vector<int> output1(num, 0);
    vector<int> output2(num, 0);
    set<node> cset;
    for (int i = 0; i < num; i++) {
        cin >> input[i].first;
        cin >> input[i].second;
        long length = input[i].second - input[i].first;
        auto it = cset.upper_bound(node(length));
        if (it != cset.end()) {
            while (it != cset.end()) {
                for (int j = 0; j < (int)(*it).idx.size(); j++) {
                    long cstart = input[(*it).idx[j]].first;
                    long cend = input[(*it).idx[j]].second;
                    if (cstart <= input[i].first && cend >= input[i].second) {
                        output1[(*it).idx[j]] = 1;
                        output2[i] = 1;
                    }
                }
                it++;
            }
        }
        it = cset.upper_bound(node(length));
        if ((*it).length == length) {
            node modify = (*it);
            cset.erase(it);
            modify.idx.push_back(i);
            cset.insert(modify);
        } else {
            node nnode = node(length);
            nnode.idx.push_back(i);
            cset.insert(nnode);
        }
    }
    for (int i = 0; i < num; i++) {
        cout << output1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << output2[i] << " ";
    }
    cout << endl;
    return 0;
}
