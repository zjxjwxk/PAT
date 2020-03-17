#include <cstdio>

const int maxn = 1001;

int main() {
    int n[maxn] = {0}, c, e, cnt = 0;
    while (scanf("%d%d", &c, &e) != EOF) {
        n[e] = c;
    }
    n[0] = 0;
    for (int i = 1; i < maxn; i++) {
        n[i - 1] = i * n[i];
        n[i] = 0;
        if (n[i - 1] != 0) {
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("0 0");
    } else {
        for (int i = maxn - 1; i >= 0; i--) {
            if (n[i] != 0) {
                printf("%d %d", n[i], i);
                cnt--;
                if (cnt != 0) {
                    printf(" ");
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}
