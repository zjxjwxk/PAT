#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char n1[11], n2[11], temp[11];
int tag;
long long radix, num1, inf = (1LL << 63) - 1;

long long strToNum(char str[], long long radix, long long upper) {
    int len = strlen(str);
    long long num = 0;
    for (int i = 0; i < len; i++) {
        long long digit;
        if (str[i] >= 'a' && str[i] <= 'z') {
            digit = str[i] - 'a' + 10;
        } else {
            digit = str[i] - '0';
        }
        num = num * radix + digit;
        if (num < 0 || num > upper) {
            return -1;
        }
    }
    return num;
}

long long findLower(char str[]) {
    long long maxDigit = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        long long digit;
        if (str[i] >= 'a' && str[i] <= 'z') {
            digit = str[i] - 'a' + 10;
        } else {
            digit = str[i] - '0';
        }
        if (digit > maxDigit) {
            maxDigit = digit;
        }
    }
    return maxDigit + 1;
}

int binarySearch(long long left, long long right, char str[], long long upper) {
    long long mid, num2;
    while (left <= right) {
        mid = left + (right - left) / 2;
        long long num2 = strToNum(n2, mid, upper);
        if (num2 == num1) {
            return mid;
        } else if (num2 > num1 || num2 == -1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    if (tag == 2) {
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }
    long long lower = findLower(n2);
    num1 = strToNum(n1, radix, inf);
    long long radix2 = binarySearch(lower, max(num1, lower) + 1, n2, num1);
    if (radix2 == -1) {
        printf("Impossible");
    } else {
        printf("%d", radix2);
    }
    return 0;
}
