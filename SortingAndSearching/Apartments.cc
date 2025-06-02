#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    vector<long> applicant;
    vector<long> apartment;
    long tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        applicant.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        apartment.push_back(tmp);
    }
    sort(applicant.begin(), applicant.end());
    sort(apartment.begin(), apartment.end());
    long count = 0;
    long idxa = 0;
    long idxb = 0;
    while (idxa < n && idxb < m) {
        if (abs(applicant[idxa] - apartment[idxb]) <= k) {
            count++;
            idxa++;
            idxb++;
        } else if (applicant[idxa] < apartment[idxb]) {
            idxa++;
        } else {
            idxb++;
        }
    }
    cout << count << endl;
    return 0;
}
