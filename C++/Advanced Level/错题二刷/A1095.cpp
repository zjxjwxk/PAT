#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 10000;

struct Record {
    char id[8];
    int time, status;
} records[maxn];

vector<Record> vec;
map<string, int> lenMap;

int cmpByIdAndTime(Record r1, Record r2) {
    int strCmp = strcmp(r1.id, r2.id);
    if (strCmp != 0) {
        return strCmp < 0;
    } else {
        return r1.time < r2.time;
    }
}

int cmpByTime(Record r1, Record r2) {
    return r1.time < r2.time;
}

int main() {
    int n, k, hour, min, sec, time, cnt = 0, maxLen = -1, j = 0;
    scanf("%d %d", &n, &k);
    char status[3];
    for (int i = 0; i < n; i++) {
        scanf("%s %d:%d:%d %s", records[i].id, &hour, &min, &sec, status);
        records[i].time = hour * 3600 + min * 60 + sec;
        if (strcmp(status, "in") == 0) {
            records[i].status = 1;
        } else {
            records[i].status = -1;
        }
    }
    sort(records, records + n, cmpByIdAndTime);
    for (int i = 1; i < n; i++) {
        if (strcmp(records[i].id, records[i - 1].id) == 0 && records[i - 1].status == 1 && records[i].status == -1) {
            vec.push_back(records[i - 1]);
            vec.push_back(records[i]);
            lenMap[records[i].id] += records[i].time - records[i - 1].time;
            if (lenMap[records[i].id] > maxLen) {
                maxLen = lenMap[records[i].id];
            }
        }
    }
    sort(vec.begin(), vec.end(), cmpByTime);
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &hour, &min, &sec);
        time = hour * 60 * 60 + min * 60 + sec;
        while (j < vec.size() && vec[j].time <= time) {
            cnt += vec[j].status;
            j++;
        }
        printf("%d\n", cnt);
    }
    for (auto it : lenMap) {
        if (it.second == maxLen) {
            printf("%s ", it.first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxLen / 3600, maxLen % 3600 / 60, maxLen % 60);
    return 0;
}
