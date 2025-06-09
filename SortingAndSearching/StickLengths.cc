#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> input(num);
    for (int i = 0; i < num; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    long mid = input[num / 2];
    long midp = input[num / 2 + 1];
    long result1 = 0;
    long result2 = 0;
    for (int i = 0; i < num; i++) {
        result1 += abs(input[i] - mid);
        result2 += abs(input[i] - midp);
    }
    cout << ((result1 < result2) ? result1 : result2) << endl;
    return 0;
}
