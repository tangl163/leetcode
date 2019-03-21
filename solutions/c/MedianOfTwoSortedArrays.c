double
findMedianSortedArrays(int *nums1, int len1, int *nums2, int len2)
{
    double ret;
    long len;
    int i, j, k, *p;

    i = j = 0;
    len = len1 + len2;
    p = malloc(sizeof *p * len);

    for (k = 0; k < len; k++) {
        if (i < len1 && j < len2) {
            if (nums1[i] > nums2[j])
                p[k] = nums2[j++];
            else
                p[k] = nums1[i++];
        } else if (i < len1) {
            p[k] = nums1[i++];
        } else {
            p[k] = nums2[j++];
        }
    }

    if (len % 2) {
        ret = p[len / 2];
    } else {
        i = len / 2;
        ret = (p[i-1] + p[i]) / 2.0;
    }

    free(p);

    return ret;
}

