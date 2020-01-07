#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int HOUR = 60 * 60;
const int MIN = 60;
map<string, int> parkTime;

struct Car {
    char id[8];
    int time;
    char type[4];
} all[10000], valid[10000];

int cmpByIdAndTime(Car c1, Car c2) {
    if (strcmp(c1.id, c2.id)) {
        return strcmp(c1.id, c2.id) < 0;
    } else {
        return c1.time < c2.time;
    }
}

int cmpByTime(Car c1, Car c2) {
    return c1.time < c2.time;
}

int getTime(int hour, int min, int sec) {
    return hour * HOUR + min * MIN + sec;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int hour, min, sec;
        scanf("%s %d:%d:%d %s", all[i].id, &hour, &min, &sec, all[i].type);
        all[i].time = getTime(hour, min, sec);
    }
    sort(all, all + n, cmpByIdAndTime);
    int valid_num = 0, max_time = -1;
    for (int i = 0; i < n - 1; i++) {
        if (!strcmp(all[i].id, all[i + 1].id) 
            && !strcmp(all[i].type, "in") && !strcmp(all[i + 1].type, "out")) {
            valid[valid_num++] = all[i];
            valid[valid_num++] = all[i + 1];
            if (parkTime.count(all[i].id) == 0) {
                parkTime[all[i].id] = 0;
            }
            parkTime[all[i].id] += all[i + 1].time - all[i].time;
            max_time = max(parkTime[all[i].id], max_time);
        }
    }
    sort(valid, valid + valid_num, cmpByTime);
    int now = 0, park_num;
    for (int i = 0; i < k; i++) {
        int hour, min, sec;
        scanf("%d:%d:%d", &hour, &min, &sec);
        int query_time = getTime(hour, min, sec);
        while (now < valid_num && valid[now].time <= query_time) {
            if (!strcmp(valid[now].type, "in")) {
                park_num++;
            } else {
                park_num--;
            }
            now++;
        }
        printf("%d\n", park_num);
    }
    map<string, int>::iterator it;
    for (it = parkTime.begin(); it != parkTime.end(); it++) {
        if (it->second == max_time) {
            printf("%s ", it->first.c_str());
        }
    }
    printf("%02d:%02d:%02d", max_time / HOUR, max_time % HOUR / MIN, max_time % MIN);
    return 0;
}
