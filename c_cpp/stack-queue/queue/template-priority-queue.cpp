#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;


template <typename T,
          class Compare = less<T>>
class Priority_Queue { // 默认小根堆
    vector<T> arr;
    Compare Comp;

public:
    Priority_Queue() : arr() {}

    int top() const { return arr.front(); }
    bool empty() const { return arr.empty(); }
    int size() const { return arr.size(); }

    void pop() {
        if (arr.empty()) return;
        arr.front() = arr.back(); // 弹出队头元素
        arr.pop_back();
        int i{};
        for (;;) { // Heapify
            int tmp{i}, l{2 * i + 1}, r{2 * i + 2};
            if (l < arr.size() && Comp(arr[l], arr[tmp])) tmp = l;
            if (r < arr.size() && Comp(arr[r], arr[tmp])) tmp = r;
            if (tmp != i) {
                swap(arr[i], arr[tmp]);
                i = tmp;
            } else
                break;
        }
    }
    void push(int key) {
        //
        arr.emplace_back(key);
        for (auto i{arr.size() - 1}; i > 0 && Comp(arr[i], arr[(i - 1) / 2]);
             i = (i - 1) / 2)
            swap(arr[(i - 1) / 2], arr[i]);
    }
};

void t1() {
    Priority_Queue<int> minHeap;
    Priority_Queue<int, greater<>> maxHeap;
    for (auto i : {1, 4, 9, 3, 6, 8, 5, 2, 99})
        minHeap.push(i), maxHeap.push(i);
    for (; !minHeap.empty(); minHeap.pop()) cout << minHeap.top() << " ";
    cout << "\n"; // 1 2 3 4 5 6 8 9 99
    for (; !maxHeap.empty(); maxHeap.pop()) cout << maxHeap.top() << " ";
    cout << "\n"; // 99 9 8 6 5 4 3 2 1
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}