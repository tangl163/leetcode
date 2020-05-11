#define max(a, b) ((a) > (b) ? (a) : (b))

bool
canJump(int *nums, int len)
{
    int i, maxReach, step;

    if (len <= 1) {
        return true;
    }

    if (nums[0] == 0) {
        return false;
    }

    maxReach = nums[0];
    step = nums[0];

    for (i = 1; i < len; i++) {
        if (maxReach >= len - 1) {
            return true;
        }

        maxReach = max(maxReach, i + nums[i]);
        step--;

        if (step == 0) {
            if (i >= maxReach) {
                return false;
            }

            step = maxReach - i;
        }
    }

    return false;
}

