#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void show_num(string str, int len, int n) {
    if (n <= len) {
        printf(" %s*10^%d", str.c_str(), len);
    } else {
        printf(" %s", str.c_str());
        for (int i = 0; i < n - len; i++) {
            printf("0");
        }
        printf("*10^%d", len);
    }
}

int main() {
    int n;
    string a, b;
    //scanf("%d %s %s", &n, &a[0], &b[0]);
    cin >> n;
    cin >> a;
    cin >> b;
    int len1 = a.length(), len2 = b.length();
    int index1, index2;
    if ((index1 = a.find(".")) != string::npos) {
        a.erase(index1, 1);
        len1 = index1;
    }
    if ((index2 = b.find(".")) != string::npos) {
        b.erase(index2, 1);
        len2 = index2;
    }
    a.insert(0, "0.");
    b.insert(0, "0.");
    a.erase(a.begin() + 2 + n, a.end());
    b.erase(b.begin() + 2 + n, b.end());
    if (len1 == len2 && a == b) {
        printf("YES");
        show_num(a, len1, n);
    } else {
        printf("NO");
        show_num(a, len1, n);
        show_num(b, len2, n);
    }
    return 0;
}
