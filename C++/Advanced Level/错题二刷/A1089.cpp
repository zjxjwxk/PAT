#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
int n, init[maxn], init2[maxn], partial[maxn];

bool ifEqual(int arr1[], int arr2[]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void printArr(int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}

bool insertSort() {
    int arr[maxn];
    bool flag = false;
    for (int i = 1; i < n; i++) {
        int temp = init[i], j;
        for (j = i - 1; j >= 0; j--) {
            if (temp < init[j]) {
                init[j + 1] = init[j];
            } else {
                break;
            }
        }
        init[j + 1] = temp;
        if (flag == false) {
            flag = ifEqual(init, partial);
        } else {
            printf("Insertion Sort\n");
            printArr(init);
            return true;
        }
    }
    return false;
}

void mergeSort() {
    bool flag = false;
    for (int i = 2; i <= n; i *= 2) {
        for (int j = 0; j < n; j += i) {
            int left = j, right = j + i;
            if (right > n) {
                right = n;
            }
            sort(init2 + left, init2 + right);
        }
        if (flag == false) {
            flag = ifEqual(init2, partial);
        } else {
            printf("Merge Sort\n");
            printArr(init2);
            break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &init[i]);
        init2[i] = init[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &partial[i]);
    }
    if (!insertSort()) {
        mergeSort();
    }
    return 0;
}
