#include <iostream>
#include <string>
using namespace std;

int main() {
    string d;
    int n;
    cin >> d >> n; 
    while (--n) {
        char pre = d[0];
        int cnt = 1;
        string temp;
        for (int i = 1; i < d.length(); i++) {
            if (d[i] == pre) {
                cnt++;
            } else {
                temp += pre + to_string(cnt);
                pre = d[i];
                cnt = 1;
            }
        }
        temp += pre + to_string(cnt);
        d = temp;
    }
    cout << d;
    return 0;
} 
