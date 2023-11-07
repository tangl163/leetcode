use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut dict = HashMap::new();
        let mut used = HashMap::new();

        let s = s.into_bytes();
        let t = t.into_bytes();

        for i in (0..s.len()) {
            if let Some(v) = dict.get(&s[i]) {
                if *v != t[i] {
                    return false;
                }
            } else {
                if used.get(&t[i]).is_some() {
                    return false;
                }

                dict.insert(s[i], t[i]);
                used.insert(t[i], true);
            }
        }

        return true;
    }
}
