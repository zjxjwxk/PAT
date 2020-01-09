#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int index[100000];
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        index[num] = i;
        if (num != 0 && num == i) {
            ans--;
        }
    }
    int k = 1;
    for (int i = 0; i < ans; i++) {
        if (index[0] == 0) {
            for (int j = k; j < n; j++) {
                if (index[j] != j) {
                    swap(index[0], index[j]);
                    k = j;
                    break;
                }
            }
            ans++;
        } else {
            swap(index[0], index[index[0]]);
        }
    }
    printf("%d", ans);
}
