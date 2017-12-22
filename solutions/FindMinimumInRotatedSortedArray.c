int
findMin(int *nums, int len)
{
    int low, high, mid, min;

    low = 0;
    high = len - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (nums[mid] >= nums[low])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}

