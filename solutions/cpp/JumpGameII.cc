class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, maxReach = 0, cur = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            maxReach = std::max(maxReach, nums[i]+i);
            if (i == cur) {
                ++step;
                cur = maxReach;
            }
        }

        return step;
    }
};

