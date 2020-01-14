#include <cstdio>

// Solution on book
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int num[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    m = m % n;
    if (m != 0) {
        int d = gcd(n, m);
        for (int i = n - m; i <= n - m + d - 1; i++) {
            int temp = num[i];
            int now = i;
            while ((now - m + n) % n != i) {
                num[now] = num[(now - m + n) % n];
                now = (now - m + n) % n;
            }
            num[now] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", num[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}

/*
// My solution
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
/*
