#include <bits/stdc++.h>
using namespace std;

struct node {
    int value;
    struct node *next;
};

int main() {
    int num;
    cin >> num;
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
    current = head;
    int count = num;
    while (count > 1) {
        cout << current->next->value << " ";
        node *ptr = current->next;
        current->next = ptr->next;
        current = ptr->next;
        free(ptr);
        count--;
    }
    cout << current->value << endl;
    free(current);
    return 0;
}
