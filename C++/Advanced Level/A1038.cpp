#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}

int main() {
    int n;
    scanf("%d", &n);
    string num[10000];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n, cmp);
    string ans;
    for (int i = 0; i < n; i++) {
        ans += num[i];
    }
    while (ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.size() == 0) {
        cout << 0;
    } else {
        cout << ans;
    }
    return 0;
}

