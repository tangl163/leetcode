class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26];
        bool visited[26];
        std::vector<char> st;

        for (int i = 0; i < 26; ++i) {
            freq[i] = 0;
            visited[i] = false;
        }

        for (auto c : s) {
            freq[c-'a']++;
        }

        for (auto c : s) {
            freq[c-'a']--;

            if (visited[c-'a']) {
                continue;
            }

            while (!st.empty() && st.back() > c && freq[st.back()-'a'] > 0) {
                visited[st.back()-'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c-'a'] = true;
        }

        return {st.begin(), st.end()};
    }
};

