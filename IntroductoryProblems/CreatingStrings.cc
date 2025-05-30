#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

void print_list(char *list, int *count, int lidx, int length, string a) {
    int count_copy[8];
    copy(count, count + lidx, count_copy);
    for (int i = 0; i < lidx; i++) {
        if (count_copy[i] <= 0)
            continue;
        a.push_back(list[i]);
        count_copy[i]--;
        if (length > 1) {
            print_list(list, count_copy, lidx, length - 1, a);
        } else if (length == 1) {
            cout << a << endl;
        }
        count_copy[i]++;
        a.pop_back();
    }
}

int calcu(int num) {
    int k = num;
    int ret = 1;
    while (k) {
        ret *= k;
        k--;
    }
    return ret;
}

int main() {
    string str;
    cin >> str;
    // count
    int *flag[26] = {NULL};
    char list[8] = {'\0'};
    int count[8] = {0};
    int list_idx = 0;
    for (int i = 0; i < (int)(str.length()); i++) {
        if (flag[str[i] - 'a'] == NULL) {
            list[list_idx] = str[i];
            flag[str[i] - 'a'] = &count[list_idx];
            count[list_idx] += 1;
            list_idx++;
        } else {
            *(flag[str[i] - 'a']) += 1;
        }
    }
    long total = 1;
    for (int i = 0; i < list_idx; i++) {
        total *= calcu(count[i]);
    }
    cout << (calcu(str.length()) / total) << endl;
    // sort
    for (int i = list_idx - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                char temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
                int tmp = count[j + 1];
                count[j + 1] = count[j];
                count[j] = tmp;
            }
        }
    }
    string a;
    print_list(list, count, list_idx, str.length(), a);
    return 0;
}
