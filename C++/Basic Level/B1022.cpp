#include <cstdio>

int main() {
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    int sum = a + b;
    int num[31];
    int i = 0;
    do {
        num[i++] = sum % d;
        sum /= d;
    } while(sum != 0);
    for (i = i - 1; i >= 0; i--) {
        printf("%d", num[i]);
    }
    return 0;
}
