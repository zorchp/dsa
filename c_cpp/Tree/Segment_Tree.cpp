#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> &v) {
    for (auto i : v) cout << i << " ";
    cout << '\n';
}
vector<int> tree(15);

void build_tree(vector<int> &arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2, left_node{2 * node + 1},
        right_node{2 * node + 2};
    build_tree(arr, left_node, start, mid);
    build_tree(arr, right_node, mid + 1, end);
    tree[node] = tree[left_node] + tree[right_node];
}

void update_tree(vector<int> &arr, int node, int start, int end, int idx,
                 int val) {
    if (start == end) {
        tree[node] = arr[idx] = val;
        return;
    }
    int mid = (start + end) / 2, left_node{2 * node + 1},
        right_node{2 * node + 2};
    if (idx >= start && idx <= mid)
        update_tree(arr, left_node, start, mid, idx, val);
    else
        update_tree(arr, right_node, mid + 1, end, idx, val);
    tree[node] = tree[left_node] + tree[right_node];
}

int query_tree(int node, int start, int end, int L, int R) {
    if (R < start || end < L) return 0;
    if (L <= start && end <= R) return tree[node];
    int mid = (start + end) / 2, left_node{2 * node + 1},
        right_node{2 * node + 2};

    int lsum = query_tree(left_node, start, mid, L, R);
    int rsum = query_tree(right_node, mid + 1, end, L, R);
    return lsum + rsum;
}

class SegmentTree {
public:
    SegmentTree() {}
};


int main(int argc, char const *argv[]) {
    vector<int> v{1, 3, 5, 7, 9, 11};
    build_tree(v, 0, 0, v.size() - 1);
    // print(tree);
    update_tree(v, 0, 0, v.size() - 1, 4, 6);
    // print(tree);
    cout << query_tree(0, 0, v.size() - 1, 3, 5);
    return 0;
}