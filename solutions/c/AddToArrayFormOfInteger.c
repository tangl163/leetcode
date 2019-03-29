/**
 * return an array of size *retSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
addToArrayForm(int *A, int ASize, int K, int *retSize)
{
    int *p;
    int kArr[5], kLen;
    int i, j, carry, len, tmp;

    if (K == 0 && ASize == 1 && A[0] == 0) {
        p = malloc(sizeof *p * 1);
        p[0] = 0;
        *retSize = 1;
        return p;
    }

    for (kLen = 0; K > 0; K /= 10)
        kArr[kLen++] = K % 10;

    j = carry = 0;
    len = (kLen > ASize) ? (kLen + 1) : (ASize + 1);
    p = malloc(sizeof *p * len);

    for (i = 0, ASize -= 1; i < kLen || ASize >= 0; i++, ASize--) {
        if (i < kLen && ASize >=0) {
            tmp = kArr[i] + A[ASize] + carry;
        } else if (i < kLen) {
            tmp = kArr[i] + carry;
        } else {
            tmp = A[ASize] + carry;
        }

        if (tmp >= 10) {
            p[j++] = tmp - 10;
            carry = 1;
        } else {
            p[j++] = tmp;
            carry = 0;
        }
    }

    if (carry)
        p[j++] = 1;

    *retSize = j;

    for (i = 0, kLen = j - 1; i < kLen; i++, kLen--) {
        tmp = p[i];
        p[i] = p[kLen];
        p[kLen] = tmp;
    }

    return p;
}

