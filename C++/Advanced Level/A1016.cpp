#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int DAY = 24 * 60;
int HOUR = 60;
int DAY_COST;
int rate[24];

struct Record {
    char name[21];
    int month;
    int day;
    int hour;
    int min;
    int type;
} records[1000];

struct RecordPair {
    Record record1;
    Record record2;
    int last_time;
    int cost;
} record_pairs[500];

int cmp(Record r1, Record r2) {
    int cmp_ret;
    if ((cmp_ret = strcmp(r1.name, r2.name)) != 0) {
        return cmp_ret < 0;
    } else if (r1.day != r2.day) {
        return r1.day < r2.day;
    } else if (r1.hour != r2.hour) {
        return r1.hour < r2.hour;
    } else {
        return r1.min < r2.min;
    }
}

int lastTime(Record r1, Record r2) {
    return r2.day * DAY + r2.hour * HOUR + r2.min - (r1.day * DAY + r1.hour * HOUR + r1.min);
}

int getCost(Record r1, Record r2) {
    if (r1.day != r2.day) {
        int cost1 = rate[r1.hour] * (HOUR - r1.min);
        int cost2 = rate[r2.hour] * (r2.min);
        int cost3 = 0;
        for (int i = r1.hour + 1; i < 24; i++) {
            cost3 += rate[i] * HOUR;
        }
        int cost4 = 0;
        for (int i = 0; i < r2.hour; i++) {
            cost4 += rate[i] * HOUR;
        }
        int cost5 = (r2.day - r1.day - 1) * DAY_COST;
        return cost1 + cost2 + cost3 + cost4 + cost5;
    } else if (r1.hour != r2.hour) {
        int cost1 = rate[r1.hour] * (HOUR - r1.min);
        int cost2 = rate[r2.hour] * (r2.min);
        int cost3 = 0;
        for (int i = r1.hour + 1; i < r2.hour; i++) {
            cost3 += rate[i] * HOUR;
        }
        return cost1 + cost2 + cost3;
    } else {
        return (r2.min - r1.min) * rate[r1.hour];
    }
}

int main() {
    int n;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        DAY_COST += rate[i] * 60;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char type[9];
        scanf("%s %d:%d:%d:%d %s", records[i].name, &records[i].month, &records[i].day,
            &records[i].hour, &records[i].min, &type);
        if (strcmp(type, "off-line") == 0) {
            records[i].type = 1;
        } else {
            records[i].type = 0;
        }
    }
    sort(records, records + n, cmp);
    double total = 0;
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(records[i].name, records[i + 1].name) == 0) {
            if (records[i].type == 0 && records[i + 1].type == 1) {
                record_pairs[j].record1 = records[i];
                record_pairs[j].record2 = records[i + 1];
                record_pairs[j].last_time = lastTime(records[i], records[i + 1]);
                record_pairs[j].cost = getCost(records[i], records[i + 1]);
                total += record_pairs[j].cost;
                j++;
            }
        } else {
            if (total != 0) {
                printf("%s %02d\n", record_pairs[j - 1].record1.name, record_pairs[j - 1].record1.month);
                for (int k = 0; k < j; k++) {
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", 
                    record_pairs[k].record1.day, record_pairs[k].record1.hour, record_pairs[k].record1.min,
                    record_pairs[k].record2.day, record_pairs[k].record2.hour, record_pairs[k].record2.min, 
                    record_pairs[k].last_time, record_pairs[k].cost / 100.0);
                }
                printf("Total amount: $%.2lf\n", total / 100.0);
            }
            total = 0;
            j = 0;
        }
    }
    if (total != 0) {
        printf("%s %02d\n", record_pairs[j - 1].record1.name, record_pairs[j - 1].record1.month);
        for (int k = 0; k < j; k++) {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", 
            record_pairs[k].record1.day, record_pairs[k].record1.hour, record_pairs[k].record1.min,
            record_pairs[k].record2.day, record_pairs[k].record2.hour, record_pairs[k].record2.min, 
            record_pairs[k].last_time, record_pairs[k].cost / 100.0);
        }
        printf("Total amount: $%.2lf\n", total / 100.0);
    }
    return 0;
}
