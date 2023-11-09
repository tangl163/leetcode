impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        if s.len() > t.len() {
            return false;
        }

        let s = s.as_bytes();
        let t = t.as_bytes();
        let mut idx = 0;

        for b in t {
            if idx < s.len() && s[idx] == *b {
                idx += 1;
            }
        }

        idx == s.len()
    }
}
