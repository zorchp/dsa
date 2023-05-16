#include <bits/stdc++.h>

using namespace std;


class Heap { // big root heap
    vector<int> arr;
    size_t len;

    void heapify(int i) {
        while (true) {
            int l{2 * i + 1}, r{2 * i + 2}, largest{i};
            if (l < len && arr[largest] < arr[l]) largest = l;
            if (r < len && arr[largest] < arr[r]) largest = r;
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else
                break;
        }
    }

public:
    Heap() : arr(), len() {}
    void push(int item) {
        // 先插入, 然后从后往前调整
        arr.emplace_back(item);
        ++len;
        for (auto i{len - 1}; i > 0 && arr[i] > arr[(i - 1) / 2];
             i = (i - 1) / 2) {
            swap(arr[i], arr[(i - 1) / 2]);
        }
    }
    void pop() {
        //
        arr[0] = arr[len - 1];
        --len;
        arr.pop_back();
        heapify(0);
    }
    int top() const { return arr.front(); }
    bool empty() const { return len == 0; }
    size_t size() const { return len; }
};

int main(int argc, char* argv[]) {
    Heap hp{};
    time_t t;
    srand((unsigned)time(&t));

    for (int i{}; i < 10; ++i) hp.push(rand() % 100);
    for (; !hp.empty(); hp.pop()) cout << hp.top() << " ";
    cout << '\n';
    return 0;
}
