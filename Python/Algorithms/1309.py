class Solution:
    def freqAlphabets(self, s):
        i = 0
        len_ = len(s)
        res = []
        # speed things up by localizing lookups
        ord_, chr_, append = ord, chr, res.append
        # edge case where s ends with "[char][char]#", loop
        # until i < len - 2 to not go beyond bounds.
        while i < (len_ - 2):
            # Handle [char][char]# case
            if s[i+2] == '#':
                # caluclate value
                v = s[i+1]
                # we can use the code point to calculate the
                # mapping. The first character simply means
                # we need to look ten characters ahead (48 + 10)
                # for the case of '1'. The second character
                # can then be added to find the final value.
                # 'a' - '1' is the offset we're always adding in.
                if s[i] == '1':
                    append(chr_(ord_(v) + 58))
                # it's a '2', we add 20 to the offset.
                else:
                    append(chr_(ord_(v) + 68))
                i = i + 3
            # Just add the offset here.
            else:
                append(chr_(ord_(s[i]) + 48))
                i = i + 1
        # Handle edge cases (what's left out from only iterating
        # until len_ - 2.
        if len_ - i == 2:
            append(chr_(ord_(s[i]) + 48))
            append(chr_(ord_(s[i+1]) + 48))
        elif len_ - i == 1:
            append(chr_(ord_(s[i]) + 48))
        return "".join(res)
