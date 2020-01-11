// binary search
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

/* 
// tow pointers
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long p;
    scanf("%d %lld", &n, &p);
    long long num[100000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    sort(num, num + n);
    int i = 0, j = 1, max_num = 1;
    while (j <= n - 1) {
        if (num[i] * p >= num[j]) {
            if (j - i + 1 > max_num) {
                max_num = j - i + 1;
            }
            j++;
        } else {
            i++;
        }
    }
    printf("%lld", max_num);
    return 0;
}
*/
