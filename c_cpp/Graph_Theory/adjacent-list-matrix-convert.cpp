#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix2table(vector<vector<int>> matrix) {
    vector<vector<int>> result;
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
        vector<int> tmp1;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j]) tmp1.emplace_back(j);
        }
        result.emplace_back(tmp1);
    }
    return result;
}

vector<vector<int>> table2matrix(vector<vector<int>> table) {
    vector<vector<int>> ret;
    int N = table.size();
    for (int i = 0; i < N; i++) {
        vector<int> tmp(N);
        for (int j : table[i]) tmp[j] = 1;
        ret.emplace_back(tmp);
    }
    return ret;
}

int main() {
    vector<vector<int>> matrix = {
        //
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0} //
    };

    auto tb = matrix2table(matrix);
    for (auto row : tb) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }
    cout << '\n';

    auto mat = table2matrix(tb);
    for (auto row : mat) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
