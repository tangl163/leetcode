int
minSubArrayLen(int target, int *nums, int len)
{
    int i, j, sum, min;

    min = INT_MAX;
    j = sum = 0;

    for (i = 0; i < len; ++i) {
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

