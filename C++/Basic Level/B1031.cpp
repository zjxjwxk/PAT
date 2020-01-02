#include <cstdio>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    char id[18];
    int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    for (int i = 0; i < n; i++) {
        scanf("%s", id);
        int sum = 0;
        int flag = true;
        for (int j = 0; j < 17; j++) {
            if (id[j] < '0' && id[j] > '9') {
                printf("%s\n", id);
                count++;
                flag = false;
            }
            sum += (id[j] - '0') * a[j];
        }
        if (true && m[sum % 11] != id[17]) {
            printf("%s\n", id);
            count++;
        }
    }
    if (count == 0) {
        printf("All passed");
    }
    return 0;
}
