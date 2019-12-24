#include <cstdio>

int main() {
    int n, row;
    char c;
    scanf("%d %c", &n, &c);
    row = n * 0.5 + 0.5;
    for (int i = 0; i < row; i++) {
        printf("%c", c);
        for (int j = 1; j < n - 1; j++) {
            if (i == 0 || i == row - 1) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("%c\n", c);
    }
    return 0;
} 
