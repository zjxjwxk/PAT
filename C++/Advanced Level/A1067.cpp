#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int num[100000];
    int index[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        index[num[i]] = i;
    }
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        if (num[i] != 0 && num[i] == i) {
            ans--;
        }
    }
    int k = 1;
    for (int i = 0; i < ans; i++) {
        if (index[0] == 0) {
            for (int j = k; j < n; j++) {
                if (num[j] != j) {
                    num[0] = num[j];
                    num[j] = 0;
                    index[0] = j;
                    index[num[0]] = 0;
                    k = j;
                    break;
                }
            }
            ans++;
        } else {
            num[index[0]] = index[0];
            num[index[index[0]]] = 0;
            int temp = index[0];
            index[0] = index[index[0]];
            index[temp] = temp;
        }
    }
    printf("%d", ans);
}
