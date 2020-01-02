#include <cstdio>
#include <stdlib.h>

int main() {
    char ans[10010];
    char flag1, flag2;
    char n[10010];
    char a[10010];
    scanf("%s", n);
    flag1 = n[0];
    a[0] = n[1];
    int i = 3, j = 1;
    while (n[i] != 'E') {
        a[j++] = n[i++];
    }
    a[j] = '\0';
    flag2 = n[++i];
    int e = atoi(&n[i]);
    if (flag1 == '-') {
        printf("%c", flag1);
    }
    int index = 1;
    if (e >= 0) {
        if (e >= j - 1) {
            printf("%s", a);
            for (int k = 0; k < e - (j - 1); k++) {
                printf("0");
            }
        } else {
            int k = 0;
            while (a[k] != '\0') {
                if (k == 1 + e) {
                    printf(".%c", a[k++]);
                } else {
                    printf("%c", a[k++]);  
                }
            }
        }
    } else {
        printf("0.");
        for (int k = 0; k < -e - 1; k++) {
            printf("0");
        }
        printf("%c%s", a[0], &a[1]);
    }
    return 0;
}
