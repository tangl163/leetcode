char *
removeDuplicateLetters(char *s)
{
    int freq[26];
    bool visited[26];
    char stack[26], peek;

    for (int i = 0; i < 26; ++i) {
        freq[i] = 0;
        visited[i] = false;
    }

    for (char *p = s; *p != 0; ++p) {
        freq[*p-'a']++;
    }

    peek = -1;

    for (char *p = s; *p != 0; ++p) {
        freq[*p-'a']--;
        if (visited[*p-'a']) {
            continue;
        }

        while (peek != -1 && *p < stack[peek] && freq[stack[peek]-'a'] > 0) {
            visited[stack[peek]-'a'] = false;
            peek--;
        }

        stack[++peek] = *p;
        visited[*p-'a'] = true;
    }

    for (int i = 0; i <= peek; i++) {
        s[i] = stack[i];
    }

    s[peek+1] = 0;

    return s;
}

