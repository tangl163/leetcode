static int binarySearch(int *nums, int numsSize, int target);

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j, *ret;

    *returnSize = 2;
    ret = malloc(sizeof *ret * 2);
    i = binarySearch(nums, numsSize, target);

    if (i == -1) {
        ret[0] = ret[1] = -1;
    } else {
        for (j = i; j > 0 && nums[j-1] == target; j--)
            ;

        ret[0] = j;

        for (j = i; j < numsSize-1 && nums[j+1] == target; j++)
            ;

        ret[1] = j;
    }

    return ret;
}

static int
binarySearch(int *nums, int numsSize, int target)
{
    int mid, low, high;

    low = 0;
    high = numsSize - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (target < nums[mid])
            high = mid - 1;
        else if (target > nums[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

