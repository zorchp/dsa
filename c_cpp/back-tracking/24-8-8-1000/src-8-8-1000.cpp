#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int TARGET = 1000;
const int N = 8;
struct item {
    string cal;
    int num;
    bool flag;
};
item a[N];
void swap(int i, int j) {
    item t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}
map<string, bool> mhash;
char buf[10];

bool push_map_check(int dep) {
    string s = "";
    for (int i = 0; i < dep; i++) {
        // itoa(a[i].num, buf, 10);
        s = s + to_string(a[i].num) + ',';
    }
    if (mhash[s] != true) {
        mhash[s] = true;
        return true;
    } else {
        return false;
    }
}

void search_ans(int dep) {
    if (dep == 1 && a[0].num == TARGET) cout << a[0].cal << endl;
    if (dep > 1 && push_map_check(dep)) {
        // 组合i,j
        map<int, int> hash;
        hash.clear();
        for (int i = 0; i < dep; i++)
            for (int j = i + 1; j < dep; j++) {
                if (hash[a[i].num] == a[j].num) continue;
                if (hash[a[j].num] == a[i].num) continue;
                hash[a[i].num] = a[j].num;

                swap(j, dep - 1);
                item temp = a[i];
                //+
                a[i].num = a[i].num + a[dep - 1].num;
                a[i].flag = false;
                a[i].cal = '(' + temp.cal + '+' + a[dep - 1].cal + ')';
                search_ans(dep - 1);
                a[i] = temp;
                //-
                a[i].num = a[i].num - a[dep - 1].num;
                a[i].flag = false;
                a[i].cal = '(' + temp.cal + '-' + a[dep - 1].cal + ')';
                search_ans(dep - 1);
                a[i] = temp;
                //*
                a[i].num = a[i].num * a[dep - 1].num;
                a[i].flag = false;
                a[i].cal = '(' + temp.cal + '*' + a[dep - 1].cal + ')';
                search_ans(dep - 1);
                a[i] = temp;
                // /
                if (a[dep - 1].num != 0 && a[i].num % a[dep - 1].num == 0) {
                    a[i].num = a[i].num / a[dep - 1].num;
                    a[i].flag = false;
                    a[i].cal = '(' + temp.cal + '/' + a[dep - 1].cal + ')';
                    search_ans(dep - 1);
                    a[i] = temp;
                }

                if (a[i].flag && a[dep - 1].flag && a[dep - 1].num == 8) {
                    a[i].num = a[i].num * 10 + a[dep - 1].num;
                    a[i].cal = temp.cal + a[dep - 1].cal;
                    search_ans(dep - 1);
                    a[i] = temp;
                }
                swap(dep - 1, j);
            }
    }
}


int main() {
    freopen("src-out.txt", "w", stdout);
    mhash.clear();
    for (int i = 0; i < N; i++) {
        a[i].cal = "8";
        a[i].num = 8;
        a[i].flag = true;
    }
    search_ans(N);
    return 0;
}