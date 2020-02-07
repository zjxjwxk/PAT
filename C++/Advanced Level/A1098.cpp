#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 101;
int n, init1[maxn], init2[maxn], partial[maxn];

bool arrEqual(int a[], int b[]) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void printArr(int a[]) {
    for (int i = 1; i <= n; i++) {
        printf("%d", a[i]);
        if (i != n) {
            printf(" ");
        }
    }
}

void insertSort() {
    bool ifEqual = false;
    for (int i = 2; i <= n; i++) {
        int temp = init1[i];
        int j;
        for (j = i; j >= 1; j--) {
            if (temp < init1[j - 1]) {
                init1[j] = init1[j - 1];
            } else {
                break;
            }
        }
        init1[j] = temp;
        if (ifEqual == true) {
            printf("Insertion Sort\n");
            printArr(init1);
            break;
        }
        if (arrEqual(init1, partial)) {
            ifEqual = true;
        }
    }
}

void downAdjust(int left, int right) {
    int i = left, j = i * 2, temp = init2[i];
    while (j <= right) {
        if (j + 1 <= right && init2[j + 1] > init2[j]) {
            j++;
        }
        if (temp < init2[j]) {
            init2[i] = init2[j];
        } else {
            break;
        }
        i = j;
        j *= 2;
    }
    init2[i] = temp;
}

void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}

void heapSort() {
    bool ifEqual = false;
    createHeap();
    for (int i = n; i > 1; i--) {
        swap(init2[i], init2[1]);
        downAdjust(1, i - 1);
        if (ifEqual == true) {
            printf("Heap Sort\n");
            printArr(init2);
            break;
        }
        if (arrEqual(init2, partial)) {
            ifEqual = true;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &init1[i]);
        init2[i] = init1[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &partial[i]);
    }
    insertSort();
    heapSort();
    return 0;
}
