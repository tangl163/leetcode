/**
 * referenced by [sheehan](https://discuss.leetcode.com/topic/6468/my-pretty-simple-code-to-solve-it)
 */
int
findMin(int *nums, int len)
{
    int low, high, mid, min;

    low = 0;
    high = len - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high--;
    }

    return nums[low];
}

