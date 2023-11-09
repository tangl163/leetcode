#include <ctype.h>

bool
isPalindrome(char *s)
{
    char *tail = s;

    while (*tail) {
        ++tail;
    }

    --tail;

    while (s < tail) {
        if (isalnum(*s) && isalnum(*tail)) {
            if (tolower(*s) == tolower(*tail)) {
                ++s, --tail;
            } else {
                return false;
            }
        } else if (!isalnum(*s)) {
            ++s;
        } else if (!isalnum(*tail)) {
            --tail;
        } else {
            ++s, --tail;
        }
    }

    return true;
}
