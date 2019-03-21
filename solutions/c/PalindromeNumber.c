bool
isPalindrome(int x)
{
    int tmp = x;
    int reverseX = 0;

    if (x < 0 || (x % 10 == 0 && x != 0))
        return 0;

    while (tmp) {
        reverseX = reverseX * 10 + tmp % 10;
        tmp /= 10;
    }

    return x == reverseX ? 1 : 0;
}

