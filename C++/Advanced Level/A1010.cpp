#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int len1, len2;

long long to_decimal(char n[], int len, long long radix, long long n1_10) {
    long long ret = 0;
    for (int i = 0; i < len; i++) {
        int num = n[i];
        if (n[i] >= 'a' && n[i] <= 'z') {
            num = num - 'a' + 10;
        } else {
            num = num - '0';
        }
        ret = ret * radix + num;
        if (ret < 0) {
            return -1;
        }
    }
    return ret;
}

long long find_radix(char n[], long long left, long long right, long long n1_10) {
    long long mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        long long n2_10 = to_decimal(n, len2, mid, n1_10);
        if (n2_10 == -1 || n2_10 > n1_10) {
            right = mid - 1;
        } else if (n2_10 == n1_10) {
            return mid;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int find_largest_digit(char n[]) {
    int ans = -1, len = strlen(n);
    for (int i = 0; i < len; i++) {
        int num = n[i];
        if (n[i] >= 'a' && n[i] <= 'z') {
            num = num - 'a' + 10;
        } else {
            num = num - '0';
        }
        if (num > ans) {
            ans = num;
        }
    }
    return ans + 1;
}

int main() {
    char n1[11];
    char n2[11];
    int tag;
    long long radix;
    scanf("%s %s %d %lld", n1, n2, &tag, &radix);
    if (tag == 2) {
        char temp[11];
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }
    len1 = strlen(n1);
    len2 = strlen(n2);
    long long inf = (1LL << 63) - 1;
    long long n1_10 = to_decimal(n1, len1, radix, inf);
    long long left = find_largest_digit(n2);
    long long right = max(left, n1_10 + 1);
    long long ans = find_radix(n2, left, right, n1_10);
    if (ans != -1) {
        printf("%lld", ans);
    } else {
        printf("Impossible");
    }
    return 0;
}
