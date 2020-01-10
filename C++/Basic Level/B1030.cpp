#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    scanf("%d %ld", &n, &p);
    long long num[100000];
    for (int i = 0; i < n; i++) {
        scanf("%ld", &num[i]);
    }
    sort(num, num + n);
    int max = 1;
    for (int i = 0; i < n - 1; i++) {
        int j = upper_bound(num + i + 1, num + n, num[i] * p) - num;
        if (j - i > max) {
            max = j - i;
        }
    }
    printf("%d", max);
    return 0;
}
