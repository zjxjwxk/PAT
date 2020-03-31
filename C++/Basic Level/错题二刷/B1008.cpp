#include <cstdio>

const int maxn = 100;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, m, nums[maxn];
    scanf("%d %d", &n, &m);
    m %= n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    if (m != 0) {
        int d = gcd(n, m);
        for (int i = n - m; i <= n - m + d - 1; i++) {
            int temp = nums[i], curIndex = i;
            while ((curIndex - m + n) % n != i) {
                int preIndex = (curIndex - m + n) % n;
                nums[curIndex] = nums[preIndex];
                curIndex = preIndex;
            }
            nums[curIndex] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    return 0;
}
