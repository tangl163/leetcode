/**
 * Concise O(log N) Binary search solution.
 * Referenced by
 * [StefanPochmann](https://discuss.leetcode.com/topic/34491/clever-idea-making-it-simple)
 */
int
search(int* nums, int numsSize, int target)
{
    long long tmp;
    int low, high, mid;

    low = 0;
    high = numsSize - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if ((nums[0] > nums[mid]) == (nums[0] > target))
            tmp = nums[mid];
        else if (target < nums[0])
            tmp = LONG_MIN;
        else 
            tmp = LONG_MAX;

        if (target > tmp)
            low = mid + 1;
        else if (target < tmp)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

