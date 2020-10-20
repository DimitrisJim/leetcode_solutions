class Solution:
    
    mors = [
        ".-","-...","-.-.","-..",".","..-.","--.","....", "..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    ]
    
    def uniqueMorseRepresentations(self, words):
        # hold what we've seen.
        seen = set()
        mors = self.mors
        ord_ = ord
        # go through words and add to seen.
        for w in words:
            code = "".join(mors[ord_(c) - 97] for c in w)
            if code not in seen:
                seen.add(code)
        # return unique codes.
        return len(seen)
