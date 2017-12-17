int
removeDuplicates(int* nums, int numsSize)
{
    int i, j, tmp;

    tmp = nums[0];

    for (i = 1, j = 1; i < numsSize; i++) {
        if (nums[i] != tmp) {
            tmp = nums[i];
            nums[j++] = tmp;
        }
    }

    return numsSize ? j : numsSize;
}

