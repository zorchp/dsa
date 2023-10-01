#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(int argc, char *argv[]) {
    int n = 3;
    string path;
    vector<string> ans;
    function<void(int, int)> f = [&](int l, int r) {
        if (r < l) return;
        if (l < 0 || r < 0) return;
        if (l == 0 && r == 0) {
            ans.emplace_back(path);
            return;
        }
        path.push_back('(');
        f(l - 1, r);
        path.pop_back();

        path.push_back(')');
        f(l, r - 1);
        path.pop_back();
    };
    f(n, n);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}
