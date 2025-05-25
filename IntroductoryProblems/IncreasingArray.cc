#include <iostream>
using namespace std;

int main() {
  int nums;
  cin >> nums;
  int array[nums];
  for (int i = 0; i < nums; i++)
    cin >> array[i];
  long moves = 0;
  for (int i = 1; i < nums; i++) {
    if (array[i - 1] > array[i]) {
      moves += array[i - 1] - array[i];
      array[i] = array[i - 1];
    }
  }
  cout << moves << endl;
  return 0;
}
