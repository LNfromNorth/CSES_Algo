#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct State {
    vector<pair<char, int>> str;
    vector<char> result;
    char lastChar;

    State(vector<pair<char, int>> s, vector<char> r, char last) : str(s), result(r), lastChar(last) {}
};

int glist(vector<pair<char, int>> &str, char before, vector<char> &result, int length) {
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

int glistDFS(vector<pair<char, int>> &str, char before, vector<char> &result, int length) {
    if (length == (int)str.size())
        return 1;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i].second == 1 || str[i].first == before)
            continue;
        str[i].second = 1;
        result.push_back(str[i].first);
        if (glist(str, str[i].first, result, length + 1)) {
            return 1;
        }
        result.pop_back();
        str[i].second = 0;
    }
    return 0;
}

int glistBFS(vector<pair<char, int>> &str, vector<char> &result) {
    queue<State> q;
    q.push(State(str, vector<char>(), '\0'));

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if ((int)current.result.size() == (int)str.size()) {
            result = current.result;
            return 1;
        }

        for (int i = 0; i < (int)current.str.size(); i++) {
            if (current.str[i].second == 1 || current.str[i].first == current.lastChar)
                continue;

            State newState = current;
            newState.str[i].second = 1;
            newState.result.push_back(current.str[i].first);
            newState.lastChar = current.str[i].first;

            q.push(newState);
        }
    }

    return 0;
}

string greedySolution(string s) {
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int oddCount = 0;
    for (auto &p : freq) {
        if (p.second % 2 == 1)
            oddCount++;
    }

    if (oddCount > (int)(s.length() + 1) / 2) {
        return "-1";
    }

    string result;
    char lastChar = '\0';

    while (result.length() < s.length()) {
        bool found = false;

        char nextChar = '\0';
        int maxFreq = 0;

        for (auto &p : freq) {
            if (p.second > 0 && p.first != lastChar && p.second > maxFreq) {
                maxFreq = p.second;
                nextChar = p.first;
                found = true;
            }
        }

        if (!found) {
            return "-1";
        }

        result += nextChar;
        freq[nextChar]--;
        if (freq[nextChar] == 0) {
            freq.erase(nextChar);
        }
        lastChar = nextChar;
    }
    return result;
}

const int maxN = 1e6 + 5;

int freq[26];
char S[maxN], ans[maxN];

bool possible(int current) {
    int mode = 0, total = 0;
    for (int c = 0; c < 26; c++) {
        if (freq[mode] < freq[c])
            mode = c;
        total += freq[c];
    }
    return (freq[mode] <= (total + 1) / 2) && (freq[current] <= total / 2);
}

int solution(string input) {
    strncpy(S, input.c_str(), maxN - 1);
    for (int i = 0; i < (int)input.length(); i++)
        freq[(int)(S[i] - 'A')]++;

    int lastChar = -1;
    for (int i = 0; i < (int)(input.length()); i++) {
        bool filled = false;
        for (int c = 0; c < 26 && !filled; c++) {
            if (freq[c] > 0 && c != lastChar) {
                freq[c]--;
                if (possible(c)) {
                    ans[i] = (char)(c + 'A');
                    lastChar = c;
                    filled = true;
                } else
                    freq[c]++;
            }
        }
        if (!filled) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 1;
}

int main() {
    string input;
    cin >> input;
    vector<pair<char, int>> instr;
    vector<char> result;
    for (char c : input) {
        instr.emplace_back(c, 0);
    }
    sort(instr.begin(), instr.end());

    // int ret = glistBFS(instr, result);
    // int ret = glistDFS(instr, '\0', result, 0);
    // if (ret) {
    //     for (char ch : result) {
    //         cout << ch;
    //     }
    // } else {
    //     cout << "-1";
    // }
    // cout << endl;
    // cout << greedySolution(input) << endl;
    solution(input);
    return 0;
}
