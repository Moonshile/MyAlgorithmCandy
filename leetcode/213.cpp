class Solution {
private:
    using citer = vector<int>::const_iterator;
    
    int rob(citer begin, citer end) {
        int money1 = 0, money2 = 0, pre = 0, cur = 0;
        for (citer i = begin; i != end; ++i) {
            cur = max(money1 + *i, money2 + *i);
            money1 = money2;
            money2 = pre;
            pre = cur;
        }
        // in fact, money2 is last pre, pre is last cur
        return max(money2, pre);
    }
    
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size() == 0 ? 0 : nums[0];
        }
        return max(rob(nums.begin(), nums.end() - 1), rob(nums.begin() + 1, nums.end()));
    }
};
