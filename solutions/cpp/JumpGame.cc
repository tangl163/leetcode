class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i <= maxReach; ++i) {
            maxReach = std::max(maxReach, i+nums[i]);
            if (maxReach >= nums.size()-1) {
                return true;
            }
        }

        return false;
    }
};
