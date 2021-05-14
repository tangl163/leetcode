#define max(a, b) ((a) > (b) ? (a) : (b))

int
jump(int *nums, int len)
{
    int step = 0, cur = 0, maxReach = 0;

    for (int i = 0; i < len-1; ++i) {
        maxReach = max(maxReach, nums[i]+i);
        if (i == cur) {
            ++step;
            cur = maxReach;
        }
    }

    return step;
}

