#include <cstdio>

int main() {
    int num[10];
    int ans[50];
    int i;
    int index = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 1; i < 10; i++) {
        if (num[i] != 0) {
            ans[index++] = i;
            num[i]--;
            break;
        }
    }
    i--;
    while (i != 10) {
        if (num[0] != 0) {
            ans[index++] = 0;
            num[0]--;
        } else if (num[i] != 0) {
            ans[index++] = i;
            num[i]--;
        } else {
            i++;
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%d", ans[i]);
    }
    return 0;
}
