#include <vector>
#include <cstdlib> //rand
#include <ctime>   //time
#include <queue>   // priority_queue
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono_literals;

constexpr auto X = 0x3f3f3f3f;


template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << (i == X ? "∞"s : to_string(i)) << "\t";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}

bool BellmanFord(vector<vector<int>> &g, vector<int> &dis) {
    int n = g.size();
    bool flg{};
    // dis = g[0];
    dis.assign(n, X);
    dis[0] = 0;

    for (int i{}; i < n; ++i) { // 遍历每一源点
        flg = false;
        for (int u{}; u < n; ++u) {
            for (int v{}; v < n; ++v) {
                auto w = g[u][v];
                if (w < X && dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w, flg = true; //, cout << dis;
            }
        }
        if (!flg) break; // 无法松弛, 停止
    }
    // cout << dis;
    return flg; // 仍可以松弛说明含有一个负环
}

void t1() {
    // example by CLRS
    vector<vector<int>> adjacent_matrix = {
        {0, 10, X, 5, X}, // s
        {X, 0, 1, 2, X},  // t
        {X, X, 0, X, 4},  // x
        {X, 3, 9, 0, 2},  // y
        {7, X, 6, X, 0},  // z
    };
    vector<int> dis(adjacent_matrix.size());
    cout << (BellmanFord(adjacent_matrix, dis) ? "exist negative cycle"
                                               : "not exist negative cycle\n");
    // 仅说明从 s 没到达一个负环, 并不能说图中没有负环
    // 0       10      11      5       ∞
    // 0       10      11      5       15
    // 0       8       11      5       15
    // 0       8       11      5       7
    // 0       8       9       5       7
}

void t2() {
    const int N = 1000;
    // srand(time(0));
    srand(0);
    vector<vector<int>> adjacent_matrix(N, vector<int>(N));
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            if (i == j) continue;
            int val = rand() % 100;
            adjacent_matrix[i][j] = (val < 30 ? X : val);
        }
    }
    vector<int> dis(N);

    auto start = std::chrono::system_clock::now();


    BellmanFord(adjacent_matrix, dis);

    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spent: "
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "s" << std::endl;

    cout << dis;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
