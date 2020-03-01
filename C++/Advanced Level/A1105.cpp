#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn1 = 10000, maxn2 = 100;

int cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, nums[maxn1], matrix[maxn2][maxn2] = {0}, row, column, i = 0, j = 0, k = 0, cnt = 0;
    scanf("%d", &n);
    double temp = sqrt(n);
    if (temp - (int) temp != 0) {
        row = (int) temp + 1;
    } else {
        row = (int) temp;
    }
    while (n % row != 0) {
        row++;
    }
    column = n / row;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n, cmp);
    while (cnt != n) {
        while (cnt != n && i < row && i >= 0 && j < column && j >= 0 && matrix[i][j] == 0) {
            if (k == 0) {
                matrix[i][j++] = nums[cnt++];
            } else if (k == 1) {
                matrix[i++][j] = nums[cnt++];
            } else if (k == 2) {
                matrix[i][j--] = nums[cnt++];
            } else {
                matrix[i--][j] = nums[cnt++];
            }
        }
        if (k == 0) {
            j--;
            i++;
        } else if (k == 1) {
            i--;
            j--;
        } else if (k == 2) {
            j++;
            i--;
        } else {
            i++;
            j++;
        }
        k = (k + 1) % 4;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", matrix[i][j]);
            if (j != column - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
