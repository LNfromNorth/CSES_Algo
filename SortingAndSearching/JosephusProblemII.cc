#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    struct node *pre;
    struct node *next;
};

void solve(int num, int k) {
    vector<vector<int>> arr;
    int root = sqrt(num);
    int row = 0, col = 0, count = 0;
    vector<int> vec;
    for (int i = 1; i <= num; i++) {
        if (count > root) {
            count = 0;
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if (!vec.empty())
        arr.push_back(vec);
    for (int i = 0; i < num; i++) {
        int j = k % (num - i);
        while (j) {
            if (col + j < (int)arr[row].size()) {
                col += j;
                j = 0;
            } else {
                j -= arr[row].size() - col;
                col = 0;
                row++;
            }
            if (row >= (int)arr.size())
                row = 0;
        }
        while ((int)arr[row].size() <= col) {
            col = 0;
            row++;
            if (row >= (int)arr.size())
                row = 0;
        }
        cout << arr[row][col] << " ";
        if (i != num - 1) {
            arr[row].erase(arr[row].begin() + col);
            while ((int)arr[row].size() <= col) {
                col = 0;
                row++;
                if (row >= (int)arr.size())
                    row = 0;
            }
        }
    }
}

int main() {
    long num, k;
    cin >> num;
    cin >> k;
    solve(num, k);
    return 0;
}

void solve_dlist(int num, int k) {
    node *head = (node *)malloc(sizeof(node));
    head->value = 1;
    node *current = head;
    for (int i = 2; i <= num; i++) {
        node *nnode = (node *)malloc(sizeof(node));
        nnode->value = i;
        current->next = nnode;
        nnode->pre = current;
        current = nnode;
    }
    current->next = head;
    head->pre = current;
    current = head;
    int direction = 0;
    long skip = k % num;
    if (skip > (num / 2)) {
        direction = 1;
        skip = num - skip;
    }
    while (skip > 0) {
        if (direction == 0) {
            current = current->next;
        } else {
            current = current->pre;
        }
        skip--;
    }
    int count = num;
    while (count > 1) {
        cout << current->value << " ";
        node *pre = current->pre;
        node *next = current->next;
        pre->next = next;
        next->pre = pre;
        free(current);
        current = next;
        skip = k % (count - 1);
        if (skip > (num / 2)) {
            direction = 1;
            skip = count - 1 - skip;
        } else {
            direction = 0;
        }
        while (skip > 0) {
            if (direction == 0) {
                current = current->next;
            } else {
                current = current->pre;
            }
            skip--;
        }
        count--;
    }
    cout << current->value << endl;
    free(current);
}
