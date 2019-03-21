int
romanToInt(char *s)
{
    int i, n, len;

    n = 0;
    len = strlen(s);

    for (i = 0; i < len; i++) {
        switch (s[i]) {
        case 'M':
            n += 1000;
            break;

        case 'D':
            n += 500;
            break;

        case 'C':
            if (s[i+1] == 'M') {
                n += 900;
                i++;
            } else if (s[i+1] == 'D') {
                n += 400;
                i++;
            } else {
                n += 100;
            }
            break;

        case 'L':
            n += 50;
            break;

        case 'X':
            if (s[i+1] == 'C') {
                n += 90;
                i++;
            } else if (s[i+1] == 'L') {
                n += 40;
                i++;
            } else {
                n += 10;
            }
            break;

        case 'V':
            n += 5;
            break;
        case 'I':
            if (s[i+1] == 'X') {
                n += 9;
                i++;
            } else if (s[i+1] == 'V') {
                n += 4;
                i++;
            } else {
                n += 1;
            }
            break;
        }
    }

    return n;
}

