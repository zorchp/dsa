#include <bitset>
#include <iostream>

using namespace std;
constexpr int N = 1e8;

bitset<N + 10> pri;
int ans[N];

void era() {
    int cnt{};
    for (int i{2}; i * i <= N; ++i)
        if (!pri[i])
            for (int j{i * i}; j <= N; j += i)
                pri[j] = 1;

    for (int i{2}; i < N; ++i)
        cnt += 1 - pri[i];
    cout << cnt << endl;
}

int main(int argc, char *argv[]) {
    era();
    return 0;
}
