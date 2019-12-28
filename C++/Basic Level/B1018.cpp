#include <cstdio>

int main() {
    int n;
    // 甲和乙的获胜次数统计 
    int win1 = 0 , win2 = 0;
    // 甲和乙每种手势的获胜次数统计, 按字母序 B, C, J
    int win_count1[3] = {0};
    int win_count2[3] = {0};
    char gesture[3] = {'B', 'C', 'J'};
    char a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a, &b);
        if (a == 'C') {
            if (b == 'J') {
                win1++;
                win_count1[1]++;
            } else if (b == 'B') {
                win2++;
                win_count2[0]++;
            }
        } else if (a == 'J') {
            if (b == 'C') {
                win2++;
                win_count2[1]++;
            } else if (b == 'B') {
                win1++;
                win_count1[2]++; 
            }
        } else {
            if (b == 'C') {
                win1++;
                win_count1[0]++;
            } else if (b == 'J') {
                win2++;
                win_count2[2]++;
            }
        }
    }
    printf("%d %d %d", win1, n - win1 - win2, win2);
    printf("\n");
    printf("%d %d %d", win2, n - win1 - win2, win1);
    printf("\n");
    int max_a = 0, max_b = 0;
    for (int i = 1; i < 3; i++) {
        if (win_count1[i] > win_count1[max_a]) {
            max_a = i;
        }
        if (win_count2[i] > win_count2[max_b]) {
            max_b = i;
        }
    }
    printf("%c %c", gesture[max_a], gesture[max_b]);
    return 0;
}
