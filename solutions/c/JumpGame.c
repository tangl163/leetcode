#define max(a, b) ((a) > (b) ? (a) : (b))

bool
canJump(int *nums, int len)
{
    int maxReach = 0;

    for (int i = 0; i <= maxReach; i++) {
        maxReach = max(maxReach, nums[i]+i);
        if (maxReach >= len-1) {
            return true;
        }
    }

    return false;
}

