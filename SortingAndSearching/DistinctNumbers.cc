#include <iostream>
#include <set>
using namespace std;

int main() {
    int nums;
    cin >> nums;
    long input[nums];
    for (int i = 0; i < nums; i++) {
        cin >> input[i];
    }
    // for (int i = nums - 1; i > 0; i--) {
    //     for (int j = 0; j < i; j++) {
    //         if (input[j] > input[j + 1]) {
    //             long tmp = input[j];
    //             input[j] = input[j + 1];
    //             input[j + 1] = tmp;
    //         }
    //     }
    // }
    set<int> s;
    for (int i = 0; i < nums; i++) {
        s.insert(input[i]);
    }
    long count = s.size();
    cout << count << endl;
    return 0;
}
