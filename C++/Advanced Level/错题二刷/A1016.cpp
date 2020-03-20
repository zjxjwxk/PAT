#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 2000;
int n, rate[25] = {0};

struct Record {
    string name;
    int month, day, hour, min, time, status;
} records[maxn];

double getCostFromZero(Record &r) {
    double cost = 0;
    cost += (r.day - 1) * 60 * rate[24] + r.min * rate[r.hour];
    for (int i = 0; i <= r.hour - 1; i++) {
        cost += rate[i] * 60;
    }
    return cost;
}

int cmp(Record r1, Record r2) {
    if (r1.name != r2.name) {
        return r1.name < r2.name;
    } else {
        return r1.time < r2.time;
    }
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    string status;
    for (int i = 0; i < n; i++) {
        cin >> records[i].name;
        scanf("%d:%d:%d:%d", &records[i].month, &records[i].day, &records[i].hour, &records[i].min);
        records[i].time = records[i].day * 24 * 60 + records[i].hour * 60 + records[i].min;
        cin >> status;
        if (status == "on-line") {
            records[i].status = 1;
        } else {
            records[i].status = 0;
        }
    }
    sort(records, records + n, cmp);
    map<string, vector<Record> > nameRecords;
    for (int i = 1; i < n; i++) {
        if (records[i].name == records[i - 1].name && records[i - 1].status == 1 && records[i].status == 0) {
            nameRecords[records[i].name].push_back(records[i - 1]);
            nameRecords[records[i].name].push_back(records[i]);
        }
    }
    for (auto it : nameRecords) {
        vector<Record> temp = it.second;
        printf("%s %02d\n", it.first.c_str(), temp[0].month);
        double totalCost = 0;
        for (int i = 0; i < temp.size(); i += 2) {
            double cost = getCostFromZero(temp[i + 1]) - getCostFromZero(temp[i]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i].day, temp[i].hour, temp[i].min, temp[i + 1].day, temp[i + 1].hour, temp[i + 1].min, temp[i + 1].time - temp[i].time, cost / 100);
            totalCost += cost;
        }
        printf("Total amount: $%.2f\n", totalCost / 100);
    }
    return 0;
}
