#include <cstdio>

int main() {
    int n, x;
    double a[5] = {0};
    int b[5] = {0};
    int flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 5 == 0 && x % 2 == 0) {
            a[0] += x;
            b[0] = 1;
        } else if (x % 5 == 1) {
            a[1] += flag * x;
            flag = -flag;
            b[1] = 1;
        } else if (x % 5 == 2) {
            a[2]++;
            b[2] = 1;
        } else if (x % 5 == 3) {
            a[3] += x;
            b[3]++;
        } else if (x % 5 == 4 && x > a[4]) {
            a[4] = x;
            b[4] = 1;
        }
    }
    a[3] /= b[3];
    for (int i = 0; i < 5; i++) {
        if (b[i] == 0) {
            printf("N");
        } else if (i == 3) {
            printf("%.1lf", a[i]);
        } else {
            printf("%d", (int) a[i]);
        }
        if (i != 4) {
            printf(" ");
        }
    }
    return 0;
}
