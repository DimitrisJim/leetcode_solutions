from string import ascii_lowercase

class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        chars = {}
        for ch in key:
            if ch not in chars:
                if ch == ' ':
                    continue
                chars[ch] = ascii_lowercase[len(chars)]
        chars[' '] = ' '
        return "".join(chars[ch] for ch in message)