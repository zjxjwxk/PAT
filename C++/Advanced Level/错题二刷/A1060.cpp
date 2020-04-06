#include <iostream>
#include <string>
using namespace std;

int n;
string a, b;

void chopping(string &str, int &e) {
    while (str[0] == '0' && str.length() > 0) {
        str.erase(0, 1);
    }
    if (str[0] == '.') {
        str.erase(0, 1);
        while (str[0] == '0' && str.length() > 0) {
            str.erase(0, 1);
            e--;
        }
    } else {
        if (str.find('.') == string::npos) {
            e = str.length();
        } else {
            e = str.find('.');
            str.erase(str.find('.'), 1);
        }
    }
    int len = str.length();
    if (len == 0) {
        e = 0;
    }
    if (str.length() < n) {
        for (int i = 0; i < n - len; i++) {
            str.append("0");
        }
    } else if (len > n) {
        str = str.substr(0, n);
    }
}

int main() {
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    chopping(a, e1);
    chopping(b, e2);
    if (a == b && e1 == e2) {
        printf("YES");
        cout << " 0." << a << "*10^" << e1;
    } else {
        printf("NO");
        cout << " 0." << a << "*10^" << e1;
        cout << " 0." << b << "*10^" << e2;
    }
    return 0;
}
