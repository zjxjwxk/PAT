#include <cstdio>

int main() {
    int n;
    int b;
    scanf("%d %d", &n, &b);
    int a[31] = {0};
    int i = 0;
    while (n != 0) {
        a[i++] = n % b;
        n /= b;
    }
    while (a[i - 1] == 0) {
        i--;
    }
    bool palindromic = true;
    for (int j = 0; j < i / 2; j++) {
        if (a[j] != a[i - 1 - j]) {
            palindromic = false;
            break;
        }
    }
    printf("%s\n", palindromic ? "Yes" : "No");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", a[j]);
        if (j != 0) {
            printf(" ");
        }
    }
    return 0;
}
