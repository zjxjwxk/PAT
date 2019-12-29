#include <cstdio>

int main() {
    int n, e, count = 0;
    double k;
    double a[1010] = {0};
    double b[1010] = {0};
    double c[2010] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &e, &k);
        a[e] = k;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &e, &k);
        b[e] = k;
    }
    int e1, k1;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (a[i] != 0 && b[j] != 0) {
                if (c[i + j] == 0) {
                    count++;
                }
                c[i + j] += a[i] * b[j];
                if (c[i + j] == 0) {
                    count--;
                }
            }
        }
    }
    printf("%d", count);
    for (int i = 2009; i >= 0; i--) {
        if (c[i] != 0) {
            printf(" %d %.1lf", i, c[i]);
        }
    }
    return 0;
}
