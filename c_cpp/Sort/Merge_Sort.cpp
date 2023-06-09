#include <iostream>
#include <vector>

using namespace std;

/*
归并排序
*/

// 此函数用于打印输出数组
void printArray(vector<int> arr) {
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}


// merge the sorted list
void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int arr1[n1 + 1], arr2[n2 + 1];
    for (int i = 0; i < n1; ++i) arr1[i] = arr[p + i];
    for (int j = 0; j < n2; ++j) arr2[j] = arr[q + j + 1];
    // 标记
    arr1[n1] = 10000;
    arr2[n2] = 10000;
    int i = 0, j = i;
    for (int k = p; k <= r; ++k) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            ++i;
        } else {
            arr[k] = arr2[j];
            ++j;
        }
    }
}

void merge(vector<int> &arr, int L, int M, int R) {
    vector<int> a(R - L + 1);
    int i = 0, p1 = L, p2 = M + 1;
    // 左右依次比较将小数放入新数组中
    while (p1 <= M && p2 <= R)
        a[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    // 如果左侧没全部放入则依次全部放入
    while (p1 <= M) a[i++] = arr[p1++];
    // 如果右侧没全部放入则依次全部放入
    while (p2 <= R) a[i++] = arr[p2++];
    // 将排序好后的数组复制到原数组
    /* for (i = 0; i < R - L + 1; i++) arr[L + i] = a[i]; */
    // 使用STL算法函数来操作
    std::copy(a.begin(), a.begin() + R - L + 1, arr.begin() + L);

    printArray(arr);
}

void MergeSort1(vector<int> &arr, int L, int R) {
    if (L >= R) return;
    int M = L + (R - L) / 2;
    MergeSort1(arr, L, M);
    MergeSort1(arr, M + 1, R);
    // Merge(arr, L, M, R);
    merge(arr, L, M, R);
}

void MergeSort2(vector<int> &arr) {
    int n = arr.size();
    for (int cur = 1; cur < n; cur *= 2) {
        for (int left{}; left < n - 1; left += 2 * cur) {
            int mid = min(left + cur - 1, n - 1);
            int right = min(left + 2 * cur - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

void MergeSort(vector<int> &arr) {
    int n = arr.size();
    // 两两归并的序列的长度, 1,2,4,8
    for (int i = 1; i < n; i *= 2)
        // 对于每两个相邻的子序列进行归并, 子序列的长度
        for (int j = 0; j < n - i; j += 2 * i)
            merge(arr, j, j + i - 1, min(j + 2 * i - 1, n - 1));
}

int main(int argc, char const *argv[]) {
    vector<int> arr = {19, 2, 5, 97, 9, 17, 1, 8};
    printArray(arr);
    // 进行排序
    MergeSort(arr);
    /* MergeSort(arr, 0, arr.size() - 1); */
    // 输出排序后的数组
    printArray(arr);
    return 0;
}
