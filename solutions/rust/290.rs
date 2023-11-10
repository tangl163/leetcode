use std::collections::HashMap;

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let mut tokens = s.split_ascii_whitespace();
        let pattern = pattern.as_bytes();

        let mut m1 = HashMap::new();
        let mut m2 = HashMap::new();

        for (i, v) in pattern.iter().enumerate() {
            let token = tokens.next();
            if token.is_none() {
                return false;
            }

            let v1 = m1.entry(v).or_insert(i);
            let v2 = m2.entry(token.unwrap()).or_insert(i);

            if *v1 != *v2 {
                return false;
            }
        }

        if tokens.next().is_some() {
            return false;
        }

        return true;
    }
}
