#include <cstdio>
#include <map>
using namespace std;

map<int, int> count;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int max_count = 0, max_num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            if (count.count(num) == 0) {
                count[num] = 1;
            } else {
                count[num]++;
            }
            if (count[num] > max_count) {
                max_count = count[num];
                max_num = num;
            }
        }
    }
    printf("%d", max_num);
    return 0;
}
