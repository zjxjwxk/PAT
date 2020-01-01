#include <cstdio>

int main() {
    int n;
    int ans[30];
    scanf("%d", &n);
    int i = 0;
    for (int j = n % 10; j >= 1; j--) {
        ans[i++] = j + '0';
    }
    for (int j = 0; j < n / 10 % 10; j++) {
        ans[i++] = 'S';
    }
    for (int j = 0; j < n / 100 % 10; j++) {
        ans[i++] = 'B';
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", ans[j]);
    }
    return 0;
}
