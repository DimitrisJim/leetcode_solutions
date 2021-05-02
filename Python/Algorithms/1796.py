class Solution:
    def secondHighest(self, s: str) -> int:
        max_, second_max = '', ''
        for i in filter(str.isdigit, s):
            if i > max_:
                if max_ > second_max:
                    second_max = max_
                max_ = i
            elif i > second_max and i != max_:
                second_max = i
        return int(second_max) if second_max else -1
