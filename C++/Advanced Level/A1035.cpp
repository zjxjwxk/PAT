#include <cstdio>

struct User {
    char name[11];
    char password[11];
} users[1000];

int main() {
    int n, count = 0;
    scanf("%d", &n);
    int index[1000];
    int k = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %s", users[i].name, users[i].password);
        int j = 0;
        int flag = 0;
        while (users[i].password[j] != '\0') {
            if (users[i].password[j] == '1') {
                users[i].password[j] = '@';
                flag = 1;
            } else if (users[i].password[j] == '0') {
                users[i].password[j] = '%';
                flag = 1;
            } else if (users[i].password[j] == 'l') {
                users[i].password[j] = 'L';
                flag = 1;
            } else if (users[i].password[j] == 'O') {
                users[i].password[j] = 'o';
                flag = 1;
            }
            j++;
        }
        if (flag) {
            index[k++] = i;
        }
    }
    if (k == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        index[k] = -1;
        printf("%d\n", k);
        k = 0;
        while (index[k] != -1) {
            printf("%s %s\n", users[index[k]].name, users[index[k]].password);
            k++;
        }
    }
    return 0;
}
