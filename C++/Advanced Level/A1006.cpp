#include <cstdio>

struct Person {
    char ID[16];
    int in_hour, in_min, in_sec;
    int out_hour, out_min, out_sec;
} temp, earliest, latest;

int ifInEarlier(Person p1, Person p2) {
    if (p1.in_hour != p1.in_hour) {
        return p1.in_hour < p2.in_hour;
    } else if (p1.in_min != p2.in_min) {
        return p1.in_min < p2.in_min;
    } else {
        return p1.in_sec < p2.in_sec;
    }
}

int ifOutLater(Person p1, Person p2) {
    if (p1.out_hour != p2.out_hour) {
        return p1.out_hour > p2.out_hour;
    } else if (p1.out_min != p2.out_min) {
        return p1.out_min > p2.out_min;
    } else {
        return p1.out_sec > p2.out_min;
    }
} 

void init() {
    earliest.in_hour = 24;
    earliest.in_min = earliest.in_sec = 60;
    latest.out_hour = latest.out_min = latest.out_sec = 0;
}

int main() {
    int n;
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", temp.ID, &temp.in_hour, &temp.in_min, &temp.in_sec, &temp.out_hour, &temp.out_min, &temp.out_sec);
        if (ifInEarlier(temp, earliest)) {
            earliest = temp;
        }
        if (ifOutLater(temp, latest)) {
            latest = temp;
        }
    }
    printf("%s %s", earliest.ID, latest.ID);
    return 0;
}
