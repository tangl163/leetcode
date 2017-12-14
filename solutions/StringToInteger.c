#define ISDIGIT(c) ((c) - '0' >= 0 && (c) - '9' <= 9)

int
myAtoi(char* str)
{
    char *p;
    long tmp = 0;
    int sign = 1;

    for (p = str; isspace(*p); p++)
        ;

    if (*p == '-') {
        sign = -1;
        p++;
    } else if (*p == '+') {
        p++;
    }

    while (*p && ISDIGIT(*p)) {
        tmp = tmp * 10 + (*p - '0');

        if (tmp > INT_MAX || tmp < INT_MIN)
            goto overFlow;

        p++;
    }

    return tmp * sign;

overFlow:

    tmp *= sign;

    if (tmp > INT_MAX)
        return INT_MAX;
    else
        return INT_MIN;
}

