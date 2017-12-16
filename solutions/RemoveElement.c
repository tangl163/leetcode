int
removeElement(int* nums, int numsSize, int val)
{
    int len, i;

    for (i = 0, len = 0; i < numsSize; i++) {
        if (nums[i] != val)
            nums[len++] = nums[i];
    }

    return len;
}

