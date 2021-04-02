class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left, right;

        left = 0;
        right = nums.size() - 1;
        int pivot = partition(nums, left, right);

        while (pivot != k-1) {
            if (pivot < k-1) {
                left = pivot + 1;
                pivot = partition(nums, left, right);
            } else {
                right = pivot - 1;
                pivot = partition(nums, left, right);
            }
        }

        return nums[pivot];
    }

private:
    int partition(vector<int> &arr, int left, int right) {
        int last = left;

        std::swap(arr[left], arr[(left+right)/2]);

        for (int i = left+1; i <= right; ++i) {
            if (arr[i] > arr[left]) {
                std::swap(arr[i], arr[++last]);
            }
        }

        std::swap(arr[left], arr[last]);

        return last;
    }
};
