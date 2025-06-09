#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<long> input(num);
    vector<long> dp(num);
    for (int i = 0; i < num; i++) {
        cin >> input[i];
    }
    dp[0] = input[0];
    long max_sum = dp[0];
    for (int i = 1; i < num; i++) {
        dp[i] = max(input[i], input[i] + dp[i - 1]);
        max_sum = max(max_sum, dp[i]);
    }
    cout << max_sum << endl;
    return 0;
}
