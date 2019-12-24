#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Testee {
    char reg_id[13];
    int final_rank;
    int loc_id;
    int loc_rank;
    int score;
} testees[30010];

bool cmp(Testee testee1, Testee testee2) {
    if (testee1.score != testee2.score) {
        return testee1.score > testee2.score;
    } else {
        return strcmp(testee1.reg_id, testee2.reg_id) < 0;
    }
}

int main() {
    int loc_id = 0;
    int loc_num;
    int testee_num;
    int total_num = 0;
    scanf("%d", &loc_num);
    while (loc_num--) {
        loc_id++;
        scanf("%d", &testee_num);
        for(int i = 0; i < testee_num; i++) {
            scanf("%s %d", &testees[total_num].reg_id, 
            &testees[total_num].score);
            testees[total_num].loc_id = loc_id;
            total_num++;
        }
        sort(testees + total_num - testee_num, testees + total_num, cmp);
        testees[total_num - testee_num].loc_rank = 1;
        for (int i = total_num - testee_num + 1; i < total_num; i++) {
            if (testees[i].score == testees[i - 1].score) {
                testees[i].loc_rank = testees[i - 1].loc_rank;
            } else {
                testees[i].loc_rank = i - (total_num - testee_num) + 1;
            }
        }
    }
    sort(testees, testees + total_num, cmp);
    testees[0].final_rank = 1;
    printf("%d\n", total_num);
    for (int i = 0; i < total_num; i++) {
        if (i > 0 && testees[i].score == testees[i - 1].score) {
            testees[i].final_rank = testees[i - 1].final_rank;
        } else {
            testees[i].final_rank = i + 1;
        }
        printf("%s %d %d %d\n", testees[i].reg_id, testees[i].final_rank,
        testees[i].loc_id, testees[i].loc_rank);
    }
    return 0;
}
