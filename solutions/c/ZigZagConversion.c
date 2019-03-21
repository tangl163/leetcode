char *
convert(char *s, int numRows)
{
    char *p;
    int i, j, len, ci, step, downStep, upStep;

    i = 0;
    len = strlen(s);
    p = malloc(sizeof *p * (len + 1));

    if (len <= numRows || numRows == 1) {
        strcpy(p, s);
        return p;
    }

    for (j = 0; j < numRows; j++) {

        ci = j;
        upStep = 2 * j;
        downStep = 2 * (numRows - j) - 2;
        step = downStep == 0 ? upStep : downStep;

        do {
            p[i++] = s[ci];
            ci += step;

            if (j > 0 && j < numRows - 1) {
                if (step == downStep)
                    step = upStep;
                else
                    step = downStep;
            }

        } while (ci < len && i < len);
    }

    p[i] = 0;

    return p;
}

