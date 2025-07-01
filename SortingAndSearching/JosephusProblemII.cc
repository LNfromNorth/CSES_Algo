#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    struct node *pre;
    struct node *next;
};

int main() {
    long num, k;
    cin >> num;
    cin >> k;
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
    return 0;
}
