#include <cstdio>

int main() {
    char n[1001];
    scanf("%s", &n);
    int ans[10] = {0};
    int i = 0;
    while (n[i] != '\0') {
        ans[n[i] - '0']++;
        i++;
    }
    for (int i = 0; i < 10; i++) {
        if (ans[i]) {
            printf("%d:%d\n", i, ans[i]);
        }
    }
    return 0;
}
