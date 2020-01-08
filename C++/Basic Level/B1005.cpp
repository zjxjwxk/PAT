#include <cstdio>
#include <cstring>

int main() {
    int n;
    scanf("%d", &n);
    int hash_table[101];
    for (int i = 0; i < 101; i++) {
        hash_table[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (hash_table[num] != 1) {
            hash_table[num] = 0;
        }
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = (num * 3 + 1) / 2;
            }
            if (num >= 1 && num <= 100) {
                hash_table[num] = 1;
            }
        }
    }
    int flag = 0;
    for (int i = 100; i >= 1; i--) {
        if (hash_table[i] == 0) {
            if (flag == 0) {
                printf("%d", i);
                flag = 1;
            } else {
                printf("% d", i);
            }
        }
    }
    return 0;
}
