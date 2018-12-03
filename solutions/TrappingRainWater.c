int
trap(int *arr, int size)
{
    int left, right;
    int water, leftMax, rightMax;

    left = 0;
    right = size - 1;
    water = 0;
    leftMax = rightMax = 0;

    while (left <= right) {
        if (arr[left] < arr[right]) {
            if (arr[left] > leftMax) {
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }

            left++;
        } else {
            if (arr[right] > rightMax) {
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }

            right--;
        }
    }

    return water;
}

