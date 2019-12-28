#include <cstdio>

void reverse(int a[], int i, int j) {
    int temp;
    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int n, m;
    int a[100];
    scanf("%d %d", &n, &m);
    m = m % n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    reverse(a, 0, n - m - 1);
    reverse(a, n - m, n - 1);
    reverse(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
