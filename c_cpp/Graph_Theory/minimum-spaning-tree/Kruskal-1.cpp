#include <vector>
#include <algorithm>
#include <numeric> //iota
#include <format>
#include <iostream>

using namespace std;

constexpr auto X = 0x3f3f3f3f;
/*
实现难点:
用一个数组visited来标记遍历过的边
具体方法:
遍历过某一条边之后, 将边的末端节点标记为始端节点
*/

struct Edge {
    int beg; // node index
    int end; // node index
    int weight;
};

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << (i == X ? "∞"s : to_string(i)) << "\t"s;
    return os << endl;
}

template <>
ostream &operator<<(ostream &os, const vector<Edge> &v) {
    // For print edges with weight
    for (auto [i, j, k] : v) os << format("{} -> {} : {}\n", i, j, k);
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os;
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

vector<Edge> mat_2_list(const vector<vector<int>> &graph) {
    vector<Edge> ans;
    int N = graph.size();
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            if (graph[i][j] and graph[i][j] != X) { // non zero and joint
                ans.emplace_back(i, j, graph[i][j]);
            }
        }
    }
    return ans;
}

vector<Edge> Kruskal(const auto &graph) {
    auto edges = mat_2_list(graph);
    // cout << "adjacent list is :\n" << edges;
    int N = graph.size();

    vector<Edge> ans;
    ans.reserve(N - 1);
    vector<int> visited(N); // 遍历集合, 初始为 0,1,2,...,N-1
    std::iota(visited.begin(), visited.end(), 0);

    sort(edges.begin(), edges.end(), [](const auto &lhs, const auto &rhs) {
        // 权重从小到大排序
        return lhs.weight < rhs.weight;
    });
    // cout << "after sort, edges is:\n";
    // cout << edges;

    for (const auto &edge : edges) {
        auto &[beg, end, _] = edge;
        if (visited[beg] == visited[end]) {
            continue; // 已标记过
        }
        ans.emplace_back(edge);
        auto end_state = visited[end];
        cout << "begin mark: " << visited;
        for (auto &item : visited) {
            if (item == end_state) { // 标记已遍历过的节点
                item = visited[beg];
            }
        }
        cout << "after mark: " << visited;
        if (static_cast<int>(ans.size()) == N - 1) {
            break;
        }
    }

    return ans;
}

void calc(const auto &graph) {
    int N = graph.size();
    auto P = get_num_of_edge(graph);
    cout << format("edge: {}, vertex: {}\n", P, N);
    auto ans = Kruskal(graph);
    int cost{};
    cout << "minimum spaning tree is:\n";
    cout << ans;
    for (auto [_, __, val] : ans) {
        cost += val;
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
    // 2 -> 4 : 1
    // 0 -> 1 : 2
    // 1 -> 4 : 2
    // 1 -> 3 : 3
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
    // edge: 18, vertex: 6
    // minimum spaning tree is:
    // 3 -> 4 : 2
    // 4 -> 5 : 2
    // 1 -> 2 : 3
    // 2 -> 4 : 3
    // 0 -> 1 : 7
    // cost is 17
}

int main(int argc, char *argv[]) {
    t1();
    // t2();
    return 0;
}
