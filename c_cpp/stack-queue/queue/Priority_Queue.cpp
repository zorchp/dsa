#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;


class Heap { // 小根堆的基本实现
private:
    vector<int> arr;
    int len;
    void Heapify(int i, int n) {
        int smallest{i}, l{2 * i + 1}, r{2 * i + 2};
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            Heapify(smallest, n);
        }
    }

public:
    Heap() : arr(), len(0) {}
    int top() { return arr[0]; }
    bool empty() { return len == 0; }
    int size() { return len; }
    void pop() {
        if (len == 0) return;
        arr[0] = arr[--len]; // 弹出队头元素(小根)
        arr.pop_back();
        Heapify(0, len);
    }
    void push(int key) {
        //
        arr.emplace_back(key);
        for (int i{len++}; i > 0 && arr[(i - 1) / 2] > arr[i]; i = (i - 1) / 2)
            swap(arr[(i - 1) / 2], arr[i]);
    }
};

class Heap2 { // 小根堆
private:
    deque<int> arr;
    int len;
    void Heapify(int i, int n) {
        int smallest{i}, l{2 * i + 1}, r{2 * i + 2};
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            Heapify(smallest, n);
        }
    }
    void build_Heap() {
        // 建堆
        int n = arr.size();
        for (int i = (n - 1) / 2; i >= 0; --i) Heapify(i, n);
    }
    void HeapSort() {
        build_Heap();
        for (int i = arr.size() - 1; i > 0; --i) {
            swap(arr[0], arr[i]); // 相当于弹出堆顶
            Heapify(0, i); // 每次都要堆化, 保证堆顶元素始终为最小值
        }
    }

public:
    Heap2() : arr({}), len(0) {}
    Heap2(vector<int> &&v) : arr(v.begin(), v.end()), len(v.size()) {
        build_Heap();
    }
    int top() { return arr[0]; }
    void pop() {
        arr.pop_front();   // 弹出队头元素(小根)
        Heapify(0, --len); // 重新堆化
    }
    void push(int val) {
        arr.emplace_front(val);
        Heapify(0, ++len);
    }
    void print() {
        HeapSort();
        for (auto i : arr) cout << i << " ";
        cout << endl;
    }
};

class Heap1 { // 大根堆
private:
    deque<int> arr;
    void Heapify(int i, int n) {
        //
        int largest{i}, l{2 * i + 1}, r{2 * i + 2};
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            Heapify(n, largest);
        }
    }
    void build_Heap() {
        // 建堆
        int n = arr.size();
        for (int i = (n - 1) / 2; i >= 0; --i) Heapify(i, n);
    }
    void HeapSort() {
        build_Heap();
        // cout << arr;
        for (int i = arr.size() - 1; i > 0; --i) {
            swap(arr[0], arr[i]); // 相当于弹出堆顶
            Heapify(0, i); // 每次都要堆化, 保证堆顶元素始终为最大值
        }
    }

public:
    Heap1() : arr({}) {}
    Heap1(vector<int> &&v) : arr(v.begin(), v.end()) { build_Heap(); }
    int top() { return arr[0]; }
    void pop() {
        arr.pop_front();            // 弹出队头元素(大根)
        Heapify(0, arr.size() - 1); // 重新堆化
    }
    void push(int val) {
        arr.emplace_front(val);
        Heapify(0, arr.size());
    }
    void print() {
        HeapSort();
        for (auto i : arr) cout << i << " ";
        cout << endl;
    }
};


void t1() {
    Heap2 h;
    // 插入元素
    h.push(1);
    h.push(2);
    h.print();
}

void t2() {
    vector<int> v{4, 2, 6, 3, 7, 3, 9, 5};
    Heap2 h(std::move(v));
    h.print();
}

void t3() {
    vector<int> v{4, 1, 3, 2, 16, 9, 10, 14, 8, 7}; //

    Heap h;
    for (auto i : {4, 2, 6, 3, 7, 3, 9, 5}) h.push(i);

    int k = 8;
    while (k--) cout << h.top() << " ", h.pop();
    cout << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    // t2();
    t3();
    return 0;
}