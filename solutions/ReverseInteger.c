int
reverse(int x)
{
    long tmp = 0;

    while (x) {
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }

    if (tmp > INT_MAX || tmp < INT_MIN)
        return 0;

    return tmp;
}

