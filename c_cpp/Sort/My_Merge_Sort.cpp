#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

void merge_sort(vector<int>& arr) {
    //
    auto merge = [&](int L, int M, int R) {
        //
        vector<int> tmp(R - L + 1);
        int i{}, l1{L}, l2{M + 1};
        for (; l1 <= M && l2 <= R; ++i)
            tmp[i] = (arr[l1] < arr[l2]) ? arr[l1++] : arr[l2++];
        for (; l1 <= M; ++i) tmp[i] = arr[l1++];
        for (; l2 <= R; ++i) tmp[i] = arr[l2++];
        for (int j{}; j < i; ++j) arr[L + j] = tmp[j];
    };
    for (int i{1}, n = arr.size(); i < n; i <<= 1)
        for (int j{}; j < n - i; j += (i << 1))
            merge(j, j + i - 1, min(j + (i << 1) - 1, n - 1));
}


int main() {
    //
    int N{15};
    vector<int> v(N);
    time_t t;
    srand((unsigned)time(&t));
    for (int i{}; i < N; ++i) v[i] = rand() % 100; //, cout << v[i] << endl;
    cout << v;
    merge_sort(v);
    cout << v;
    return 0;
}
