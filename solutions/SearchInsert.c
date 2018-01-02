int
searchInsert(int *nums, int numsSize, int target)
{
    int flag, low, mid, high;

    low = flag = 0;
    high = numsSize - 1;

    while (low <= high) {
        mid = low + ((high - low) >> 1);

        if (target > nums[mid]) {
            flag = 1;
            low = mid + 1;
        } else if (target < nums[mid]) {
            flag = 0;
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return mid + flag;
}

