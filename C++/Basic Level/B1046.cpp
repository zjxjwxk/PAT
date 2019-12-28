#include <cstdio>

int main() {
    int n, a1, a2, b1, b2;
    int count1 = 0, count2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        if (a1 + b1 == a2 && a1 + b1 != b2) {
            count2++;
        } else if (a1 + b1 == b2 && a1 + b1 != a2) {
            count1++;
        }
    }
    printf("%d %d", count1, count2);
    return 0;
}
