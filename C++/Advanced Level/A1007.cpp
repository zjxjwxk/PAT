#include <cstdio>

const int maxn = 10000;

int main() {
    int k;
    scanf("%d", &k);
    int nums[maxn], maxSum = -1, tempSum = 0, startIndex = 0, endIndex = k - 1, tempIndex = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &nums[i]);
        tempSum += nums[i];
        if (tempSum < 0) {
            tempSum = 0;
            tempIndex = i + 1;
        } else if (tempSum > maxSum) {
            maxSum = tempSum;
            startIndex = tempIndex;
            endIndex = i;
        }
    }
    if (maxSum < 0) {
        maxSum = 0;
    }
    printf("%d %d %d", maxSum, nums[startIndex], nums[endIndex]);
    return 0;
} 
