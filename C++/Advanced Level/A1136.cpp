#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rev(string a) {
    reverse(a.begin(), a.end());
    return a;
}

string add(string s1, string s2) {
    string sum = s1;
    int carry = 0;
    for (int i = s1.length() - 1; i >= 0; i--) {
        sum[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0) {
        sum = "1" + sum;
    }
    return sum;
}

int main() {
    string a, b, c;
    cin >> a;
    int n = 10;
    if (a == rev(a)) {
        cout << a << " is a palindromic number." << endl;
    } else {
        while (n--) {
            b = rev(a);
            c = add(a, b);
            cout << a << " + " << b << " = " << c << endl;
            if (c == rev(c)) {
                cout << c << " is a palindromic number." << endl;
                return 0;
            }
            a = c;
        }
        cout << "Not found in 10 iterations.";
    }
    return 0;
}
