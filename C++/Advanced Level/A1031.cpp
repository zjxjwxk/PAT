#include <cstdio>
#include <string.h>

int main() {
    char str[81];
    scanf("%s", str);
    int n = strlen(str);
    int n1, n3;
    n1 = n3 = (n + 2) / 3;
    int n2 = n + 2 - n1 - n3;
    for (int i = 0; i < n1 - 1; i++) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; j++) {
            printf(" ");
        }
        printf("%c\n", str[n - 1 - i]);
    }
    for (int i = 0; i < n2; i++) {
        printf("%c", str[n1 - 1 + i]);
    }
    return 0;
}
