#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 并查集
class UnionFind {
private:
    vector<int> parents;

public:
    UnionFind(int size) : parents(size) {
        // 初始化，每个元素都指向自己
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }

    // 合并两个元素所在的集合
    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA == rootB) return;
        parents[rootA] = rootB;
    }

    // 查找元素所在的集合
    int Find(int A) {
        if (parents[A] != A)
            // 路径压缩, 将非根节点的所有子节点都挂在根下
            parents[A] = Find(parents[A]);

        return parents[A];
    }
};

int main() {
    UnionFind uf(10);
    uf.Union(0, 1);
    uf.Union(1, 2);
    uf.Union(3, 4);
    uf.Union(4, 5);
    uf.Union(5, 6);
    uf.Union(6, 7);
    uf.Union(7, 8);
    uf.Union(0, 3);

    cout << "0 和 1 是否在同一个集合中："
         << (uf.Find(0) == uf.Find(1) ? "是" : "否") << endl;
    cout << "3 和 8 是否在同一个集合中："
         << (uf.Find(3) == uf.Find(8) ? "是" : "否") << endl;
    cout << "2 和 7 是否在同一个集合中："
         << (uf.Find(2) == uf.Find(7) ? "是" : "否") << endl;
}
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        int fa[n];
        for (int i{}; i < n; ++i) fa[i] = i;
        function<int(int)> f = [&](int u) {
            return u == fa[u] ? u : fa[u] = f(fa[u]);
        };
        for (auto e : edges) {

            int a = f(e[0]), b = f(e[1]);
            fa[a] = b;
        }
        return f(source) == f(destination);
    }
};
