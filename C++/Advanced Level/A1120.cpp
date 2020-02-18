#include <cstdio>
#include <set>
using namespace std;

int n;
set<int> ans;

int getID(int num) {
    int ID = 0;
    while (num != 0) {
        ID += num % 10;
        num /= 10;
    }
    return ID;
}

int main() {
    scanf("%d", &n);
    int num, cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        ans.insert(getID(num));
    }
    printf("%d\n", ans.size());
    for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        printf("%d", *it);
        cnt++;
        if (cnt != ans.size()) {
            printf(" ");
        }
    }
    return 0;
}
