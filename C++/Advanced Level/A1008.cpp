#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, pre = 0, now;
    for (int i = 0; i < n; i++) {
        scanf("%d", &now);
        if (now > pre) {
            ans += (now - pre) * 6 + 5;
        } else {
            ans += (pre - now) * 4 + 5;
        }
        pre = now;
    }
    printf("%d", ans);
    return 0;
} 
