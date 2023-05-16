#include <iostream>
#include <ostream>
#include <vector>
#include <cstdlib> //rand
#include <ctime>   //time
#include <queue>   // priority_queue
#include <sstream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;
constexpr auto X = 0x3f3f3f3f;

struct Node {
    int dis, u;
    Node(int _dis, int _u) : dis(_dis), u(_u) {}
    bool operator>(const Node &node) const { return dis > node.dis; }
};

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << (i == X ? string("∞") : to_string(i)) << "\t";
    return os << endl;
}

// 输出邻接表
ostream &operator<<(ostream &os, const vector<vector<Edge>> &tb) {
    cout << "u\tv\tw\n";
    for (int u{}; u < tb.size(); ++u)
        for (auto e : tb[u]) //
            cout << u << "\t" << e.v << "\t" << e.w << endl;
    return os << endl;
}


template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}

// g 是邻接表
void Dijkstra(const vector<vector<Edge>> &g, vector<int> &dis) { // O(nlogn)
    int n = dis.size();
    vector<bool> vis(n);
    // 保存最短 的前一个节点
    vector<int> pre(n);
    dis.assign(n, X);
    dis[0] = 0; // 源点开始

    // 优先队列存 节点对应的距离和对应的下标索引
    priority_queue<Node, vector<Node>, greater<>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto u = pq.top().u;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto &ed : g[u]) {
            int v{ed.v}, w{ed.w};
            if (w < X && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
                pre[v] = u;
            }
        }
    }
    function<void(int, int)> print_path = [&](int s, int v) {
        if (s == v) {
            cout << s;
            return;
        }
        print_path(s, pre[v]);
        cout << " -> " << v;
    };

    int dest = 2;
    cout << "path from " << 0 << " to " << dest << " is \n";
    print_path(0, dest);
    cout << endl;
}


void t1() {
    // example by CLRS
    vector<vector<int>> mat = {
        {0, 10, X, 5, X}, // s
        {X, 0, 1, 2, X},  // t
        {X, X, 0, X, 4},  // x
        {X, 3, 9, 0, 2},  // y
        {7, X, 6, X, 0},  // z
    };
    int n = mat.size();
    vector<int> dis(n);
    vector<bool> vis(n);
    vector<vector<Edge>> table(n);
    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j)
            if (i != j && mat[i][j] != X)
                table[i].push_back(Edge(j, mat[i][j]));
    Dijkstra(table, dis);
    cout << dis;
    // cout << table;
}

void t2() {
    const int N = 1000;
    // srand(time(0));
    srand(0);
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            if (i == j) continue;
            int val = rand() % 100;
            mat[i][j] = (val < 30 ? X : val);
        }
    }
    vector<int> dis(N);

    auto start = std::chrono::system_clock::now();


    // Dijkstra(mat, dis);
    // Dijkstra(mat, dis);

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
    t1();
    // t2();
    return 0;
}
