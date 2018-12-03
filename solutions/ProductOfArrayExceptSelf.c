/**
 * reference from [link](https://leetcode.com/problems/product-of-array-except-self/discuss/65625/Python-solution-(Accepted)-O(n)-time-O(1)-space)
 * Return an array of size *ret.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
productExceptSelf(int *nums, int n, int *retSize)
{
    int i, tmp;
    int *ret;

    tmp = 1;
    *retSize = n;
    ret = malloc(sizeof *ret * n);

    for (i = 0; i < n; i++) {
        ret[i] = tmp;
        tmp *= nums[i];
    }

    tmp = 1;

    for (i = n - 1; i >= 0; i--) {
        ret[i] = ret[i] * tmp;
        tmp *= nums[i];
    }

    return ret;
}

