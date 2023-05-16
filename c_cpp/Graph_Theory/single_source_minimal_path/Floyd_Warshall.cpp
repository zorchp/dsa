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

void Floyd(vector<vector<int>> g) { // change by value
    int n = g.size();
    for (int k{}; k < n; ++k)
        for (int i{}; i < n; ++i)
            for (int j{}; j < n; ++j)
                if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
    cout << g[0];
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

void t2() {
    const int N = 100;
    srand(time(0));
    vector<vector<int>> adjacent_matrix(N, vector<int>(N));
    for (int i{}; i < N; ++i) {
        for (int j{}; j < N; ++j) {
            if (i == j) continue;
            int val = rand() % 100;
            adjacent_matrix[i][j] = (val < 30 ? X : val);
        }
    }

    auto start = std::chrono::system_clock::now();


    Floyd(adjacent_matrix);
    // Dijkstra_Heap(adjacent_matrix, dis, vis);

    auto end = std::chrono::system_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time spent: "
              << double(duration.count()) *
                     std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den
              << "s" << std::endl;

    // cout << dis;
}


int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
