#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

map<string, set<int>> title_map, author_map, key_map, publisher_map, year_map;

void show_ids(set<int> ids) {
    for (set<int>::iterator it = ids.begin(); it != ids.end(); it++) {
        printf("%07d\n", *it);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id;
        scanf("%d%*c", &id);
        string title, author, key, publisher, year;
        getline(cin, title);
        getline(cin, author);
        while (cin >> key) {
            key_map[key].insert(id);
            char c = getchar();
            if (c == '\n') {
                break;
            }
        }
        getline(cin, publisher);
        getline(cin, year);
        title_map[title].insert(id);
        author_map[author].insert(id);
        publisher_map[publisher].insert(id);
        year_map[year].insert(id);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%d: ", &query);
        set<int> ids;
        if (query == 1) {
            string title;
            getline(cin, title);
            ids = title_map[title];
            printf("%d: %s\n", query, title.c_str());
        } else if (query == 2) {
            string author;
            getline(cin, author);
            ids = author_map[author];
            printf("%d: %s\n", query, author.c_str());
        } else if (query == 3) {
            string key;
            cin >> key;
            ids = key_map[key];
            printf("%d: %s\n", query, key.c_str());
        } else if (query == 4) {
            string publisher;
            getline(cin, publisher);
            ids = publisher_map[publisher];
            printf("%d: %s\n", query, publisher.c_str());
        } else if (query == 5) {
            string year;
            getline(cin, year);
            ids = year_map[year];
            printf("%d: %s\n", query, year.c_str());
        }
        if (ids.size() == 0) {
            printf("Not Found\n");
        } else {
            show_ids(ids);
        }
    }
    return 0;
}
