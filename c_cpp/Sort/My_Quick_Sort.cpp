#include <iostream>
#include <vector>
#include <stack>


using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}


int Partition(vector<int>& arr, int l, int r) {
    swap(arr[l], arr[r]);
    int pivot{arr[r]}, i{l};
    for (int j{l}; j < r; ++j)
        if (arr[j] <= arr[r]) swap(arr[j], arr[i++]);
    swap(arr[i], arr[r]);
    return i;
}

void Qsort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = Partition(arr, l, r);
    Qsort(arr, l, m - 1);
    Qsort(arr, m + 1, r);
}

void Qsort1(vector<int>& arr) {
    using pii = pair<int, int>;
    stack<pii> st{};
    st.emplace(pii{0, arr.size() - 1});
    while (!st.empty()) {
        auto [l, r] = st.top();
        st.pop();
        int m = Partition(arr, l, r);
        if (l < m - 1) st.emplace(pii{l, m - 1});
        if (m + 1 < r) st.emplace(pii{m + 1, r});
    }
}

int main(int argc, char const* argv[]) {
    vector<int> arr{9, 4, 23, 3, 4, 3,  43, 24, 82, 26, 123, 4,  5,
                    6, 7, 93, 5, 4, 29, 11, 39, 3,  4,  5,   69, 6};
    cout << arr;
    // Qsort(arr, 0, arr.size() - 1);
    Qsort1(arr);
    cout << arr;
    return 0;
}