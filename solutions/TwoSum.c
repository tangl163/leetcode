/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
twoSum(int *nums, int numsSize, int target)
{
    int i, j, *p;

    p = malloc(sizeof *p * 2);

    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target)
                goto done;
        }
    }

done:

    p[0] = i;
    p[1] = j;

    return p;
}

