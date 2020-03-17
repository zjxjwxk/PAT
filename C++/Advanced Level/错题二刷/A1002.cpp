#include <cstdio>

const int maxn = 1001;

int main() {
    int k, e, cnt = 0;
    double n[maxn] = {0}, c;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %lf", &e, &c);
        n[e] = c;
        if (c != 0) {
            cnt++;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        bool flag = false;
        scanf("%d %lf", &e, &c);
        if (n[e] != 0) {
            flag = true;
        }
        n[e] += c;
        if (flag == true && n[e] == 0) {
            cnt--;
        } else if (flag == false && n[e] != 0) {
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = maxn - 1; i >= 0; i--) {
        if (n[i] != 0) {
            printf(" %d %.1f", i, n[i]);
            cnt--;
            if (cnt == 0) {
                break;
            }
        }
    }
    return 0;
}
