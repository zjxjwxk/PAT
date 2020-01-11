#include <cstdio>

int main() {
    int n1, n2, inf = 1 << 31 - 1;
    int num1[200001], num2[200001];
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &num1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num2[i]);
    }
    num1[n1] = inf, num2[n2] = inf;
    int i = 0, j = 0, mid = (n1 + n2 + 1) / 2;
    while (mid > 1) {
        if (num1[i] <= num2[j]) {
            i++;
        } else {
            j++;
        }
        mid--;
    }
    if (num1[i] < num2[j]) {
        printf("%d", num1[i]);
    } else {
        printf("%d", num2[j]);
    }
    return 0;
}
