#include <iostream>

using namespace std;

int Josephus(int n, int m) {
    int ans{};
    for (int i{2}; i <= n; ++i) {
        ans = (ans + m) % i;
    }
    return ans + 1;
}

int main(int argc, char *argv[]) {
    // 下标从 1 开始
    cout << Josephus(17, 3) << endl; // 11
    cout << Josephus(5, 3) << endl;  // 4
    return 0;
}
