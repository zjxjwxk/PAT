#include <cstdio>
#include <string.h>

int main() {
    int n;
    char line[100][257];
    int len[100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        int j = 0;
        char c;
        scanf("%c", &c);
        while (c != '\n') {
            line[i][j++] = c;
            scanf("%c", &c);
        }
        line[i][j] = '\0';
        len[i] = j;
    }
    int i;
    for (i = 0; i < len[0]; i++) {
        char c = line[0][len[0] - 1 - i];
        int flag = 1;
        for (int j = 1; j < n; j++) {
            if (c != line[j][len[j] - 1 - i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    if (i == 0) {
        printf("nai");
    } else {
        for (int j = len[0] - i; j < len[0]; j++) {
            printf("%c", line[0][j]);
        }
    }
    return 0;
}
