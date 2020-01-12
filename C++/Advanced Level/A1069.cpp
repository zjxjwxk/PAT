#include <cstdio>
#include <algorithm>
using namespace std;

int to_arr(int n, int arr[]) {
    for (int i = 0; i < 4; i++) {
        arr[i] = n % 10;
        n /= 10;
    }
}

int to_num(int arr[]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum = sum * 10 + arr[i];
    }
    return sum;
}

int cmp_decrease(int a, int b) {
    return a > b;
}

int main() {
    int arr[5];
    int n1, n2, n;
    scanf("%d", &n);
    do {
        to_arr(n, arr);
        sort(arr, arr + 4, cmp_decrease);
        n1 = to_num(arr);
        sort(arr, arr + 4);
        n2 = to_num(arr);
        n = n1 - n2;
        printf("%04d - %04d = %04d\n", n1, n2, n);
    } while (n != 6174 && n != 0);
    return 0;
}
