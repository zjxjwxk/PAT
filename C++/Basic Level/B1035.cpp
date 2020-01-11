#include <cstdio>
#include <algorithm>
using namespace std;

int n;
const int maxn = 100;

bool isSame(int a[], int b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void print_array(int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

bool ifInsert(int init[], int sorted[]) {
    bool isInsert = false;
    for (int i = 1; i < n; i++) {
        if (i != 1 && isSame(init, sorted)) {
            isInsert = true;
        }
        int temp = init[i], j = i;
        while (j > 0 && init[j - 1] > temp) {
            init[j] = init[j - 1];
            j--;
        }
        init[j] = temp;
        if (isInsert == true) {
            return true;
        }
    }
    return false;
}

void ifMerge(int init[], int sorted[]) {
    bool isMerge = false;
    int step = 2;
    for (int step = 2; step / 2 <= n; step *= 2) {
        if (step != 2 && isSame(init, sorted)) {
            isMerge = true;
        }
        for (int i = 0; i < n; i += step) {
            sort(init + i, init + min(i + step, n));
        }
        if (isMerge == true) {
            print_array(init);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    int init[maxn];
    int init2[maxn];
    int sorted[maxn];
    for (int i = 0; i < n; i++) {
        scanf("%d", &init[i]);
        init2[i] = init[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &sorted[i]);
    }
    if (ifInsert(init, sorted)) {
        printf("Insertion Sort\n");
        print_array(init);
    } else {
        printf("Merge Sort\n");
        ifMerge(init2, sorted);
    }
    return 0;
}
