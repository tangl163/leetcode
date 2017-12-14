int
myAtoi(char* str)
{
    char *p;
    long tmp, val;
    int sign;

    val = 0;
    sign = 1;

    for (p = str; isspace(*p); p++)
        ;

    if (*p == '-') {
        sign = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }

    while (*p && ISDIGIT(*p)) {
        val = val * 10 + (*p - '0');

        tmp = val * sign;
        if (tmp > INT_MAX || tmp < INT_MIN)
            goto overFlow;

        p++;
    }

    return val * sign;

overFlow:

    val *= sign;

    if (val > INT_MAX)
        return INT_MAX;
    else
        return INT_MIN;
}

