#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[n - 1] < 0) return {};
        if (nums[0] == 0 && nums[n - 1] == 0) return {{0, 0, 0}};
        vector<vector<int>> ans{};
        for (int i{}; i < n - 2; ++i) {
            if (nums[i] > 0) break; // 最左端一定是负数
            if (i && nums[i - 1] == nums[i]) continue;
            int j{i + 1}, k{n - 1};
            while (j < k) {
                int tmp{nums[i] + nums[j] + nums[k]};
                if (tmp == 0) {
                    ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j, --k;
                    while (j < k && nums[j - 1] == nums[j]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                } else if (tmp > 0)
                    --k;
                else
                    ++j;
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v{0, 1, 1};
    s.threeSum(v);
    return 0;
}