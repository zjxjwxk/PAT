#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int num[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int left_max[100000], right_min[100000];
    left_max[0] = 0, right_min[n - 1] = 1 << 31 - 1;
    for (int i = 1; i < n; i++) {
        if (num[i - 1] > left_max[i - 1]) {
            left_max[i] = num[i - 1];
        } else {
            left_max[i] = left_max[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (num[i + 1] < right_min[i + 1]) {
            right_min[i] = num[i + 1];
        } else {
            right_min[i] = right_min[i + 1];
        }
    }
    int ans[100000], count = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] >= left_max[i] && num[i] <= right_min[i]) {
            ans[count++] = num[i];
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d", ans[i]);
        if (i != count - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
