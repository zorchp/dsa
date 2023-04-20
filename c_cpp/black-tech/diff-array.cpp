#include <vector>
#include <iostream>
using namespace std;


ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}


template <typename T>
class DiffArray {
    vector<T> arr;

public:
    DiffArray() : arr() {}
    DiffArray(vector<T> _arr) { init(_arr); }

    void init(const vector<T>& raw_arr) {
        int n = raw_arr.size();
        arr.resize(n);
        arr[0] = raw_arr[0];
        for (int i{1}; i < n; ++i) arr[i] = raw_arr[i] - raw_arr[i - 1];
    }

    vector<T> get_raw() {
        vector<T> raw_arr(arr);
        for (int i{1}; i < arr.size(); ++i)
            raw_arr[i] = arr[i] + raw_arr[i - 1];
        return raw_arr;
    }

    void modify(int i, int j, int k) {
        arr[i] += k;
        if (j + 1 < arr.size()) arr[j + 1] -= k;
    }

    const vector<T>& query() const { return arr; }
};


ostream& operator<<(ostream& os, const DiffArray<int>& v) {
    return os << v.query();
}


int main() {
    //
    vector<int> v{4, 7, 5, 2, 9};
    cout << v;
    DiffArray<int> d1(v);
    cout << d1;
    d1.modify(2, 3, 1); // [2, 3] 增加 1
    cout << d1;
    cout << d1.get_raw();
}
