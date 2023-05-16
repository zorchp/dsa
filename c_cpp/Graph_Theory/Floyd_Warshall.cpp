#include <iostream>
#include <vector>
using namespace std;
constexpr auto X = 0x3f3f3f3f;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v) os << i << "\t";
    return os << endl;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (auto i : v) os << i;
    return os << endl;
}

void Floyd(vector<vector<int>> g) {
    int n = g.size();
    for (int k{}; k < n; ++k)
        for (int i{}; i < n; ++i)
            for (int j{}; j < n; ++j)
                if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
    cout << g;
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
    Floyd(adjacent_matrix);
    // 下面的输出结果可见, 从 s 到 t,x,y,z的最短路分别为 8,9,5,7
    // 0       8       9       5       7
    // 2       0       1       2       4
    // 11      19      0       16      4
    // 0       3       4       0       2
    // 7       15      6       12      0
}


int main(int argc, char *argv[]) {
    t1();
    return 0;
}
