#include <cstdio>
#include <string.h>

int main() {
    char a[101], b[101], ans[101];
    int c[3] = {'J', 'Q', 'K'};
    scanf("%s %s", a, b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    int i;
    for (i = 1; i <= len1 || i <= len2; i++) {
        int x1 = i <= len1 ? a[len1 - i] - '0' : 0;
        int x2 = i <= len2 ? b[len2 - i] - '0' : 0;
        if (i % 2 == 1) {
            int mod = (x1 + x2) % 13;
            ans[i - 1] = mod < 10 ? (mod + '0') : c[mod - 10];
        } else {
            int sum = x2 - x1;
            ans[i - 1] = (sum < 0 ? (sum + 10) : sum) + '0';
        }
    }
    for (int j = i - 2; j >= 0; j--) {
        printf("%c", ans[j]);
    }
    return 0;
}
