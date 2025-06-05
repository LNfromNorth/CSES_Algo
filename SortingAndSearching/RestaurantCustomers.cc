#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> start(num);
    vector<int> end(num);
    for (int i = 0; i < num; i++) {
        cin >> start[i];
        cin >> end[i];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int ptr_s = 0;
    int ptr_e = 0;
    int max = 0;
    int current = 0;
    while (ptr_s < num) {
        if (start[ptr_s] < end[ptr_e]) {
            current++;
            ptr_s++;
        } else if (start[ptr_s] == end[ptr_e]) {
            ptr_s++;
            ptr_e++;
        } else {
            current--;
            ptr_e++;
        }
        if (current > max)
            max = current;
    }
    cout << max << endl;
    return 0;
}
