class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a, b, c;

        a = b = c = LLONG_MIN;

        for (int v : nums) {
            if (v <= a || v == b || v == c) {
                continue;
            }

            if (v > c) {
                a = b;
                b = c;
                c = v;
            } else if (v > b) {
                a = b;
                b = v;
            } else {
                a = v;
            }
        }

        return a == LLONG_MIN ? c : a;
    }
};
