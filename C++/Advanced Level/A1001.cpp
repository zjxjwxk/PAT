#include <cstdio>

int main() {
    int a, b, sum;
    scanf("%d %d", &a, &b);
    sum = a + b;
    char ans[10];
    if (sum < 0) {
        sum = -sum;
        printf("-");
    }
    int i = 0;
    do {
        if ((i + 1) % 4 != 0) {
            ans[i++] = sum % 10 + '0';
            sum /= 10;
        } else {
            ans[i++] = ',';
        }
    } while (sum != 0);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", ans[j]);
    }
    return 0;
}
