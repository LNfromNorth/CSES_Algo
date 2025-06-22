#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    long num;
    cin >> num;
    set<int> input;
    queue<int> order;
    int item;
    long max_len = 0;
    for (long i = 0; i < num; i++) {
        cin >> item;
        size_t pre_len = input.size();
        input.insert(item);
        order.push(item);
        size_t after_len = input.size();
        if (pre_len == after_len) {
            while (order.front() != item) {
                input.erase(order.front());
                order.pop();
            }
            order.pop();
        }
        if ((long)after_len > max_len) {
            max_len = after_len;
        }
    }
    cout << max_len << endl;
    return 0;
}
