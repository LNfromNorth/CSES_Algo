#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    long x;
    cin >> num;
    vector<long> input(num + 1);
    for (int i = 0; i < num; i++) {
        cin >> x;
        input[x] = i;
    }
    int count = 1;
    for (int i = 1; i < num + 1; i++) {
        if (input[i] < input[i - 1]) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
