#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int diamonds[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &diamonds[i]);
    }
    int i = 0, j = 0, sum = diamonds[0];
    int min_lost = (1 << 31) - 1;
    int min_index[100000][3];
    int count = 0;
    int flag = false;
    while (j <= n - 1) {
        if (sum < m) {
            sum += diamonds[++j];
        } else if (sum > m) {
            if ((sum - m) <= min_lost) {
                min_lost = sum - m;
                min_index[count][0] = i + 1;
                min_index[count][1] = j + 1;
                min_index[count][2] = min_lost;
                count++;
            }
            sum -= diamonds[i++];
        } else {
            printf("%d-%d\n", i + 1, j + 1);
            sum += diamonds[++j];
            flag = true;
        }
    }
    if (!flag) {
        int i = count - 1;
        while (min_index[i][2] == min_lost) {
            i--;
        }
        for (int j = i + 1; j < count; j++) {
            printf("%d-%d\n", min_index[j][0], min_index[j][1]);
        }
    }
    return 0;
}
