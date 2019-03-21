char *
intToRoman(int num)
{
    char *p;
    int i, n;

    i = 0;
    p = malloc(sizeof *p * 17);

    n = num / 1000;
    if (n > 0) {
        while (n--)
            p[i++] = 'M';
        num %= 1000;
    }

    if (num >= 900) {
        p[i++] = 'C';
        p[i++] = 'M';
        num -= 900;
    } else if (num >= 500) {
        p[i++] = 'D';
        num -= 500;
    } else if (num >= 400) {
        p[i++] = 'C';
        p[i++] = 'D';
        num -= 400;
    }

    n = num / 100;
    if (n > 0) {
        while (n--)
            p[i++] = 'C';
        num %= 100;
    }

    if (num >= 90) {
        p[i++] = 'X';
        p[i++] = 'C';
        num -= 90;
    } else if (num >= 50) {
        p[i++] = 'L';
        num -= 50;
    } else if (num >= 40) {
        p[i++] = 'X';
        p[i++] = 'L';
        num -= 40;
    }

    n = num / 10;
    if (n > 0) {
        while (n--)
            p[i++] = 'X';
        num %= 10;
    }

    if (num == 9) {
        p[i++] = 'I';
        p[i++] = 'X';
        num -= 9;
    } else if (num >= 5) {
        p[i++] = 'V';
        num -= 5;
    } else if (num == 4) {
        p[i++] = 'I';
        p[i++] = 'V';
        num -= 4;
    }

    while (num-- > 0)
        p[i++] = 'I';

    p[i] = 0;

    return p;
}

