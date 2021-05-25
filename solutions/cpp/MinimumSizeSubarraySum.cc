class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j, sum, min;

        j = sum = 0;
        min = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            while (sum >= target) {
                if (i-j+1 < min) {
                    min = i - j + 1;
                }

                sum -= nums[j++];
            }
        }

        return min == INT_MAX ? 0 : min;
    }
};

