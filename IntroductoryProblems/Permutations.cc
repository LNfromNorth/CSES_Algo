#include <iostream>
using namespace std;

int main() {
  int nums;
  cin >> nums;
  if (nums < 4 && nums != 1)
    cout << "NO SOLUTION" << endl;
  else if (nums == 4)
    cout << "3 1 4 2" << endl;
  else {
    for (int i = 1; i <= nums; i += 2)
      cout << i << " ";
    for (int i = 2; i <= nums; i += 2)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
