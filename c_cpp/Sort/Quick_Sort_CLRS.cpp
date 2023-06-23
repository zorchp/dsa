#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <list>
#include <ctime>
#include <tuple>
#include <vector>
#include <cassert>
#include <chrono>
#include <random>

using namespace std::chrono;

using namespace std;

void printArray(const vector<int> &A) {
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

/*
快速排序基本思想
1. 选定pivot中心轴
2. 将大于pivot的数字放在pivot右边
3. 将小于pivot的数字放在pivot左边
4. 分别对左右子序列重复上述三步操作
具体思路:
首先默认以最右边的数为pivot, 进行遍历比较,
需要左右两个游标, 分别对左右两个子序列进行值比较
*/

// 这部分相当于是插入排序
int Partition1(vector<int> &arr, int l, int r) { // pivot=arr[mid]
    /*i: the number of left side of x */
    int mid = l + (r - l) / 2; // 选pivot
    swap(arr[mid], arr[r]);    // 这样就不需要判断mid位置了
    int pivot = arr[r], i = l;
    for (int j = l; j < r; ++j)
        if (arr[j] <= pivot)
            swap(arr[i++], arr[j]);

    swap(arr[r], arr[i]);
    return i; // 返回pivot插入的位置
}

int Partition2(vector<int> &arr, int l, int r) { // pivot=arr[r]
    /*i: the number of left side of x */
    int x = arr[r], i = l;
    for (int j = l; j < r; ++j)
        if (arr[j] <= x)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[r]);
    // printArray(arr);
    return i; // 返回pivot插入的位置
}

int Partition(vector<int> &arr, int l, int r) { // pivot=arr[l]
    /*i: the number of left side of x */
    int x = arr[l], i = l + 1;
    for (int j = l + 1; j <= r; ++j)
        if (arr[j] <= x)
            swap(arr[i++], arr[j]);
    swap(arr[i - 1], arr[l]);
    // printArray(arr);
    return i - 1; // 返回pivot插入的位置
}

int Partition3(vector<int> &arr, int l, int r) { // pivot=arr[l]
    /*i: the number of left side of x */
    // 通过把选出来的pivot换在最后面, 减少判断
    swap(arr[l], arr[r]);
    int x = arr[r], i = l;
    for (int j = l; j < r; ++j)
        if (arr[j] <= x)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[r]);
    // printArray(arr);
    return i; // 返回pivot插入的位置
}

int PartitionX(vector<int> &arr, int l, int r) {
    swap(arr[rand() % (r - l + 1)], arr[r]); // 这里x 可以取l到r任意一个元素
    int i = l;
    for (int j{l}; j < r; ++j)
        if (arr[j] <= arr[r])
            swap(arr[i++], arr[j]);

    swap(arr[r], arr[i]);
    return i; // 返回pivot插入的位置
}

// 递归实现快速排序算法
void QuickSort1(vector<int> &arr, int l, int r) {
    if (l >= r)
        return;
    int m = Partition(arr, l, r);
    QuickSort1(arr, l, m - 1);
    QuickSort1(arr, m + 1, r);
}


/* arr --> Array to be sorted,
    l  --> Starting index,
    r  --> Ending index */
void QuickSort2(vector<int> &arr) {
    int l{}, r = arr.size() - 1;
    int stack[r - l + 1];
    // 栈顶指针(索引)
    int top = -1;

    stack[++top] = l;
    stack[++top] = r;
    // 栈空, 说明每一个子区间都被处理完了
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];

        int p = Partition(arr, l, r);
        // pivot 左边元素入栈
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        // pivot 右边元素入栈
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}
int median(int a, int b, int c) {
    if (a < b)
        if (b < c)
            return b;
        else if (a < c) // b>=c
            return c;
        else
            return a;
    else if (a < c)
        return a;
    else if (b < c)
        return c;
    else
        return b;
}

// 只能满足部分排序的需求, 最后的小区间需要用插入排序, 否则会出问题
int PartitionY(vector<int> &arr, int l, int r) { // [l, r], 闭区间
    /*i: the number of left side of x */
    // auto pivot = median(arr[l], arr[l + (r - l) / 2], arr[r]);
    auto pivot = arr[r];
    ++r;
    for (;;) {
        while (arr[l] < pivot)
            ++l;
        --r;
        while (pivot < arr[r])
            --r;
        if (l >= r) {
            printArray(arr);
            cout << arr[l] << endl;
            return l;
        }

        swap(arr[l], arr[r]);
        ++l;
    }
}

void QuickSort(vector<int> &arr) {
    stack<pair<int, int>, list<pair<int, int>>> st; // STL
    st.emplace(0, arr.size() - 1);
    while (!st.empty()) {
        auto [l, r] = st.top();
        st.pop();
        int p = Partition(arr, l, r);
        if (p - 1 > l)
            st.emplace(l, p - 1);
        if (p + 1 < r)
            st.emplace(p + 1, r);
    }
}

const int LMT = 100;

vector<int> gen_data(size_t N) {
    vector<int> data(N);
    int min1{-LMT}, max1{LMT};

    // random_device seed;
    ranlux48 engine(1);
    uniform_int_distribution<> distrib(min1, max1);
    for (int i{}; i < N; ++i) {
        int ran1 = distrib(engine);
        data[i] = ran1;
    }
    // printArray(data);
    return data;
}

const int NUMS = 100;

void t1() {
    auto start = system_clock::now();
    // 定义数组
    vector<int> arr = {12, 5, 3, 19, 7, 9, 17, 1, 8};
    // auto arr = gen_data(NUMS);
    // 输出原始数组
    printArray(arr);
    // 进行快速排序
    // QuickSort(arr);
    cout << "sorting...\n";
    // QuickSort1(arr, 0, arr.size() - 1);
    // 输出排序后的数组
    printArray(arr);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time spent: "
         << double(duration.count()) * microseconds::period::num << "ms"
         << endl;
    auto tmp(arr);
    std::sort(tmp.begin(), tmp.end());
    assert(tmp == arr);
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
