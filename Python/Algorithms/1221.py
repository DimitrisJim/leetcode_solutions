class Solution:
    def balancedStringSplit(self, s: str) -> int:
        # count of balanced pairs, cur_char of balanced
        # pair we're checking, track counts # of cur_chars in sequence
        count, cur_char, track = 0, s[0], 1
        i, end = 1, len(s)
        while i < end:
            next_char = s[i]
            if next_char != cur_char:
                track -= 1
                if track == 0:
                    count += 1
                    i += 1
                    if i < end:
                        cur_char = s[i]
                        track = 1
                    else:
                        break
            else:
                track += 1
            i += 1
        return count
