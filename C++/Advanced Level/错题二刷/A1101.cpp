#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100000;

int main() {
    int n, nums[maxn], leftMax[maxn], rightMin[maxn];
    scanf("%d", &n);
    leftMax[0] = 0;
    rightMin[n - 1] = 1 << 31 - 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (i != n - 1) {
            if (nums[i] > leftMax[i]) {
                leftMax[i + 1] = nums[i];
            } else {
                leftMax[i + 1] = leftMax[i];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (nums[i] < rightMin[i]) {
            rightMin[i - 1] = nums[i];
        } else {
            rightMin[i - 1] = rightMin[i];
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] > leftMax[i] && nums[i] < rightMin[i]) {
            ans.push_back(nums[i]);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i]);
        if (i != ans.size() - 1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
