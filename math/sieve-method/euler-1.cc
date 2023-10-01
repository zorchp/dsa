#include <iostream>
#include <bitset>

using namespace std;


const int maxn = 1e7;
int ans[maxn];
bitset<maxn + 2> pri;

void euler() {
    int cnt{};

    for (int i{2}; i <= maxn; ++i) {
        if (!pri[i])
            ans[cnt++] = i;
        for (int j{}; i * ans[j] <= maxn; ++j) {
            pri[i * ans[j]] = 1;
            if (i % ans[j] == 0)
                break;
        }
    }
    cout << cnt << endl;
    // for (int i{}; i < maxn; ++i)
    //     cout << ans[i] << " ";
}

int main(int argc, char *argv[]) {
    euler();
    return 0;
}
