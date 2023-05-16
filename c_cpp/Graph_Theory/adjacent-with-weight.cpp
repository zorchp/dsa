#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int X = INT_MAX;

vector<pair<pair<int, int>, int>> matrix2list(vector<vector<int>>& matrix) {
    vector<pair<pair<int, int>, int>> result;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] && matrix[i][j] != X)
                result.push_back({{i, j}, matrix[i][j]});

    return result;
}

vector<vector<int>> list2matrix(vector<pair<pair<int, int>, int>>& table) {
    int n = 0;
    // 找到结点数目
    for (int i = 0; i < table.size(); i++) {
        n = max(max(table[i].first.first, table[i].first.second), n);
    }
    // 这里不能直接使用列表乘法
    vector<vector<int>> ret(n + 1, vector<int>(n + 1, X));
    // 对角线置零
    for (int i = 0; i <= n; i++) {
        ret[i][i] = 0;
    }
    // 开始赋值
    for (auto p : table) {
        ret[p.first.first][p.first.second] = p.second;
    }
    return ret;
}

int main() {
    vector<vector<int>> matrix = {
        {0, 2, X, X, X},
        {2, 0, X, 3, 2},
        {X, X, 0, X, 1},
        {X, 3, X, 0, 4},
        {X, 2, 1, 4, 0} //
    };
    vector<pair<pair<int, int>, int>> tb = matrix2list(matrix);
    for (auto p : tb) {
        cout << "(" << p.first.first << ", " << p.first.second << ")\t"
             << p.second << endl;
    }
    vector<pair<pair<int, int>, int>> tb1 = {
        {{0, 1}, 2}, {{1, 0}, 2}, {{1, 3}, 3}, {{1, 4}, 2}, {{2, 4}, 1},
        {{3, 1}, 3}, {{3, 4}, 4}, {{4, 1}, 2}, {{4, 2}, 1}, {{4, 3}, 4}};
    vector<vector<int>> mat = list2matrix(tb1);
    for (auto row : mat) {
        for (auto item : row) {
            cout << (item == X ? "∞" : to_string(item)) << "\t";
        }
        cout << endl;
    }
    return 0;
}
