static int charIsVowel(char c);

static char *vowels = "aeiouAEIOU";

char *
reverseVowels(char *s)
{
    char tmp;
    int i, j, len, leftSign, rightSign;

    leftSign = rightSign = i = 0;
    len = strlen(s);
    j = len - 1;

    while (i < j) {
        if (charIsVowel(s[i]))
            leftSign = 1;

        if (charIsVowel(s[j]))
            rightSign = 1;

        if (leftSign && rightSign) {
            tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
            leftSign = rightSign = 0;
        } else if (leftSign) {
            j--;
        } else if (rightSign) {
            i++;
        } else {
            i++, j--;
        }
    }

    return s;
}

static int
charIsVowel(char c)
{
    int i, len;

    len = strlen(vowels);

    for (i = 0; i < len; i++)
        if (vowels[i] == c)
            return 1;

    return 0;
}

