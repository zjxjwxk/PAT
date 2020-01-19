#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string transfer(string str, int& e, int n) {
    while(str[0] == '0') {
        str.erase(str.begin());
    }
    if (str[0] == '.') {
        str.erase(str.begin());
        while (str[0] == '0') {
            str.erase(str.begin());
            e--;
        }
        if (str.length() == 0) {
            e = 0;
        }
    } else {
        int index = str.find(".");
        if (index != string::npos) {
            str.erase(index, 1);
            e = index;
        } else {
            e = str.length();
        }
    }
    int len = str.length();
    while (len < n) {
        str.insert(len, "0");
        len++;
    }
    return str;
}

int main() {
    int n;
    string a, b, str1, str2;
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    str1 = transfer(a, e1, n);
    str2 = transfer(b, e2, n);
    str1 = str1.substr(0, n);
    str2 = str2.substr(0, n);
    if (str1 == str2 && e1 == e2) {
        cout << "YES " << "0." << str1 << "*10^" << e1;
    } else {
        cout << "NO " << "0." << str1 << "*10^" << e1
            << " 0." << str2 << "*10^" << e2;
    }
    return 0;
}
