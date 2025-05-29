#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    long length = str.length();
    char out_str[length + 1];
    out_str[length] = '\0';
    long flag[length] = {0};
    long i = 0;
    long out_idx = 0;
    long single = 0;
    char *cstr = &str[0];
    char reserve = '\0';
    int idx = 0;
    while (i != length) {
        if (flag[idx]) {
            idx++;
            continue;
        }
        char a = cstr[idx];
        int nidx = idx + 1;
        while (nidx < length) {
            if (cstr[nidx] != a || flag[nidx] == 1)
                nidx++;
            else
                break;
        }
        if (nidx == length) {
            if (single > 0)
                break;
            else {
                i++;
                flag[idx] = 1;
                reserve = cstr[idx];
                idx++;
                single++;
                continue;
            }
        }
        out_str[out_idx] = a;
        out_str[length - 1 - out_idx] = a;
        flag[idx] = 1;
        flag[nidx] = 1;
        idx++;
        out_idx++;
        i += 2;
    }
    if (single)
        out_str[out_idx] = reserve;
    if (i < length)
        cout << "NO SOLUTION" << endl;
    else
        cout << out_str << endl;
    return 0;
}
