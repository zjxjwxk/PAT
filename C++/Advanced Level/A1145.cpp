#include <cstdio>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int tSize, n, m, num, sum = 0;
    scanf("%d %d %d", &tSize, &n, &m);
    while (!isPrime(tSize)) {
        tSize++;
    }
    vector<int> hash_table(tSize);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        bool flag = false;
        for (int j = 0; j < tSize; j++) {
            int hash = (num + j * j) % tSize;
            if (hash_table[hash] == 0) {
                hash_table[hash] = num;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            printf("%d cannot be inserted.\n", num);
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        for (int j = 0; j <= tSize; j++) {
            sum++;
            int hash = (num + j * j) % tSize;
            if (hash_table[hash] == num || hash_table[hash] == 0) {
                break;
            }
        }
    }
    printf("%.1f\n", 1.0 * sum / m);
    return 0;
}
