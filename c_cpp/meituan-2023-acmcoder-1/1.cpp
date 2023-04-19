#include <bits/stdc++.h>
using namespace std;
/*
我写的垃圾代码...

*/
int main() {
    int m, n, a;
    cin >> n >> m >> a;
    string s;
    vector<string> vs(m);
    vector<vector<string>> vvs(n, vector<string>(m));
    int r{}, c{};
    while (cin >> s) {
        vs[r++] = s;
        if (r == m) vvs[c++] = vs, r = 0;
        if (c == n) break;
    }

    auto tmp(vvs);
    auto row1(vvs[n - 1]); // last row
    // change rows
    for (int i{n - 1}; i > 0; --i) vvs[i] = vvs[i - 1];
    vvs[0] = row1;

    // last big col
    vector<string> col1(n); // 1d array
    for (int i{}; i < n; ++i) col1[i] = vvs[i][m - 1];
    // change cols
    for (int i{}; i < n; ++i) {
        for (int j{m - 1}; j > 0; --j) { vvs[i][j] = vvs[i][j - 1]; }
    }
    for (int i{}; i < n; ++i) vvs[i][0] = col1[i];


    int ans{};
    for (int i{}; i < n; ++i) {
        for (int j{}; j < m; ++j) {
            for (int k{}; k < a; ++k) {
                if (vvs[i][j][k] != tmp[i][j][k]) ++ans;
            }
        }
    }
    cout << ans << endl;
}
