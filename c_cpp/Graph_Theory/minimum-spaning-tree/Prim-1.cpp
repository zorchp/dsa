#include <vector>
#include <algorithm>
#include <numeric> //iota
#include <format>
#include <iostream>

using namespace std;

constexpr auto X = 0x3f3f3f3f;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << (i == X ? "∞"s : to_string(i)) << "\t"s;
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}


int get_num_of_edge(const vector<vector<int>> &graph) {
    int P{}, N = graph.size();
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            P += (graph[i][j] != X and graph[i][j]);
        }
    }
    return P;
}


vector<int> Prim(const auto &graph) {
    int N = graph.size();
    vector<int> ans(N, -1); // 结果
    // ans[idx] -> idx 代表最小生成树的一条边
    vector<int> dis(N, X); // 权值, 初始都是 inf
    vector<bool> visited(N, false);
    auto find_min_key = [&] { // 找未被遍历过的节点中dis最小的
        auto min_weight = X, min_idx = 0;
        for (int i{}; i < N; ++i) {
            if (not visited[i] and dis[i] < min_weight) {
                min_weight = dis[i];
                min_idx = i;
            }
        }
        return min_idx;
    };
    // dis[v] : 到节点 v 的最小权值
    dis[0] = 0; // first node to search

    for (int i{}; i < N - 1; ++i) { // 找 N-1 轮即可
        auto u = find_min_key();
        cout << u << endl;
        visited[u] = true;
        for (int v{}; v < N; ++v) {
            if (not visited[v] and graph[u][v] < dis[v]) {
                ans[v] = u;
                cout << format("ans : {} -> {}\n", ans[v], v);
                dis[v] = graph[u][v];
                cout << "dis " << dis;
            }
        }
    }
    return ans;
}

void calc(const auto &graph) {
    int N = graph.size();
    auto P = get_num_of_edge(graph);
    cout << format("edge: {}, vertex: {}\n", P, N);
    auto ans = Prim(graph);
    int cost{};
    cout << "minimum spaning tree is:\n";
    for (int i{1}; i < N; ++i) {
        cost += graph[i][ans[i]];
        cout << format("{} -> {} : {}\n", ans[i], i, graph[i][ans[i]]);
    }
    cout << format("cost is {}\n", cost);
}

void t1() {
    vector<vector<int>> graph = {
        {0, 2, X, X, X},
        {2, 0, X, 3, 2},
        {X, X, 0, X, 1},
        {X, 3, X, 0, 4},
        {X, 2, 1, 4, 0} //
    };
    calc(graph);
    // edge: 10, vertex: 5
    // minimum spaning tree is:
    // 0 -> 1 : 2
    // 4 -> 2 : 1
    // 1 -> 3 : 3
    // 1 -> 4 : 2
    // cost is 8
}

void t2() {
    vector<vector<int>> graph = {
        {0, 7, 8, X, X, X}, //
        {7, 0, 3, 6, X, X}, //
        {8, 3, 0, 4, 3, X}, //
        {X, 6, 4, 0, 2, 5}, //
        {X, X, 3, 2, 0, 2}, //
        {X, X, X, 5, 2, 0}  //
    };
    calc(graph);
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
