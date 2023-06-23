#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto i : v)
        os << i << " ";
    return os << endl;
}

int partition1(vector<int> &arr, int l, int r) {
    auto pivot = arr[r - 1];
    for (;;) {
        while (arr[l] < pivot)
            ++l;
        --r;
        while (pivot < arr[r])
            --r;
        if (l >= r)
            return l;
        swap(arr[l], arr[r]);
        ++l;
    }
}
void quick_sort(vector<int> &arr, int l, int r) {
    //
    if (l >= r)
        return;
    int m = partition1(arr, l, r);
    quick_sort(arr, l, m - 1);
    quick_sort(arr, m + 1, r);
}

int main(int argc, char *argv[]) {
    vector<int> arr = {0,  16, 5, 6,  11, 7,  9,  1,  8,  4,
                       19, 17, 3, 18, 10, 14, 12, 15, 13, 2};
    cout << arr;
    quick_sort(arr, 0, arr.size());
    cout << arr;
    auto tmp(arr);
    sort(tmp.begin(), tmp.end());
    assert(tmp == arr);
    return 0;
}
