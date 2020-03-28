#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;

int main() {
    int n;
    long long p, nums[maxn];
    scanf("%d %lld", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nums[i]);
    }
    sort(nums, nums + n);
    int ans = 0;
    long long m = nums[0];
    for (int i = 0; i < n; i++) {
        int j = upper_bound(nums + i + 1, nums + n, nums[i] * p) - nums - 1;
        if (j - i + 1 > ans) {
            ans = j - i + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
