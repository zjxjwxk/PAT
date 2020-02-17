#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10001;
int n, k;
map<int, int> ranks;

bool isPrime(int x) {
    if (x == 1) {
        return false;
    } else if (x == 2) {
        return true;
    } else {
        for (int i = 2; i <= x - 1; i++) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int ID;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ID);
        ranks[ID] = i;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &ID);
        if (ranks.count(ID) == 0) {
            printf("%04d: Are you kidding?\n", ID);
        } else if (ranks[ID] == -1) {
            printf("%04d: Checked\n", ID);
        } else if (ranks[ID] == 1) {
            printf("%04d: Mystery Award\n", ID);
            ranks[ID] = -1;
        } else if (isPrime(ranks[ID])) {
            printf("%04d: Minion\n", ID);
            ranks[ID] = -1;
        } else {
            printf("%04d: Chocolate\n", ID);
            ranks[ID] = -1;
        }
    }
    return 0;
}
