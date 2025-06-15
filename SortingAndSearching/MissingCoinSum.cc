#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long> input(num);
    for (int i = 0; i < num; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    long val = 1;
    for (auto i : input) {
        if (i > val)
            break;
        val += i;
    }
    cout << val << endl;
    return 0;
}
