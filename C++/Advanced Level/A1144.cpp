#include <cstdio>
#include <map>
using namespace std;

int main() {
    int n, num, cur = 0;
    map<int, bool> m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num > 0) {
            m[num] = true;
        }
    }
    while (true) {
        if (m[++cur] == false) {
            break;
        }
    }
    printf("%d", cur);
    return 0;
}
