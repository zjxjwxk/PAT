#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 21;
int n, k, p, nums[maxn], maxSum = -1;
vector<int> temp, ans;

void DFS(int index, int sum, int total) {
    temp.push_back(index);
    total += nums[index];
    sum += index;
    if (temp.size() == k) {
        if (total == n && sum > maxSum) {
            ans = temp;
            maxSum = sum;
        }
    } else {
        for (int i = index; i >= 1; i--) {
            if (total + nums[i] <= n) {
                DFS(i, sum, total);
            }
        }
    }
    temp.pop_back();
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i < maxn; i++) {
        nums[i] = pow(i, p);
    }
    for (int i = 20; i >= 1; i--) {
        if (nums[i] <= n) {
            DFS(i, 0, 0);
            temp.clear();
        }
    }
    if (ans.size() == 0) {
        printf("Impossible");
    } else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d^%d", ans[i], p);
            if (i != ans.size() - 1) {
                printf(" + ");
            }
        }
    } 
    return 0;
}
