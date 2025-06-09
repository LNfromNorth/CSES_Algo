#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int glist(vector<pair<char, int>> &str, char before, vector<char> &result,
          int length) {
    if (length == (int)str.size())
        return 1;
    for (auto it = str.begin(); it < str.end(); it++) {
        if ((*it).second == 1 || (*it).first == before)
            continue;
        (*it).second = 1;
        result.push_back((*it).first);
        if (glist(str, (*it).first, result, length + 1)) {
            return 1;
        } else {
            result.pop_back();
            (*it).second = 0;
        }
    }
    return 0;
}

int glistBFS(vector<pair<char, int>> &str, vector<char> &result) {}

int main() {
    string input;
    cin >> input;
    vector<pair<char, int>> instr;
    vector<char> result;
    for (char c : input) {
        instr.emplace_back(c, 0);
    }
    sort(instr.begin(), instr.end());
    int ret = glist(instr, '\0', result, 0);
    if (ret) {
        for (char ch : result) {
            cout << ch;
        }
    } else {
        cout << "-1";
    }
    cout << endl;
    return 0;
}
