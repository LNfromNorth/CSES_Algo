#include <iostream>
using namespace std;

int find_list(long start, long size, long *list, long idx, long sum,
              long half) {
    list[idx] = start;
    if (sum == half) {
        cout << start << " ";
        return 1;
    }
    long i = start + 1;
    while (i <= size) {
        if (i + sum > half)
            return 0;
        if (find_list(i, size, list, idx + 1, sum + i, half)) {
            cout << i << " ";
            return 1;
        }
        i++;
    }
    return 0;
}

int find_list_end(long start, long *list, long idx, long sum, long half) {
    list[idx] = start;
    if (sum == half) {
        return idx;
    }
    long i = start - 1;
    while (i) {
        if (sum + i <= half)
            if (long index = find_list_end(i, list, idx + 1, sum + i, half)) {
                return index;
            }
        i--;
    }
    return 0;
}

int main() {
    long num;
    cin >> num;
    long sum_num = ((num) * (num + 1)) / 2;
    long sum_half = sum_num / 2;
    long *list = (long *)malloc(num / 2 * sizeof(long));
    if (sum_num % 2 == 0) {
        cout << "YES" << endl;
        int count = find_list_end(num, list, 0, num, sum_half);
        cout << count + 1 << endl;
        for (long i = 0; i < count + 1; i++)
            cout << list[i] << " ";
        cout << endl;
        cout << (num - count - 1) << endl;
        long index = 0;
        for (long i = num; i > 0; i--) {
            if (i == list[index])
                index++;
            else
                cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
