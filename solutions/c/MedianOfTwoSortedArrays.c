#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

double
findMedianSortedArrays(int *x, int lenx, int *y, int leny)
{
    if (lenx > leny) {
        return findMedianSortedArrays(y, leny, x, lenx);
    }

    int low, high;
    double median;

    low = 0;
    high = lenx;

    while (low <= high) {
        int pivotx = (low + high) / 2;
        int pivoty = (lenx + leny + 1) / 2 - pivotx;

        int leftx = pivotx == 0 ? INT_MIN : x[pivotx-1];
        int rightx = pivotx == lenx ? INT_MAX : x[pivotx];
        int lefty = pivoty == 0 ? INT_MIN : y[pivoty-1];
        int righty = pivoty == leny ? INT_MAX : y[pivoty];

        if (leftx <= righty && lefty <= rightx) {
            if (((lenx+leny) & 1) != 0) {
                median = (double)max(leftx, lefty);
            } else {
                median = (double)(max(leftx, lefty) + min(rightx, righty)) / 2;
            }

            break;
        } else if (leftx > righty) {
            high = pivotx - 1;
        } else {
            low = pivotx + 1;
        }
    }

    return median;
}

