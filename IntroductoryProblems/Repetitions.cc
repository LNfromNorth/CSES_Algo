#include <iostream>
using namespace std;

int main() {
    char input[1000001] = {'\0'};
    int max_length = 1;
    int k = 1;
    cin >> input;
    int i = 1;
    while(true) {
        if(input[i] == input[i - 1]) k++;
        else {
            if(k > max_length) {
                max_length = k;
            }
            k = 1;
        }
        if(input[i] == '\0') break;
        i++;
    }
    cout << max_length << endl;
    return 0;
}