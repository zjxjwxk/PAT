#include <cstdio>
#include <cstring>

int main() {
    char str[100010];
    scanf("%s", str);
    int leftPNums[100010] = {0};
    int leftPCount = 0;
    int rightTCount = 0;
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == 'P') {
            leftPCount++;
        } else if (str[i] == 'A') {
            leftPNums[i] = leftPCount;
        }
    }
    int ans = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == 'T') {
            rightTCount++;
        } else if (str[i] == 'A') {
            ans = (ans + leftPNums[i] * rightTCount) % 1000000007;
        }
    }
    printf("%d", ans);
    return 0;
} 
