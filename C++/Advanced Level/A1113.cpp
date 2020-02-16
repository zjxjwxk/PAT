#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;
int n, nums[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    int index = n / 2 - 1, s1 = 0, s2 = 0, temp1, temp2;
    for (int i = 0; i <= index; i++) {
        s1 += nums[i];
    }
    for (int i = index + 1; i < n; i++) {
        s2 += nums[i];
    }
    printf("%d %d", n % 2, s2 - s1);
    return 0;
}
