#include <iostream>
using namespace std;

int main() {
    int c, k;
    cin >> c;
    int list[c] = {0}; 
    for(int i = 0; i < c - 1; i++) {
        cin >> k;
        list[k - 1] = 1;
    }
    for(int i = 0; i < c; i++) {
        if(list[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}