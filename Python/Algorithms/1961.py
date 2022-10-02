class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        partial = ""
        for word in words:
            partial = "".join([partial, word])
            if partial == s:
                return True
        return False