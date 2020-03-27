#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100000;

int main() {
    int n, index[maxn], num, k = 1, ans = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        index[num] = i;
        if (index[num] != num && num != 0) {
            cnt++;
        }
    }
    while (cnt != 0) {
        if (index[0] == 0) {
            for (; k < n; k++) {
                if (index[k] != k) {
                    break;
                }
            }
            swap(index[0], index[k]);
        } else {
            swap(index[0], index[index[0]]);
            cnt--;
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}
