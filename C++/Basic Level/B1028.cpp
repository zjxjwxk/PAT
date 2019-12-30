#include <cstdio>

struct Person {
    char name[6];
    int year;
    int month;
    int day;
} temp, oldest, youngest, left, right;

int ifOlder(Person p1, Person p2) {
    if (p1.year != p2.year) {
        return p1.year <= p2.year;
    } else if (p1.month != p2.month) {
        return p1.month <= p2.month;
    } else {
        return p1.day <= p2.day;
    }
}

int ifYounger(Person p1, Person p2) {
    if (p1.year != p2.year) {
        return p1.year >= p2.year;
    } else if (p1.month != p2.month) {
        return p1.month >= p2.month;
    } else {
        return p1.day >= p2.day;
    }
}

void init() {
    oldest.year = right.year = 2014;
    youngest.year = left.year = 1814;
    oldest.month = youngest.month = left.month = right.month = 9;
    oldest.day = youngest.day = left.day = right.day = 6;
}

int main() {
    int n, count = 0;
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if (ifOlder(temp, right) && ifYounger(temp, left)) {
            if (ifOlder(temp, oldest)) {
                oldest = temp;
            }
            if (!ifOlder(temp, youngest)) {
                youngest = temp;
            }
            count++;
        }
    }
    if (count == 0) {
        printf("0");
    } else {
        printf("%d %s %s", count, oldest.name, youngest.name);
    }
    return 0;
}
