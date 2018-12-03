#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * Reference from [link](https://leetcode.com/problems/container-with-most-water/discuss/6099/Yet-another-way-to-see-what-happens-in-the-O(n)-algorithm)
 */
int
maxArea(int *arr, int size)
{
    int left, right, water;

    water = 0;
    left = 0;
    right = size - 1;

    while (left < right) {
        water = max(water, min(arr[left], arr[right]) * (right - left));

        if (arr[left] > arr[right])
            right--;
        else
            left++;
    }

    return water;
}

