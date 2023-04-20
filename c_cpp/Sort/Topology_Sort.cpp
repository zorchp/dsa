#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}
ostream& operator<<(ostream& os, queue<int> v) { // pass by value
    for (; !v.empty(); v.pop()) os << v.front() << " ";
    return os << endl;
}
ostream& operator<<(ostream& os, stack<int> v) { // pass by value
    for (; !v.empty(); v.pop()) os << v.top() << " ";
    return os << endl;
}


// 图的例子: 参见
// https://oi-wiki.org/graph/images/topo-example.svg
// 邻接表
vector<vector<int>> G{
    {1, 5, 6}, {},  {0, 3},       {5}, {},   {4}, {4, 9},
    {6},       {7}, {10, 11, 12}, {},  {12}, {},
};

int n = G.size(); // n: vertex
// int m{15};        // m: edge
// 存储结点的入度
vector<int> in(n);
//{1, 1, 0, 1, 2, 2, 2, 1, 0, 1, 1, 1, 2};

bool topoSort_Kahn() {
    vector<int> L;
    queue<int> S;
    // 计算节点入度
    for (auto v : G)
        for (int i : v) ++in[i];
    // cout << in;
    for (int i{}; i < n; ++i)
        if (in[i] == 0) S.push(i); // 存入度为 0 的节点
    // cout << S;
    while (!S.empty()) {
        int u = S.front();
        S.pop();
        L.push_back(u);
        // cout << G[u];
        for (auto v : G[u]) {
            if (--in[v] == 0) S.push(v);
        }
    }
    // cout << L.size() << endl;
    if (L.size() == n) {
        cout << "排序结果:\n" << L;
        return true;
    }
    return false;
}

void topoSort_DFS() {
    //
    bool visited[n];
    memset(visited, false, sizeof(visited));
    stack<int> st;

    function<void(int)> dfs = [&](int v) {
        visited[v] = true;
        for (auto i : G[v])
            if (!visited[i]) dfs(i);
        st.emplace(v);
    };
    for (int i{}; i < n; ++i)
        if (!visited[i]) dfs(i);
    cout << st;
}

int main() {
    // topoSort_Kahn(); // BFS
    // 2 8 0 3 7 1 5 6 4 9 10 11 12
    topoSort_DFS();
    // 8 7 2 3 0 6 9 11 12 10 5 4 1
}
