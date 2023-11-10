class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, short> m1;
        std::unordered_map<std::string, short> m2;

        std::vector<std::string> tokens = split_whitespace(s);
        if (tokens.size() != pattern.size()) {
            return false;
        }

        for (short i = 0; i < pattern.size(); i++) {
            auto found1 = m1.find(pattern[i]);
            auto found2 = m2.find(tokens[i]);

            if (found1 == m1.end() && found2 == m2.end()) {
                m1[pattern[i]] = i;
                m2[tokens[i]] = i;
            } else if (found1 != m1.end() && found2 != m2.end()) {
                if (found1->second != found2->second) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

private:
    std::vector<std::string> split_whitespace(std::string &s) {
        std::vector<std::string> result;
        std::size_t pos = 0;

        while (pos < s.length()) {
            auto found = s.find(' ', pos);
            if (found == std::string::npos) {
                result.push_back(s.substr(pos));
                break;
            } else {
                result.push_back(s.substr(pos, found - pos));
                pos = found + 1;
            }
        }

        return result;
    }
};
