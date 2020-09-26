import (
    "math"
)

func minWindow(s string, t string) string {
    lens, lent := len(s), len(t)
    if lens == 0 || lent == 0 {
        return ""
    }

    dict := make(map[byte]int)
    for i := 0; i < lent; i++ {
        dict[t[i]]++
    }

    n := lent
    start := 0;
    smallest := math.MaxInt32

    for i, j := 0, 0; j < lens; {
        if ele, ok := dict[s[j]]; ok {
            if ele > 0 {
                n--
            }
            dict[s[j]]--
        }
        j++

        for n == 0 {
            if j - i < smallest {
                start, smallest = i, j - i
            }

            if ele, ok := dict[s[i]]; ok {
                if ele == 0 {
                    n++
                }
                dict[s[i]]++
            }
            i++
        }
    }

    if smallest == math.MaxInt32 {
        return ""
    }

    return s[start:start+smallest]
}
