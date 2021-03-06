class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                m.erase(nums[i - k - 1]);
            }
            if (m.count(nums[i]) > 0) {
                return true;
            }
            m.insert(nums[i]);
        }
        return false;
    }
};
