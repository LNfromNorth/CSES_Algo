#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct raab {
    int n;
    int a;
    int b;
};

void print_list(vector<int> nl) {
    for (int i = 0; i < (int)nl.size(); i++)
        cout << nl[i] << " ";
    cout << endl;
}

void do_algo(struct raab item) {
    int _k = abs(item.a - item.b);
    int _2 = (item.a > item.b) ? (item.b - 1) : (item.a - 1);
    if (_k > 0 && _2 == -1) {
        cout << "NO" << endl;
        return;
    }
    _2 = (_k) ? _2 : _2 + 1;
    _k = (_k) ? _k + 2 : _k;
    int _1 = item.n - _k - 2 * _2;
    if (_1 < 0) {
        cout << "NO" << endl;
        return;
    }
    // cout << _k << " " << _2 << " " << _1 << endl;
    cout << "YES" << endl;
    vector<int> a;
    vector<int> b;
    int start = 1;
    if (_k) {
        for (int i = 2; i <= _k; i++) {
            a.push_back(i);
            b.push_back(i - 1);
        }
        a.push_back(1);
        b.push_back(_k);
        start += _k;
    }
    if (_2) {
        for (int i = 0; i < _2; i++) {
            a.push_back(start);
            a.push_back(start + 1);
            b.push_back(start + 1);
            b.push_back(start);
            start += 2;
        }
    }
    if (_1) {
        for (int i = 0; i < _1; i++) {
            a.push_back(start);
            b.push_back(start);
            start += 1;
        }
    }
    if (item.a > item.b) {
        print_list(a);
        print_list(b);
    } else {
        print_list(b);
        print_list(a);
    }
    return;
}

int main() {
    int num;
    cin >> num;
    struct raab input[num];
    for (int i = 0; i < num; i++) {
        cin >> input[i].n;
        cin >> input[i].a;
        cin >> input[i].b;
    }
    for (int i = 0; i < num; i++)
        do_algo(input[i]);
    return 0;
}
