/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j, *p;

    *returnSize = 2;
    p = malloc(sizeof *p * 2);

    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target)
                goto done;
        }
    }

done:

    p[0] = i + 1;
    p[1] = j + 1;

    return p;
}

