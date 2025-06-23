#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    long input;
    vector<long> towers;
    for (int i = 0; i < num; i++) {
        cin >> input;
        if (i == 0)
            towers.push_back(input);
        else {
            if (towers.back() <= input)
                towers.push_back(input);
            else {
                auto it = lower_bound(towers.begin(), towers.end(), input);
                if (*it == input) {
                    while (*it == input)
                        it++;
                    *it = input;
                } else {
                    *it = input;
                }
            }
        }
    }
    cout << towers.size() << endl;
    return 0;
}
