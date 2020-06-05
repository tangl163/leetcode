int
countSegments(char *s)
{
    int i, n;
    bool sign = true;

    for (n = i = 0; i < strlen(s); i++) {
        if (isspace(s[i])) {
            sign = true;
        } else if (sign) {
            n++;
            sign = false;
        }
    }

    return n;
}

