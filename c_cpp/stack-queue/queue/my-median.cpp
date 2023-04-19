class PriorityQueue { // 小根
public:
    // 构造函数，初始化堆
    PriorityQueue() : len(0), heap({}) {}

    // 向堆中插入元素
    void push(int x) {
        heap.push_back(x);
        // 反向堆化
        for (int i = len++; i && heap[i] < heap[(i - 1) / 2]; i /= 2)
            swap(heap[i], heap[(i - 1) / 2]);
    }

    // 获取堆顶元素
    int top() { return heap[0]; }

    // 删除堆顶元素
    void pop() {
        int last = heap[--len];
        heap.pop_back();
        if (heap.empty()) return;
        heap[0] = last;
        int i{};
        while (true) { // 正向堆化
            int minI{i}, l{i * 2 + 1}, r{i * 2 + 2};
            if (l < len && heap[l] < heap[minI]) minI = l;
            if (r < len && heap[r] < heap[minI]) minI = r;
            if (minI == i) break;
            swap(heap[i], heap[minI]);
            i = minI;
        }
    }

    // 获取堆的大小
    int size() { return len; }

    // 判断堆是否为空
    bool empty() { return len == 0; }

private:
    vector<int> heap;
    int len;
};

class PQ1 { // 首结点从1开始(CLRS)
public:
    // 构造函数，初始化堆
    PQ1() { heap.push_back(0); }

    // 向堆中插入元素
    void push(int x) {
        heap.push_back(x);
        int idx = heap.size() - 1; // 新插入的元素
        while (idx > 1 && heap[idx] > heap[idx / 2]) {
            swap(heap[idx], heap[idx / 2]);
            idx /= 2;
        }
    }

    // 获取堆顶元素
    int top() { return heap[1]; }

    // 删除堆顶元素
    void pop() {
        if (heap.size() <= 1) { return; }
        int last = heap.back();
        heap.pop_back();
        if (heap.size() <= 1) { return; }
        heap[1] = last;
        int idx = 1;
        while (idx * 2 < heap.size()) {
            int minI = idx;
            if (heap[idx * 2] > heap[minI]) { minI = idx * 2; }
            if (idx * 2 + 1 < heap.size() && heap[idx * 2 + 1] > heap[minI]) {
                minI = idx * 2 + 1;
            }
            if (minI == idx) { break; }
            swap(heap[idx], heap[minI]);
            idx = minI;
        }
    }

    // 获取堆的大小
    int size() { return heap.size() - 1; }

    // 判断堆是否为空
    bool empty() { return size() == 0; }

private:
    vector<int> heap;
};


class PriorityQueue { // 小根
public:
    // 构造函数，初始化堆
    PriorityQueue() : len(0), heap({}) {}

    // 向堆中插入元素
    void push(int x) {
        heap.push_back(x);
        // 反向堆化
        for (int i = len++; i && heap[i] < heap[(i - 1) / 2]; i = (i - 1) / 2)
            swap(heap[i], heap[(i - 1) / 2]);
    }

    // 获取堆顶元素
    int top() { return heap[0]; }

    // 删除堆顶元素
    void pop() {
        int last = heap[--len];
        heap.pop_back();
        if (heap.empty()) return;
        heap[0] = last;
        int i{};
        while (true) { // 正向堆化
            int minI{i}, l{i * 2 + 1}, r{i * 2 + 2};
            if (l < len && heap[l] < heap[minI]) minI = l;
            if (r < len && heap[r] < heap[minI]) minI = r;
            if (minI == i) break;
            swap(heap[i], heap[minI]);
            i = minI;
        }
    }

    // 获取堆的大小
    int size() { return len; }

    // 判断堆是否为空
    bool empty() { return len == 0; }

private:
    vector<int> heap;
    int len;
};

class PriorityQueue1 { // 大根
public:
    // 构造函数，初始化堆
    PriorityQueue1() : len(0), heap({}) {}

    // 向堆中插入元素
    void push(int x) {
        heap.push_back(x);
        // 反向堆化
        for (int i = len++; i && heap[i] > heap[(i - 1) / 2]; i = (i - 1) / 2)
            swap(heap[i], heap[(i - 1) / 2]);
    }

    // 获取堆顶元素
    int top() { return heap[0]; }

    // 删除堆顶元素
    void pop() {
        int last = heap[--len];
        heap.pop_back();
        if (heap.empty()) return;
        heap[0] = last;
        int i{};
        while (true) { // 正向堆化
            int minI{i}, l{i * 2 + 1}, r{i * 2 + 2};
            if (l < len && heap[l] > heap[minI]) minI = l;
            if (r < len && heap[r] > heap[minI]) minI = r;
            if (minI == i) break;
            swap(heap[i], heap[minI]);
            i = minI;
        }
    }

    // 获取堆的大小
    int size() { return len; }

    // 判断堆是否为空
    bool empty() { return len == 0; }

private:
    vector<int> heap;
    int len;
};

class MedianFinder {
    PriorityQueue1 queMin; // 大根堆 (堆顶元素是小于等于中位数的最大值)
    PriorityQueue queMax; // 大于中位数的最小值
public:
    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            // 调整(满足中位数性质)
            if (queMax.size() + 1 < queMin.size())
                queMax.push(queMin.top()), queMin.pop();
        } else {
            queMax.push(num);
            if (queMin.size() < queMax.size())
                queMin.push(queMax.top()), queMax.pop();
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) return queMin.top();
        return (queMin.top() + queMax.top()) / 2.0;
    }
};