#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        int nums[1000];
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[j]);
        }
        stack<int> s;
        int flag = true;
        int l = 1;
        for (int j = 0; j < n; j++) {
            int num = nums[j];
            if (num >= l) {
                if (s.size() + num - l + 1 > m) {
                    flag = false;
                    break;
                } else {
                    for (; l <= num; l++) {
                        s.push(l);
                    }
                    s.pop();
                }
            } else {
                if (s.empty() || num != s.top()) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            }
        }
        if (flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
