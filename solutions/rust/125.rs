impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let s = s.as_bytes();
        let mut j = s.len() - 1;
        let mut i: usize = 0;

        while i < j {
            if Solution::is_alnum(s[i]) && Solution::is_alnum(s[j]) {
                if Solution::tolower(s[i]) != Solution::tolower(s[j]) {
                    return false;
                } else {
                    i += 1;
                    j -= 1;
                }
            } else if !Solution::is_alnum(s[i]) {
                i += 1;
            } else if !Solution::is_alnum(s[j]) {
                j -= 1;
            } else {
                i += 1;
                j -= 1;
            }
        }

        return true;
    }

    fn is_alnum(b: u8) -> bool {
        if (b >= b'0' && b <= b'9') || (b >= b'A' && b <= b'Z') || (b >= b'a' && b <= b'z') {
            return true;
        }

        return false;
    }

    fn tolower(b: u8) -> u8 {
        if b >= b'A' && b <= b'Z' {
            return b + b'a' - b'A';
        }

        return b;
    }

    // Rust idiomatic style
    pub fn is_palindrome_v2(s: String) -> bool {
        let s: Vec<_> = s
            .to_ascii_lowercase()
            .chars()
            .filter(|x| x.is_ascii_alphanumeric())
            .collect();

        s.iter().eq(s.iter().rev())
    }
}
