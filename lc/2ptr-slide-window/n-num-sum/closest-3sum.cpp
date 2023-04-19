#include <vector>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cmath>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1e7;
        for (int i{}; i < n - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            int j{i + 1}, k{n - 1};
            while (j < k) {
                int tmp{nums[i] + nums[j] + nums[k]};
                if (tmp == target) return target; // 最优解
                if (labs(tmp - target) < labs(ans - target)) ans = tmp;
                tmp > target ? --k : ++j;
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v{4, 0, 5, -5, 3, 3, 0, -4, -5};
    cout << s.threeSumClosest(v, -2); //
    return 0;
}