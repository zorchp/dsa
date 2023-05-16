#include <iostream>
#include <vector>
#include <cstdlib> //rand
#include <ctime>   //time
#include <queue>   // priority_queue
#include <chrono>

using namespace std;
using namespace std::chrono_literals;
constexpr auto X = 0x3f3f3f3f;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << (i == X ? string("∞") : to_string(i)) << "\t";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}

void Dijkstra(const vector<vector<int>> &g, vector<int> &dis) { // O(n^2)
    int n = dis.size(), cur{};
    // dis = g[0];
    dis.assign(n, X);
    dis[0] = 0;
    vector<bool> vis(n);

    vis[0] = true;                  // 从源点开始, 表示已被处理过
    for (int i{}; i < n - 1; ++i) { // 遍历剩余的点
        // 每一轮都去找最小的距离, 这部分可以用优先队列优化
        auto mini = X;
        for (int j{}; j < n; ++j)
            if (!vis[j] && dis[j] < mini) mini = dis[j], cur = j;
        // cout << cur << " " << dis[cur] << endl;
        // cur 代表距离源点最近点的索引
        vis[cur] = true;
        // 松弛操作
        for (int v{}; v < n; ++v)
            if (g[cur][v] < X && dis[v] > dis[cur] + g[cur][v])
                dis[v] = dis[cur] + g[cur][v]; //, cout << dis;
    }
}

struct Node {
    int dis, u;
    Node(int _dis, int _u) : dis(_dis), u(_u) {}
    bool operator>(const Node &node) const { return dis > node.dis; }
};

// 采用优先队列优化最短距离的查询
void Dijkstra_Heap(const vector<vector<int>> &g, vector<int> &dis) { // O(nlogn)
    int n = dis.size();
    vector<bool> vis(n);
    dis.assign(n, X);
    dis[0] = 0; // 源点开始

    // 优先队列存 节点对应的距离和对应的下标索引
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        int u = pq.top().u;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int v{}; v < n; ++v)
            if (g[u][v] < X && dis[v] > dis[u] + g[u][v])
                dis[v] = dis[u] + g[u][v],
                pq.emplace(dis[v], v); //, cout << dis;
    }
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
    int n = adjacent_matrix.size();
    vector<int> dis(n);
    vector<bool> vis(n);
    Dijkstra(adjacent_matrix, dis);
    // Dijkstra_Heap(adjacent_matrix, dis);
    cout << dis;
    // just Dijkstra
    // 0       8       ∞       5       ∞
    // 0       8       14      5       ∞
    // 0       8       14      5       7
    // 0       8       13      5       7
    // 0       8       9       5       7

    // with priority_queue optimize:
    // 0       10      ∞       ∞       ∞
    // 0       10      ∞       5       ∞
    // 0       8       ∞       5       ∞
    // 0       8       14      5       ∞
    // 0       8       14      5       7
    // 0       8       13      5       7
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


    // Dijkstra(adjacent_matrix, dis);
    Dijkstra_Heap(adjacent_matrix, dis);

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
