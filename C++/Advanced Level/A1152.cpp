#include <iostream>
#include <string>
using namespace std;

bool ifPrime(long long x) {
    if (x == 0 || x == 1) {
        return false;
    } else if (x == 2) {
        return true;
    } else {
        for (long long i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int l, k;
    string numStr;
    cin >> l >> k >> numStr;
    for (int i = 0; i <= l - k; i++) {
        string subStr = numStr.substr(i, k);
        long long subNum = stoi(subStr);
        if (ifPrime(subNum) == true) {
            cout << subStr;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}
