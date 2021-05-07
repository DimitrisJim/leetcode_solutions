from string import ascii_lowercase


class Solution:
    trans_table = {ord(i): ' ' for i in ascii_lowercase}

    def numDifferentIntegers(self, word: str) -> int:
        seen = set()
        # Translation map translates "[a-z] => ' '"
        for i in word.translate(self.trans_table).split():
            # strip any leading zeroes.
            seen.add(i.lstrip('0'))

        # return num of members.
        return len(seen)
