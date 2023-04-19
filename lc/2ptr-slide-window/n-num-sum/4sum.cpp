#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        for (int i{}; i < n - 3; ++i) {
            if (target >= 0 && nums[i] > target) break;
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j{i + 1}; j < n - 2; ++j) {
                if (target >= 0 && nums[i] + nums[j] > target) break;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l{j + 1}, r{n - 1};
                while (l < r) {
                    long tmp{1ll * nums[i] + nums[j] + nums[l] + nums[r]};
                    if (tmp == target) {
                        ans.emplace_back(
                            vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        ++l, --r;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
                        while (l < r && nums[r] == nums[r + 1]) --r;
                    } else if (tmp > target)
                        --r;
                    else
                        ++l;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v{2, 2, 2, 2, 2};
    vector<int> v2{1, -2, -5, -4, -3, 3, 3, 5};
    vector<int> v3{-2, -1, -1, 1, 1, 2, 2};

    // cout << s.fourSum(v, 8).size() << endl; // 1
    // cout << s.fourSum(v2, -11).size() << endl;
    auto a = s.fourSum(v3, 0);
    for (auto v : a) {
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}