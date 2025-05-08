int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;

    while (l <= r) {
        int m = l + ((r - l) / 2);

        int leftValid = (m - 1 < 0 || nums[m - 1] != nums[m]);
        int rightValid = (m + 1 == numsSize || nums[m + 1] != nums[m]);

        if (leftValid && rightValid)
            return nums[m];

        int leftSize = (nums[m - 1] == nums[m]) ? m - 1 : m;

        if (leftSize % 2 == 0)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}


