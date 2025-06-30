#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    struct node *next;
};

int main() {
    long num, k, statick;
    cin >> num;
    cin >> k;
    statick = k % num;
    node *head = (node *)malloc(sizeof(node));
    head->value = 1;
    node *current = head;
    for (int i = 2; i <= num; i++) {
        node *nnode = (node *)malloc(sizeof(node));
        nnode->value = i;
        current->next = nnode;
        current = nnode;
    }
    current->next = head;
    node *pre = current;
    current = head;
    long skip = statick;
    while (skip > 0) {
        current = current->next;
        pre = pre->next;
        skip--;
    }
    int count = num;
    while (count > 1) {
        cout << current->value << " ";
        node *ptr = current->next;
        pre->next = ptr;
        free(current);
        current = ptr;
        skip = k % (count - 1);
        while (skip > 0) {
            current = current->next;
            pre = pre->next;
            skip--;
        }
        count--;
    }
    cout << current->value << endl;
    free(current);
    return 0;
}
