#include <cstdio>

int main() {
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int i = 0;
    while (2 * i * i + 4 * i + 1 <= n) {
        i++;
    }
    i--;
    int first_line = 2 * i + 1;
    for (int j = 0; j < i + 1; j++) {
        for (int k = 0; k < j; k++) {
            printf(" ");
        }
        for (int k = 0; k < first_line - 2 * j; k++) {
            printf("%c", c);
        }
        printf("\n");
    }
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i - 1 - j; k++) {
            printf(" ");
        }
        for (int k = 0; k < 3 + 2 * j; k++) {
            printf("%c", c);
        }
        printf("\n");
    }
    printf("%d", n - (2 * i * i + 4 * i + 1));
    return 0;
}
